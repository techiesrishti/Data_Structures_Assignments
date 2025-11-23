#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void displaySquare_sp(vector<vector<int>>& m_sp, int n_sp) {
    for (int i_sp = 0; i_sp < n_sp; i_sp++) {
        for (int j_sp = 0; j_sp < n_sp; j_sp++)
            cout << setw(4) << m_sp[i_sp][j_sp];
        cout << endl;
    }
}

vector<vector<int>> generateOdd_sp(int n_sp) {
    vector<vector<int>> m_sp(n_sp, vector<int>(n_sp, 0));

    int num_sp = 1;
    int i_sp = 0, j_sp = n_sp / 2;

    while (num_sp <= n_sp * n_sp) {
        m_sp[i_sp][j_sp] = num_sp++;

        int newI_sp = (i_sp - 1 + n_sp) % n_sp;
        int newJ_sp = (j_sp + 1) % n_sp;

        if (m_sp[newI_sp][newJ_sp] != 0)
            i_sp = (i_sp + 1) % n_sp;
        else {
            i_sp = newI_sp;
            j_sp = newJ_sp;
        }
    }
    return m_sp;
}

vector<vector<int>> generateDoublyEven_sp(int n_sp) {
    vector<vector<int>> m_sp(n_sp, vector<int>(n_sp));
    int num_sp = 1;
    int total_sp = n_sp * n_sp;

    for (int i_sp = 0; i_sp < n_sp; i_sp++)
        for (int j_sp = 0; j_sp < n_sp; j_sp++)
            m_sp[i_sp][j_sp] = num_sp++;

    for (int i_sp = 0; i_sp < n_sp; i_sp++)
        for (int j_sp = 0; j_sp < n_sp; j_sp++)
            if ((i_sp % 4 < 2 && j_sp % 4 < 2) || (i_sp % 4 >= 2 && j_sp % 4 >= 2))
                m_sp[i_sp][j_sp] = total_sp + 1 - m_sp[i_sp][j_sp];

    return m_sp;
}

vector<vector<int>> generateSinglyEven_sp(int n_sp) {
    int half_sp = n_sp / 2;
    int subSize_sp = half_sp * half_sp;

    vector<vector<int>> A_sp = generateOdd_sp(half_sp);
    vector<vector<int>> m_sp(n_sp, vector<int>(n_sp));

    for (int i_sp = 0; i_sp < half_sp; i_sp++)
        for (int j_sp = 0; j_sp < half_sp; j_sp++) {
            m_sp[i_sp][j_sp] = A_sp[i_sp][j_sp];
            m_sp[i_sp + half_sp][j_sp] = A_sp[i_sp][j_sp] + 2 * subSize_sp;
            m_sp[i_sp][j_sp + half_sp] = A_sp[i_sp][j_sp] + 3 * subSize_sp;
            m_sp[i_sp + half_sp][j_sp + half_sp] = A_sp[i_sp][j_sp] + subSize_sp;
        }

    int k_sp = (n_sp - 2) / 4;

    for (int i_sp = 0; i_sp < n_sp; i_sp++)
        for (int j_sp = 0; j_sp < n_sp; j_sp++) {
            if (i_sp < half_sp) {
                if (j_sp < k_sp || j_sp >= n_sp - k_sp)
                    swap(m_sp[i_sp][j_sp], m_sp[i_sp + half_sp][j_sp]);
            }
            else if (i_sp == half_sp) {
                swap(m_sp[i_sp][k_sp], m_sp[i_sp - half_sp][k_sp]);
            }
        }

    return m_sp;
}

void verifyMagic_sp(vector<vector<int>>& m_sp, int n_sp) {
    int magic_sp = n_sp * (n_sp * n_sp + 1) / 2;
    cout << "\nMagic Constant = " << magic_sp << endl;

    bool ok_sp = true;

    // row check
    for (int i_sp = 0; i_sp < n_sp; i_sp++) {
        int sum_sp = 0;
        for (int j_sp = 0; j_sp < n_sp; j_sp++)
            sum_sp += m_sp[i_sp][j_sp];
        if (sum_sp != magic_sp) ok_sp = false;
    }

    // column check
    for (int j_sp = 0; j_sp < n_sp; j_sp++) {
        int sum_sp = 0;
        for (int i_sp = 0; i_sp < n_sp; i_sp++)
            sum_sp += m_sp[i_sp][j_sp];
        if (sum_sp != magic_sp) ok_sp = false;
    }

    // diagonal 1
    int d1_sp = 0, d2_sp = 0;
    for (int i_sp = 0; i_sp < n_sp; i_sp++) {
        d1_sp += m_sp[i_sp][i_sp];
        d2_sp += m_sp[i_sp][n_sp - i_sp - 1];
    }

    if (d1_sp != magic_sp || d2_sp != magic_sp) ok_sp = false;

    cout << "\nResult: ";
    if (ok_sp) cout << " Magic Square is valid\n";
    else cout << " Magic Square is NOT valid\n";
}

int main() {
    int n_sp;
    cout << "Enter order n of Magic Square: ";
    cin >> n_sp;

    if (n_sp < 3) {
        cout << "Magic square not possible for n < 3\n";
        return 0;
    }

    vector<vector<int>> m_sp;

    if (n_sp % 2 == 1)
        m_sp = generateOdd_sp(n_sp);
    else if (n_sp % 4 == 0)
        m_sp = generateDoublyEven_sp(n_sp);
    else
        m_sp = generateSinglyEven_sp(n_sp);

    cout << "\nMagic Square of order " << n_sp << ":\n\n";
    displaySquare_sp(m_sp, n_sp);

    verifyMagic_sp(m_sp, n_sp);

    return 0;
}
