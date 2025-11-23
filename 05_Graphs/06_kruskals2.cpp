#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge_sp {
public:
    int src_sp, dest_sp, weight_sp;
};

class Graph_sp {
private:
    int vertices_sp;
    vector<vector<int>> adjMatrix_sp;

public:
    Graph_sp(int v_sp) {
        vertices_sp = v_sp;
        adjMatrix_sp.assign(v_sp, vector<int>(v_sp, 0));
    }

    void inputGraph_sp() {
        int edges_sp;
        cout << "Enter number of edges: ";
        cin >> edges_sp;

        cout << "Enter edges as: src dest weight\n";
        for (int i_sp = 0; i_sp < edges_sp; i_sp++) {
            int s_sp, d_sp, w_sp;
            cin >> s_sp >> d_sp >> w_sp;

            adjMatrix_sp[s_sp][d_sp] = w_sp;
            adjMatrix_sp[d_sp][s_sp] = w_sp; 
        }
    }

    void displayAdjMatrix_sp() {
        cout << "\nAdjacency Matrix:\n";
        for (int i_sp = 0; i_sp < vertices_sp; i_sp++) {
            for (int j_sp = 0; j_sp < vertices_sp; j_sp++) {
                cout << adjMatrix_sp[i_sp][j_sp] << " ";
            }
            cout << endl;
        }
    }

    vector<Edge_sp> getEdges_sp() {
        vector<Edge_sp> edges_sp;

        for (int i_sp = 0; i_sp < vertices_sp; i_sp++) {
            for (int j_sp = i_sp + 1; j_sp < vertices_sp; j_sp++) {
                if (adjMatrix_sp[i_sp][j_sp] != 0) {
                    edges_sp.push_back({i_sp, j_sp, adjMatrix_sp[i_sp][j_sp]});
                }
            }
        }
        return edges_sp;
    }

    int findParent_sp(int v_sp, vector<int>& parent_sp) {
        if (parent_sp[v_sp] == v_sp) return v_sp;
        return parent_sp[v_sp] = findParent_sp(parent_sp[v_sp], parent_sp);
    }

    void unionSet_sp(int a_sp, int b_sp, vector<int>& parent_sp, vector<int>& rank_sp) {
        a_sp = findParent_sp(a_sp, parent_sp);
        b_sp = findParent_sp(b_sp, parent_sp);

        if (a_sp != b_sp) {
            if (rank_sp[a_sp] < rank_sp[b_sp])
                parent_sp[a_sp] = b_sp;
            else if (rank_sp[a_sp] > rank_sp[b_sp])
                parent_sp[b_sp] = a_sp;
            else {
                parent_sp[b_sp] = a_sp;
                rank_sp[a_sp]++;
            }
        }
    }

    void kruskal_sp() {
        vector<Edge_sp> edges_sp = getEdges_sp();

        sort(edges_sp.begin(), edges_sp.end(),
             [](Edge_sp a, Edge_sp b) { return a.weight_sp < b.weight_sp; });

        vector<int> parent_sp(vertices_sp);
        vector<int> rank_sp(vertices_sp, 0);

        for (int i_sp = 0; i_sp < vertices_sp; i_sp++)
            parent_sp[i_sp] = i_sp;

        vector<Edge_sp> mst_sp;
        int totalCost_sp = 0;

        for (auto& e_sp : edges_sp) {
            int p1_sp = findParent_sp(e_sp.src_sp, parent_sp);
            int p2_sp = findParent_sp(e_sp.dest_sp, parent_sp);

            if (p1_sp != p2_sp) {
                mst_sp.push_back(e_sp);
                totalCost_sp += e_sp.weight_sp;
                unionSet_sp(p1_sp, p2_sp, parent_sp, rank_sp);
            }
        }

        cout << "\nMinimum Spanning Tree (Kruskal):\n";
        for (auto& x_sp : mst_sp) {
            cout << x_sp.src_sp << " - " << x_sp.dest_sp
                 << "  (weight = " << x_sp.weight_sp << ")\n";
        }

        cout << "Total Minimum Cost: " << totalCost_sp << "\n";
    }
};

int main() {
    int v_sp;
    cout << "Enter number of vertices: ";
    cin >> v_sp;

    Graph_sp g_sp(v_sp);

    g_sp.inputGraph_sp();
    g_sp.displayAdjMatrix_sp();   
    g_sp.kruskal_sp();

    return 0;
}
