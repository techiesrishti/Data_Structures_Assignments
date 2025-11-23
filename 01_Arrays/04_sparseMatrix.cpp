#include <iostream>
#include <vector>
using namespace std;

struct Matrix_sp {
    int row_sp;
    int col_sp;
    int val_sp;
};

int main() {
    int m_sp, n_sp;
    cout << "Enter rows and cols of matrix: ";
    cin >> m_sp >> n_sp;

    vector<vector<int>> A_sp(m_sp, vector<int>(n_sp));

    cout << "Enter elements of matrix:\n";
    for (int i_sp = 0; i_sp < m_sp; i_sp++) {
        for (int j_sp = 0; j_sp < n_sp; j_sp++) {
            cin >> A_sp[i_sp][j_sp];
        }
    }

    // store sparse matrix 
    vector<Matrix_sp> sparse_sp;
    for (int i_sp = 0; i_sp < m_sp; i_sp++) {
        for (int j_sp = 0; j_sp < n_sp; j_sp++) {
            if (A_sp[i_sp][j_sp] != 0) {
                sparse_sp.push_back({i_sp, j_sp, A_sp[i_sp][j_sp]});
            }
        }
    }

    //original matrix
    cout << "\nOriginal Matrix:\n";
    for (int i_sp = 0; i_sp < m_sp; i_sp++) {
        for (int j_sp = 0; j_sp < n_sp; j_sp++) {
            cout << A_sp[i_sp][j_sp] << " ";
        }
        cout << endl;
    }

    // sparse triplet form row col val
    cout << "\nSparse Matrix (Triplet form):\n";
    for (auto &t_sp : sparse_sp) {
        cout << t_sp.row_sp << " " << t_sp.col_sp << " " << t_sp.val_sp << endl;
    }

    // simple transpose 
    cout << "\nTranspose of Sparse Matrix:\n";
    for (auto &t_sp : sparse_sp) {
        cout << t_sp.col_sp << " " << t_sp.row_sp << " " << t_sp.val_sp << endl;
    }

    return 0;
}
