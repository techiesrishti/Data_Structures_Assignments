#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name_sp;
    int marks_sp;
    int roll_no_sp;
};

// swap
void mySwap(Student &a_sp, Student &b_sp) {
    Student temp_sp = a_sp;
    a_sp = b_sp;
    b_sp = temp_sp;
}

void bubbleSort(Student arr_sp[], int n_sp) {
    for (int i_sp = 0; i_sp < n_sp - 1; i_sp++) {
        cout << "\nPass " << i_sp + 1 << ":\n_sp";
        for (int j_sp = 0; j_sp < n_sp - 1 - i_sp; j_sp++) {
            if (arr_sp[j_sp].marks_sp < arr_sp[j_sp + 1].marks_sp) {
                mySwap(arr_sp[j_sp], arr_sp[j_sp + 1]);
            }
        }
        // show array after each pass
        for (int k_sp = 0; k_sp < n_sp; k_sp++) {
            cout << "\t" <<arr_sp[k_sp].marks_sp;
        }
        cout << endl;
    }
}

int main() {
    int n_sp;
    cout << "Enter number of students: ";
    cin >> n_sp;

    Student cls[50];  // assuming max 50 students

    for (int i_sp = 0; i_sp < n_sp; i_sp++) {
        cout << "\nEnter name_sp of student " << i_sp + 1 << ": ";
        cin >> cls[i_sp].name_sp;   
        cout << "Enter previous-year marks_sp of " << cls[i_sp].name_sp << ": ";
        cin >> cls[i_sp].marks_sp;
        cls[i_sp].roll_no_sp = 0;
    }

    // sort by marks_sp descending 
    bubbleSort(cls, n_sp);

    // assign roll numbers
    for (int i_sp = 0; i_sp < n_sp; i_sp++) {
        cls[i_sp].roll_no_sp = i_sp + 1;
    }

    // Final list
    cout << "\nFinal Roll No Assignment:\n_sp";
    cout << "Roll No\tName\tMarks\n_sp";
    cout << "---------------------------\n_sp";
    for (int i_sp = 0; i_sp < n_sp; i_sp++) {
        cout << cls[i_sp].roll_no_sp << "\t" << cls[i_sp].name_sp 
             << "\t" << cls[i_sp].marks_sp << endl;
    }

    return 0;
}
