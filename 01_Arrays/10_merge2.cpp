#include <iostream>
#include <string>
using namespace std;

struct Employee_sp {
    string name_sp;
    float height_sp;
    float weight_sp;
    float avg_sp;
};

// merge sort
void merge(Employee_sp A[], int lb_sp, int mid_sp, int ub_sp) {
    Employee_sp B[100]; // assume max 100 emps
    int i_sp = lb_sp, j_sp = mid_sp + 1, k_sp = lb_sp;

    while (i_sp <= mid_sp && j_sp <= ub_sp) {
        if (A[i_sp].avg_sp <= A[j_sp].avg_sp) {
            B[k_sp] = A[i_sp];
            i_sp++;
        } else {
            B[k_sp] = A[j_sp];
            j_sp++;
        }
        k_sp++;
    }

    while (i_sp <= mid_sp) {
        B[k_sp] = A[i_sp];
        i_sp++;
        k_sp++;
    }

    while (j_sp <= ub_sp) {
        B[k_sp] = A[j_sp];
        j_sp++;
        k_sp++;
    }

    for (int p = lb_sp; p <= ub_sp; p++) {
        A[p] = B[p];
    }
}

void mergeSort(Employee_sp A[], int lb_sp, int ub_sp) {
    if (lb_sp < ub_sp) {
        int mid_sp = (lb_sp + ub_sp) / 2;
        mergeSort(A, lb_sp, mid_sp);
        mergeSort(A, mid_sp + 1, ub_sp);
        merge(A, lb_sp, mid_sp, ub_sp);
    }
}

// selection sort for comparison
void selectionSort(Employee_sp arr[], int n) {
    for (int i_sp = 0; i_sp < n - 1; i_sp++) {
        int minIdx_sp = i_sp;
        for (int j_sp = i_sp + 1; j_sp < n; j_sp++) {
            if (arr[j_sp].avg_sp < arr[minIdx_sp].avg_sp) {
                minIdx_sp = j_sp;
            }
        }
        if (minIdx_sp != i_sp) {
            Employee_sp temp = arr[i_sp];
            arr[i_sp] = arr[minIdx_sp];
            arr[minIdx_sp] = temp;
        }
    }
}

void display(Employee_sp arr[], int n) {
    cout << "\nName\tHeight\tWeight\tAverage\n";
    cout << "----------------------------------\n";
    for (int i_sp = 0; i_sp < n; i_sp++) {
        cout << arr[i_sp].name_sp << "\t" << arr[i_sp].height_sp << "\t"
             << arr[i_sp].weight_sp << "\t" << arr[i_sp].avg_sp << endl;
    }
}

int main() {
    int n_sp;
    cout << "Enter number of employees: ";
    cin >> n_sp;

    Employee_sp arr[100];
    for (int i_sp = 0; i_sp < n_sp; i_sp++) {
        cout << "\nEnter details of employee " << i_sp + 1 << ":\n";
        cout << "Name: ";
        cin >> arr[i_sp].name_sp;
        cout << "Height: ";
        cin >> arr[i_sp].height_sp;
        cout << "Weight: ";
        cin >> arr[i_sp].weight_sp;
        arr[i_sp].avg_sp = (arr[i_sp].height_sp + arr[i_sp].weight_sp) / 2.0;
    }

    // Copies for both sorting algorithms
    Employee_sp arrSel_sp[100], arrMerge_sp[100];
    for (int i_sp = 0; i_sp < n_sp; i_sp++) {
        arrSel_sp[i_sp] = arr[i_sp];
        arrMerge_sp[i_sp] = arr[i_sp];
    }

    // Selection Sort
    selectionSort(arrSel_sp, n_sp);
    cout << "\nEmployees sorted by Selection Sort:\n";
    display(arrSel_sp, n_sp); 

    // Merge Sort (your logic)
    mergeSort(arrMerge_sp, 0, n_sp - 1);
    cout << "\nEmployees sorted by Merge Sort:\n";
    display(arrMerge_sp, n_sp);

    // Complexity Conclusion
    cout << "\n--- Complexity Analysis ---\n";
    cout << "Selection Sort: O(n^2)\n";
    cout << "Merge Sort: O(n log n)\n";
    cout << "Merge Sort is more efficient for larger datasets.\n";

    return 0;
}
