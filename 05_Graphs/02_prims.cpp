#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge_sp {
    int to_sp;
    int wt_sp;
};

class Graph_sp {
    int n_sp;
    vector<vector<Edge_sp>> adj_sp;

public:
    Graph_sp(int n_sp) {
        this->n_sp = n_sp;
        adj_sp.resize(n_sp);
    }

    void addEdge_sp(int u_sp, int v_sp, int w_sp) {
        adj_sp[u_sp].push_back({v_sp, w_sp});
        adj_sp[v_sp].push_back({u_sp, w_sp}); 
    }

    void showAdjList_sp() {
        cout << "\nAdjacency List Representation:\n";
        for (int i_sp = 0; i_sp < n_sp; i_sp++) {
            cout << i_sp << " -> ";
            for (auto &x_sp : adj_sp[i_sp]) {
                cout << "(" << x_sp.to_sp << ", " << x_sp.wt_sp << ") ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void prim_sp(int start_sp) {
        vector<int> visited_sp(n_sp, 0);
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq_sp;

        pq_sp.push({0, start_sp});

        int totalCost_sp = 0;

        cout << "\nEdges selected for Minimum Spanning Tree:\n";

        while (!pq_sp.empty()) {
            auto curr_sp = pq_sp.top();
            pq_sp.pop();

            int wt_sp = curr_sp.first;
            int node_sp = curr_sp.second;

            if (visited_sp[node_sp] == 1) continue;

            visited_sp[node_sp] = 1;

            if (wt_sp != 0) {
                cout << "Edge with weight: " << wt_sp << endl;
            }

            totalCost_sp += wt_sp;

            for (auto &next_sp : adj_sp[node_sp]) {
                if (!visited_sp[next_sp.to_sp]) {
                    pq_sp.push({next_sp.wt_sp, next_sp.to_sp});
                }
            }
        }

        cout << "\nTotal Minimum Cost: " << totalCost_sp << endl;
    }
};

int main() {
    int n_sp, e_sp;
    cout << "Enter number of vertices: ";
    cin >> n_sp;

    Graph_sp g_sp(n_sp);

    cout << "Enter number of edges: ";
    cin >> e_sp;

    cout << "Enter edges as: u v weight\n";
    for (int i_sp = 0; i_sp < e_sp; i_sp++) {
        int u_sp, v_sp, w_sp;
        cin >> u_sp >> v_sp >> w_sp;
        g_sp.addEdge_sp(u_sp, v_sp, w_sp);
    }

    cout << "\n--- Graph Representation (Adjacency List) ---\n";
    g_sp.showAdjList_sp();

    int start_sp;
    cout << "Enter starting vertex for Prim's Algorithm: ";
    cin >> start_sp;

    g_sp.prim_sp(start_sp);

    return 0;
}
