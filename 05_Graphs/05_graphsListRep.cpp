#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Graph_sp {
private:
    int numVertices_sp;
    vector<vector<int>> adjList_sp;   // changed from matrix to list

public:
    Graph_sp(int vertices_sp) : numVertices_sp(vertices_sp) {
        adjList_sp.resize(vertices_sp);
    }

    void inputGraph_sp() {
        cout << "Enter the number of edges: ";
        int edges_sp;
        cin >> edges_sp;

        cout << "Enter the edges (source destination):" << endl;
        for (int i_sp = 0; i_sp < edges_sp; ++i_sp) {
            int src_sp, dest_sp;
            cin >> src_sp >> dest_sp;

            if (src_sp >= 0 && src_sp < numVertices_sp &&
                dest_sp >= 0 && dest_sp < numVertices_sp) {

                adjList_sp[src_sp].push_back(dest_sp);
                adjList_sp[dest_sp].push_back(src_sp); // undirected graph

            } else {
                cout << "Invalid vertex index. Skipping edge." << endl;
                --i_sp;
            }
        }
    }

    void printAdjacencyList_sp() {
        cout << "\nAdjacency List:" << endl;
        for (int i_sp = 0; i_sp < numVertices_sp; ++i_sp) {
            cout << i_sp << " -> ";
            for (int node_sp : adjList_sp[i_sp]) {
                cout << node_sp << " ";
            }
            cout << endl;
        }
    }

    void bfsTraversal_sp(int startVertex_sp) {
        vector<bool> visited_sp(numVertices_sp, false);
        queue<int> q_sp;

        q_sp.push(startVertex_sp);
        visited_sp[startVertex_sp] = true;

        cout << "\nBFS Traversal starting from vertex " << startVertex_sp << ": ";
        while (!q_sp.empty()) {
            int current_sp = q_sp.front();
            q_sp.pop();
            cout << current_sp << " ";

            for (int neighbor_sp : adjList_sp[current_sp]) {
                if (!visited_sp[neighbor_sp]) {
                    visited_sp[neighbor_sp] = true;
                    q_sp.push(neighbor_sp);
                }
            }
        }
        cout << endl;
    }

    void dfsTraversal_sp(int startVertex_sp) {
        vector<bool> visited_sp(numVertices_sp, false);
        stack<int> s_sp;

        s_sp.push(startVertex_sp);
        visited_sp[startVertex_sp] = true;

        cout << "\nDFS Traversal starting from vertex " << startVertex_sp << ": ";
        while (!s_sp.empty()) {
            int current_sp = s_sp.top();
            s_sp.pop();
            cout << current_sp << " ";

            // push neighbors in reverse like your original code
            for (int i_sp = adjList_sp[current_sp].size() - 1; i_sp >= 0; --i_sp) {
                int neighbor_sp = adjList_sp[current_sp][i_sp];
                if (!visited_sp[neighbor_sp]) {
                    visited_sp[neighbor_sp] = true;
                    s_sp.push(neighbor_sp);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int vertices_sp;
    cout << "Enter the number of vertices: ";
    cin >> vertices_sp;

    Graph_sp graph(vertices_sp);

    graph.inputGraph_sp();
    graph.printAdjacencyList_sp();

    int startVertex_sp;
    cout << "Enter the starting vertex for traversal: ";
    cin >> startVertex_sp;

    if (startVertex_sp >= 0 && startVertex_sp < vertices_sp) {
        graph.bfsTraversal_sp(startVertex_sp);
        graph.dfsTraversal_sp(startVertex_sp);
    } else {
        cout << "Invalid starting vertex." << endl;
    }

    return 0;
}
