#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Graph_sp {
private:
    int numVertices_sp;
    vector<vector<int>> adjMatrix_sp;

public:
    Graph_sp(int vertices_sp) : numVertices_sp(vertices_sp), adjMatrix_sp(vertices_sp, vector<int>(vertices_sp, 0)) {}

    void inputGraph_sp() {
        cout << "Enter the number of edges: ";
        int edges_sp;
        cin >> edges_sp;

        cout << "Enter the edges (source destination):" << endl;
        for (int i_sp = 0; i_sp < edges_sp; ++i_sp) {
            int src_sp, dest_sp;
            cin >> src_sp >> dest_sp;
            if (src_sp >= 0 && src_sp < numVertices_sp && dest_sp >= 0 && dest_sp < numVertices_sp) {
                adjMatrix_sp[src_sp][dest_sp] = 1;
                adjMatrix_sp[dest_sp][src_sp] = 1; // For undirected graph
            } else {
                cout << "Invalid vertex index. Skipping edge." << endl;
                --i_sp;
            }
        }
    }

    void printAdjacencyMatrix_sp() {
        cout << "\nAdjacency Matrix:" << endl;
        for (int i_sp = 0; i_sp < numVertices_sp; ++i_sp) {
            for (int j = 0; j < numVertices_sp; ++j) {
                cout << adjMatrix_sp[i_sp][j] << " ";
            }
            cout << endl;
        }
    }

    void bfsTraversal_sp(int startVertex_sp) {
        vector<bool> visited_sp(numVertices_sp, false);
        queue<int> q;

        q.push(startVertex_sp);
        visited_sp[startVertex_sp] = true;

        cout << "\nBFS Traversal starting from vertex " << startVertex_sp << ": ";
        while (!q.empty()) {
            int current_sp = q.front();
            q.pop();
            cout << current_sp << " ";

            for (int i_sp = 0; i_sp < numVertices_sp; ++i_sp) {
                if (adjMatrix_sp[current_sp][i_sp] == 1 && !visited_sp[i_sp]) {
                    visited_sp[i_sp] = true;
                    q.push(i_sp);
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

            for (int i_sp = numVertices_sp - 1; i_sp >= 0; --i_sp) {
                if (adjMatrix_sp[current_sp][i_sp] == 1 && !visited_sp[i_sp]) {
                    visited_sp[i_sp] = true;
                    s_sp.push(i_sp);
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
    graph.printAdjacencyMatrix_sp();

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