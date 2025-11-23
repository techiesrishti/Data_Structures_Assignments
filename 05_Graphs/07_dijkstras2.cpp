#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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

        cout << "\nAdjacency Matrix:\n";
        for (int i_sp = 0; i_sp < vertices_sp; i_sp++) {
            for (int j_sp = 0; j_sp < vertices_sp; j_sp++) {
                cout << adjMatrix_sp[i_sp][j_sp] << " ";
            }
            cout << endl;
        }
    }

    int minDistance_sp(vector<int>& dist_sp, vector<bool>& visited_sp) {
        int min_sp = INT_MAX, index_sp = -1;

        for (int i_sp = 0; i_sp < vertices_sp; i_sp++) {
            if (!visited_sp[i_sp] && dist_sp[i_sp] <= min_sp) {
                min_sp = dist_sp[i_sp];
                index_sp = i_sp;
            }
        }
        return index_sp;
    }

    void dijkstra_sp(int src_sp, int dest_sp) {
        vector<int> dist_sp(vertices_sp, INT_MAX);
        vector<bool> visited_sp(vertices_sp, false);

        dist_sp[src_sp] = 0;

        for (int count_sp = 0; count_sp < vertices_sp - 1; count_sp++) {
            int u_sp = minDistance_sp(dist_sp, visited_sp);

            if (u_sp == -1) break;

            visited_sp[u_sp] = true;

            for (int v_sp = 0; v_sp < vertices_sp; v_sp++) {
                if (adjMatrix_sp[u_sp][v_sp] != 0 && !visited_sp[v_sp] &&
                    dist_sp[u_sp] + adjMatrix_sp[u_sp][v_sp] < dist_sp[v_sp]) {
                    
                    dist_sp[v_sp] = dist_sp[u_sp] + adjMatrix_sp[u_sp][v_sp];
                }
            }
        }

        cout << "\nShortest distance from " << src_sp << " to " << dest_sp 
             << " is: " << dist_sp[dest_sp] << endl;
    }
};

int main() {
    int v_sp;
    cout << "Enter number of vertices: ";
    cin >> v_sp;

    Graph_sp g_sp(v_sp);
    g_sp.inputGraph_sp();

    int src_sp, dest_sp;
    cout << "Enter source vertex: ";
    cin >> src_sp;
    cout << "Enter destination vertex: ";
    cin >> dest_sp;

    g_sp.dijkstra_sp(src_sp, dest_sp);

    return 0;
}
