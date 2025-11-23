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

    //  sparse matrix
    vector<Matrix_sp> sparse_sp;
    for (int i_sp = 0; i_sp < m_sp; i_sp++) {
        for (int j_sp = 0; j_sp < n_sp; j_sp++) {
            if (A_sp[i_sp][j_sp] != 0) {
                sparse_sp.push_back({i_sp, j_sp, A_sp[i_sp][j_sp]});
            }
        }
    }

    //  original matrix
    cout << "\nOriginal Matrix:\n";
    for (int i_sp = 0; i_sp < m_sp; i_sp++) {
        for (int j_sp = 0; j_sp < n_sp; j_sp++) {
            cout << A_sp[i_sp][j_sp] << " ";
        }
        cout << endl;
    }

    //  sparse triplet form row  col val
    cout << "\nSparse Matrix Triplet form:\n";
    for (auto &t_sp : sparse_sp) {
        cout << t_sp.row_sp << " " << t_sp.col_sp << " " << t_sp.val_sp << endl;
    }

    // fast Transpose
    cout << "\nFast Transpose of Sparse Matrix:\n";

    vector<int> colCount(n_sp, 0), index(n_sp, 0);
    
    for (auto &t_sp : sparse_sp) {
        colCount[t_sp.col_sp]++;
    }
    index[0] = 0;
    for (int i = 1; i < n_sp; i++) {
        index[i] = index[i - 1] + colCount[i - 1];
    }
    vector<Matrix_sp> trans_sp(sparse_sp.size());
    for (auto &t_sp : sparse_sp) {
        int pos = index[t_sp.col_sp]++;
        trans_sp[pos] = {t_sp.col_sp, t_sp.row_sp, t_sp.val_sp};
    }

    for (auto &t_sp : trans_sp) {
        cout << t_sp.row_sp << " " << t_sp.col_sp << " " << t_sp.val_sp << endl;
    }

    return 0;
}
