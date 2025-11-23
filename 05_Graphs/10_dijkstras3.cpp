#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Graph_sp {
private:
    int vertices_sp;
    vector<vector<pair<int, int>>> adjList_sp;  
    // pair -> (neighbor, weight)

public:
    Graph_sp(int v_sp) {
        vertices_sp = v_sp;
        adjList_sp.resize(v_sp);
    }

    void inputGraph_sp() {
        int edges_sp;
        cout << "Enter number of edges: ";
        cin >> edges_sp;

        cout << "Enter edges as: src dest weight\n";
        for (int i_sp = 0; i_sp < edges_sp; i_sp++) {
            int s_sp, d_sp, w_sp;
            cin >> s_sp >> d_sp >> w_sp;

            adjList_sp[s_sp].push_back({d_sp, w_sp});
            adjList_sp[d_sp].push_back({s_sp, w_sp}); 
        }
    }

    void displayAdjList_sp() {
        cout << "\nAdjacency List:\n";
        for (int i_sp = 0; i_sp < vertices_sp; i_sp++) {
            cout << i_sp << " -> ";
            for (auto &x_sp : adjList_sp[i_sp]) {
                cout << "(" << x_sp.first << ", w=" << x_sp.second << ") ";
            }
            cout << endl;
        }
    }

    void dijkstra_sp(int start_sp, int end_sp) {
        vector<int> dist_sp(vertices_sp, numeric_limits<int>::max());
        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>>> pq_sp;

        dist_sp[start_sp] = 0;
        pq_sp.push({0, start_sp});

        while (!pq_sp.empty()) {
            int currentDist_sp = pq_sp.top().first;
            int currentNode_sp = pq_sp.top().second;
            pq_sp.pop();

            if (currentDist_sp > dist_sp[currentNode_sp])
                continue;

            for (auto &neighbor_sp : adjList_sp[currentNode_sp]) {
                int nxt_sp = neighbor_sp.first;
                int wt_sp = neighbor_sp.second;

                if (dist_sp[currentNode_sp] + wt_sp < dist_sp[nxt_sp]) {
                    dist_sp[nxt_sp] = dist_sp[currentNode_sp] + wt_sp;
                    pq_sp.push({dist_sp[nxt_sp], nxt_sp});
                }
            }
        }

        cout << "\nShortest distance from " << start_sp
             << " to " << end_sp << " is: " << dist_sp[end_sp] << endl;
    }
};

int main() {
    int v_sp;
    cout << "Enter number of vertices: ";
    cin >> v_sp;

    Graph_sp g_sp(v_sp);
    g_sp.inputGraph_sp();
    g_sp.displayAdjList_sp();

    int start_sp, end_sp;
    cout << "\nEnter source vertex: ";
    cin >> start_sp;
    cout << "Enter destination vertex: ";
    cin >> end_sp;

    g_sp.dijkstra_sp(start_sp, end_sp);

    return 0;
}
