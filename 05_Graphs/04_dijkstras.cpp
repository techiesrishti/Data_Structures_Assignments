#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
    int to, weight;
};

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<Edge>> adj(vertices);

    cout << "Enter edges in format: u v w \n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   
    }

    cout << "\nAdjacency List Representation:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (auto &e : adj[i]) {
            cout << "(" << e.to << ", w=" << e.weight << ") ";
        }
        cout << endl;
    }
   
    int source, destination;
    cout << "\nEnter source node: ";
    cin >> source;

    cout << "Enter destination node: ";
    cin >> destination;

    vector<int> dist(vertices, numeric_limits<int>::max());
    dist[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto &edge : adj[node]) {
            int next = edge.to;
            int weight = edge.weight;

            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    if (dist[destination] == numeric_limits<int>::max())
        cout << "\nNo path exists between the nodes.\n";
    else
        cout << "\nShortest distance from " << source << " to "
             << destination << " = " << dist[destination] << endl;

    return 0;
}
