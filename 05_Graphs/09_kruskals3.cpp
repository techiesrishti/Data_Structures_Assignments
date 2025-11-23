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
    vector<vector<pair<int,int>>> adjList_sp;   
    vector<Edge_sp> edgeList_sp;                

public:
    Graph_sp(int v_sp) {
        vertices_sp = v_sp;
        adjList_sp.resize(v_sp);
    }

    void addEdge_sp(int u_sp, int v_sp, int w_sp) {
        adjList_sp[u_sp].push_back({v_sp, w_sp});
        adjList_sp[v_sp].push_back({u_sp, w_sp});  

        edgeList_sp.push_back({u_sp, v_sp, w_sp});
    }

    void inputGraph_sp() {
        int edges_sp;
        cout << "Enter number of edges: ";
        cin >> edges_sp;

        cout << "Enter edges as: src dest weight\n";
        for (int i_sp = 0; i_sp < edges_sp; i_sp++) {
            int u_sp, v_sp, w_sp;
            cin >> u_sp >> v_sp >> w_sp;
            addEdge_sp(u_sp, v_sp, w_sp);
        }
    }

    void displayAdjList_sp() {
        cout << "\nAdjacency List Representation:\n";
        for (int i_sp = 0; i_sp < vertices_sp; i_sp++) {
            cout << i_sp << " -> ";
            for (auto p_sp : adjList_sp[i_sp]) {
                cout << "(" << p_sp.first << ", " << p_sp.second << ") ";
            }
            cout << "\n";
        }
    }

    int findParent_sp(vector<int>& parent_sp, int i_sp) {
        if (parent_sp[i_sp] == i_sp)
            return i_sp;
        return parent_sp[i_sp] = findParent_sp(parent_sp, parent_sp[i_sp]);
    }

    void unionSet_sp(int x_sp, int y_sp, vector<int>& parent_sp, vector<int>& rank_sp) {
        int px_sp = findParent_sp(parent_sp, x_sp);
        int py_sp = findParent_sp(parent_sp, y_sp);

        if (rank_sp[px_sp] < rank_sp[py_sp])
            parent_sp[px_sp] = py_sp;
        else if (rank_sp[px_sp] > rank_sp[py_sp])
            parent_sp[py_sp] = px_sp;
        else {
            parent_sp[py_sp] = px_sp;
            rank_sp[px_sp]++;
        }
    }

    void kruskalMST_sp() {
        vector<Edge_sp> mst_sp;
        int totalWeight_sp = 0;

        sort(edgeList_sp.begin(), edgeList_sp.end(),
            [](Edge_sp a_sp, Edge_sp b_sp) {
                return a_sp.weight_sp < b_sp.weight_sp;
            });

        vector<int> parent_sp(vertices_sp);
        vector<int> rank_sp(vertices_sp, 0);

        for (int i_sp = 0; i_sp < vertices_sp; i_sp++)
            parent_sp[i_sp] = i_sp;

        cout << "\nKruskal's MST Edges:\n";
        for (auto &e_sp : edgeList_sp) {
            int p1_sp = findParent_sp(parent_sp, e_sp.src_sp);
            int p2_sp = findParent_sp(parent_sp, e_sp.dest_sp);

            if (p1_sp != p2_sp) {
                mst_sp.push_back(e_sp);
                unionSet_sp(p1_sp, p2_sp, parent_sp, rank_sp);
                totalWeight_sp += e_sp.weight_sp;

                cout << e_sp.src_sp << " -- " << e_sp.dest_sp
                     << "  | weight = " << e_sp.weight_sp << "\n";
            }
        }

        cout << "Total Weight of MST = " << totalWeight_sp << "\n";
    }
};

int main() {
    int v_sp;
    cout << "Enter number of vertices: ";
    cin >> v_sp;

    Graph_sp g_sp(v_sp);
    g_sp.inputGraph_sp();

    g_sp.displayAdjList_sp();

    g_sp.kruskalMST_sp();

    return 0;
}
