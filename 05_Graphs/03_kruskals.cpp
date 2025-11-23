#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge_sp {
public:
    int src_sp, dest_sp, wt_sp;
    Edge_sp(int s_sp, int d_sp, int w_sp) {
        src_sp = s_sp;
        dest_sp = d_sp;
        wt_sp = w_sp;
    }
};

class Graph_sp {
public:
    int V_sp;
    vector<vector<pair<int,int>>> adjList_sp; 
    vector<Edge_sp> edges_sp;

    Graph_sp(int v_sp) {
        V_sp = v_sp;
        adjList_sp.resize(V_sp);
    }

    void addEdge_sp(int u_sp, int v_sp, int w_sp) {
        adjList_sp[u_sp].push_back({v_sp, w_sp});
        adjList_sp[v_sp].push_back({u_sp, w_sp});
        edges_sp.push_back(Edge_sp(u_sp, v_sp, w_sp));
    }

    void displayAdjList_sp() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V_sp; i++) {
            cout << i << " -> ";
            for (auto &p_sp : adjList_sp[i]) {
                cout << "(" << p_sp.first << ", " << p_sp.second << ") ";
            }
            cout << "\n";
        }
    }
};

class DSU_sp {
public:
    vector<int> parent_sp, rank_sp;

    DSU_sp(int n_sp) {
        parent_sp.resize(n_sp);
        rank_sp.resize(n_sp, 0);

        for (int i = 0; i < n_sp; i++)
            parent_sp[i] = i;
    }

    int find_sp(int x_sp) {
        if (parent_sp[x_sp] != x_sp)
            parent_sp[x_sp] = find_sp(parent_sp[x_sp]);
        return parent_sp[x_sp];
    }

    void union_sp(int x_sp, int y_sp) {
        int rx_sp = find_sp(x_sp);
        int ry_sp = find_sp(y_sp);

        if (rx_sp != ry_sp) {
            if (rank_sp[rx_sp] < rank_sp[ry_sp])
                parent_sp[rx_sp] = ry_sp;
            else if (rank_sp[ry_sp] < rank_sp[rx_sp])
                parent_sp[ry_sp] = rx_sp;
            else {
                parent_sp[ry_sp] = rx_sp;
                rank_sp[rx_sp]++;
            }
        }
    }
};

int main() {
    int v_sp, e_sp;
    cout << "Enter number of vertices: ";
    cin >> v_sp;

    cout << "Enter number of edges: ";
    cin >> e_sp;

    Graph_sp g_sp(v_sp);

    cout << "Enter edges in format: u v weight\n";
    for (int i = 0; i < e_sp; i++) {
        int u_sp, v_sp, w_sp;
        cin >> u_sp >> v_sp >> w_sp;
        g_sp.addEdge_sp(u_sp, v_sp, w_sp);
    }

    g_sp.displayAdjList_sp();

    // Sorting edges by weight
    sort(g_sp.edges_sp.begin(), g_sp.edges_sp.end(),
        [](Edge_sp &a_sp, Edge_sp &b_sp) {
            return a_sp.wt_sp < b_sp.wt_sp;
        });

    DSU_sp ds_sp(v_sp);

    cout << "\nKruskal's MST Edges:\n";
    int totalCost_sp = 0;

    for (auto &edge_sp : g_sp.edges_sp) {
        int s_sp = edge_sp.src_sp;
        int d_sp = edge_sp.dest_sp;

        if (ds_sp.find_sp(s_sp) != ds_sp.find_sp(d_sp)) {
            cout << s_sp << " -- " << d_sp << "  (wt = " << edge_sp.wt_sp << ")\n";
            totalCost_sp += edge_sp.wt_sp;
            ds_sp.union_sp(s_sp, d_sp);
        }
    }

    cout << "\nTotal MST Cost = " << totalCost_sp << "\n";

    return 0;
}
