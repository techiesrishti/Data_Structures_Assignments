#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// dynamic memory allocation
int** allocateMatrix(int rows_sp, int cols_sp) {
    int** mat_sp = new int*[rows_sp];
    for (int i_sp = 0; i_sp < rows_sp; i_sp++) {
        mat_sp[i_sp] = new int[cols_sp];
    }
    return mat_sp;

    if(mat_sp == NULL){
        cout<<"allocateMatrix(): Memory allocation failed!";
    }
}



// free memory
void freeMatrix(int** mat_sp, int rows_sp) {
    for (int i_sp = 0; i_sp < rows_sp; i_sp++) {
        delete[] mat_sp[i_sp];
    }
    delete[] mat_sp;
}

// print matrix
void printMatrix(int** mat_sp, int rows_sp, int cols_sp, const string& name_sp) {
    cout << name_sp << " (" << rows_sp << " x " << cols_sp << "):\n";
    for (int i_sp = 0; i_sp < rows_sp; i_sp++) {
        for (int j_sp = 0; j_sp < cols_sp; j_sp++) {
            cout << mat_sp[i_sp][j_sp] << " ";
        }
        cout << "\n";
    }
}

// Row major
void multiplyRowMajor(int** A_sp, int** B_sp, int** C_sp, int m_sp, int n_sp, int p_sp) {
    for (int i_sp = 0; i_sp < m_sp; i_sp++) {
        for (int k_sp = 0; k_sp < n_sp; k_sp++) {
            int temp_sp = A_sp[i_sp][k_sp];
            for (int j_sp = 0; j_sp < p_sp; j_sp++) {
                C_sp[i_sp][j_sp] += temp_sp * B_sp[k_sp][j_sp];
            }
        }
    }
}

// Col major
void multiplyColMajor(int** A_sp, int** B_sp, int** C_sp, int m_sp, int n_sp, int p_sp) {
    for (int j_sp = 0; j_sp < p_sp; j_sp++) {
        for (int k_sp = 0; k_sp < n_sp; k_sp++) {
            int temp_sp = B_sp[k_sp][j_sp];
            for (int i_sp = 0; i_sp < m_sp; i_sp++) {
                C_sp[i_sp][j_sp] += A_sp[i_sp][k_sp] * temp_sp;
            }
        }
    }
}

int main() {
    int m_sp, n_sp, p_sp, choice_sp;
    cout << "Enter number of rows and columns of Matrix A: ";
    cin >> m_sp >> n_sp;
    cout << "Enter number of columns of Matrix B: ";
    cin >> p_sp;

    // dynamic memeory allocation 
    int** A_sp = allocateMatrix(m_sp, n_sp);
    int** B_sp = allocateMatrix(n_sp, p_sp);
    int** C_sp = allocateMatrix(m_sp, p_sp);

    // error checking
    if(A_sp == NULL || B_sp == NULL || C_sp == NULL){
        cout<<"main(): memeory allocation failed!";
    }
    // generate random no matrix
    srand(time(0));
    for (int i_sp = 0; i_sp < m_sp; i_sp++)
        for (int j_sp = 0; j_sp < n_sp; j_sp++)
            A_sp[i_sp][j_sp] = rand() % 10;

    for (int i_sp = 0; i_sp < n_sp; i_sp++)
        for (int j_sp = 0; j_sp < p_sp; j_sp++)
            B_sp[i_sp][j_sp] = rand() % 10;

    // print matrices 
    printMatrix(A_sp, m_sp, n_sp, "Matrix A");
    printMatrix(B_sp, n_sp, p_sp, "Matrix B");

    cout << "\nChoose order for multiplication:\n";
    cout << "1. Row-major order\n";
    cout << "2. Column-major order\n";
    cin >> choice_sp;

    // resultant matrix
    for (int i_sp = 0; i_sp < m_sp; i_sp++)
        for (int j_sp = 0; j_sp < p_sp; j_sp++)
            C_sp[i_sp][j_sp] = 0;

    clock_t start_sp = clock();

    if (choice_sp == 1)
        multiplyRowMajor(A_sp, B_sp, C_sp, m_sp, n_sp, p_sp);
    else if (choice_sp == 2)
        multiplyColMajor(A_sp, B_sp, C_sp, m_sp, n_sp, p_sp);
    else {
        cout << "Invalid choice\n";
        return 0;
    }

    clock_t end_sp = clock();
    double time_taken_sp = double(end_sp - start_sp) / CLOCKS_PER_SEC;

    // print resultant matrix
    printMatrix(C_sp, m_sp, p_sp, "Resultant Matrix ");
    cout << "Time taken: " << time_taken_sp << " seconds\n";

    // free memeory
    freeMatrix(A_sp, m_sp);
    freeMatrix(B_sp, n_sp);
    freeMatrix(C_sp, m_sp);

    return 0;
}
