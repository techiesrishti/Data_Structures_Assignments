#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pii_sp;

class Graph_sp {
private:
    int vertices_sp;
    vector<vector<pii_sp>> adjList_sp;  

public:
    Graph_sp(int v_sp) {
        vertices_sp = v_sp;
        adjList_sp.resize(v_sp);
    }

    void addEdge_sp(int u_sp, int v_sp, int w_sp) {
        adjList_sp[u_sp].push_back({v_sp, w_sp});
        adjList_sp[v_sp].push_back({u_sp, w_sp});  // undirected graph
    }

    void inputGraph_sp() {
        int edges_sp;
        cout << "Enter number of edges: ";
        cin >> edges_sp;

        cout << "Enter edges as: src dest weight\n";
        for (int i_sp = 0; i_sp < edges_sp; i_sp++) {
            int u_sp, v_sp, w_sp;
            cin >> u_sp >> v_sp >> w_sp;

            if (u_sp >= 0 && u_sp < vertices_sp && v_sp >= 0 && v_sp < vertices_sp) {
                addEdge_sp(u_sp, v_sp, w_sp);
            } else {
                cout << "Invalid vertices. Try this edge again.\n";
                i_sp--;
            }
        }
    }

    void displayAdjList_sp() {
        cout << "\nAdjacency List Representation:\n";
        for (int i_sp = 0; i_sp < vertices_sp; i_sp++) {
            cout << i_sp << " -> ";
            for (auto &p_sp : adjList_sp[i_sp]) {
                cout << "(" << p_sp.first << ", " << p_sp.second << ") ";
            }
            cout << "\n";
        }
    }

    void primsMST_sp(int start_sp) {
        vector<int> key_sp(vertices_sp, INT_MAX);
        vector<int> parent_sp(vertices_sp, -1);
        vector<bool> inMST_sp(vertices_sp, false);

        priority_queue<pii_sp, vector<pii_sp>, greater<pii_sp>> pq_sp;
        key_sp[start_sp] = 0;
        pq_sp.push({0, start_sp});

        while (!pq_sp.empty()) {
            int u_sp = pq_sp.top().second;
            pq_sp.pop();

            if (inMST_sp[u_sp]) continue;
            inMST_sp[u_sp] = true;

            for (auto &edge_sp : adjList_sp[u_sp]) {
                int v_sp = edge_sp.first;
                int w_sp = edge_sp.second;
                if (!inMST_sp[v_sp] && w_sp < key_sp[v_sp]) {
                    key_sp[v_sp] = w_sp;
                    parent_sp[v_sp] = u_sp;
                    pq_sp.push({key_sp[v_sp], v_sp});
                }
            }
        }

        cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
        int totalWeight_sp = 0;
        for (int i_sp = 0; i_sp < vertices_sp; i_sp++) {
            if (parent_sp[i_sp] != -1) {
                cout << parent_sp[i_sp] << " -- " << i_sp
                     << "  | weight_sp = " << key_sp[i_sp] << "\n";
                totalWeight_sp += key_sp[i_sp];
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

    // display adjacency list as requested in the question
    g_sp.displayAdjList_sp();

    int start_sp;
    cout << "\nEnter starting vertex for Prim's: ";
    cin >> start_sp;
    if (start_sp < 0 || start_sp >= v_sp) {
        cout << "Invalid start vertex. Exiting.\n";
        return 0;
    }

    g_sp.primsMST_sp(start_sp);
    return 0;
}
