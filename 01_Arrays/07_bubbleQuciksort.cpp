#include <iostream>
#include <string>
using namespace std;

struct Student {
    string student_name_sp;
    int stud_roll_sp;
    float total_marks_sp;
};

//  function
void swap(Student &a_sp, Student &b_sp, int &count_sp) {
    Student temp_sp = a_sp;
    a_sp = b_sp;
    b_sp = temp_sp;
    count_sp++;
}

// bubble Sort
void bubbleSort(Student arr_sp[], int  n_sp, int &count_sp) {
    count_sp = 0;
    for(int i=0; i< n_sp-1; i++){
    for(int j=0;j< n_sp-1-i;j++){
        if(arr_sp[j].stud_roll_sp > arr_sp[j+1].stud_roll_sp){
            swap(arr_sp[j], arr_sp[j+1], count_sp);
        }
    }
}
}


// 3 2 6 5 1// 5 --> 5-1--4
// i 
// 

int partition(Student arr_sp[], int lb_sp, int ub_sp, int &count_sp) {
    int pivot_sp = arr_sp[lb_sp].stud_roll_sp; // choose first element as pivot_sp
    int start_sp = lb_sp;
    int end_sp = ub_sp;

    while (start_sp < end_sp) {
        while (start_sp <= ub_sp && arr_sp[start_sp].stud_roll_sp <= pivot_sp) {
            start_sp++;
        }
        while (arr_sp[end_sp].stud_roll_sp > pivot_sp) {
            end_sp--;
        }
        if (start_sp < end_sp) {
            swap(arr_sp[start_sp], arr_sp[end_sp], count_sp);
        }
    }
    swap(arr_sp[lb_sp], arr_sp[end_sp], count_sp); // place pivot_sp in correct position
    return end_sp;
}

void Quicksort(Student arr_sp[], int lb_sp, int ub_sp, int &count_sp) {
    if (lb_sp < ub_sp) {
        int loc_sp = partition(arr_sp, lb_sp, ub_sp, count_sp);
        Quicksort(arr_sp, lb_sp, loc_sp - 1, count_sp);
        Quicksort(arr_sp, loc_sp + 1, ub_sp, count_sp);
    }
}



// detials of student
void display(Student arr_sp[], int  n_sp) {
    cout << "\nRoll No\t Name\t Marks\t";
    cout << "\n n_sp-----------------------------------\n n_sp";
    for (int i = 0; i <  n_sp; i++) {
        cout << arr_sp[i].stud_roll_sp << "\t"
             << arr_sp[i].student_name_sp << "\t"
             << arr_sp[i].total_marks_sp << endl;
    }
}

int main() {
    int  n_sp;
    cout << "Enter number of students: ";
    cin >>  n_sp;

    Student *arr_sp = new Student[ n_sp];

    //  student data
    for (int i = 0; i <  n_sp; i++) {
        cout << "\nEnter details of student " << i + 1 << ":\n n_sp";
        cout << "Roll No: ";
        cin >> arr_sp[i].stud_roll_sp;
        cin.ignore();
        cout << "Name: ";
        getline(cin, arr_sp[i].student_name_sp);
        cout << "Total Marks: ";
        cin >> arr_sp[i].total_marks_sp;
    }

    // bubble Sort memory allocation
    Student *arrBubble_sort_sp = new Student[ n_sp];
    for (int i = 0; i <  n_sp; i++) 
        arrBubble_sort_sp[i] = arr_sp[i];


    // error checking
    if(!arrBubble_sort_sp){
        cout<<"main(): memory allocation failed for bubble sorting";
        exit(-1);
    }


    int bubble_count_swaps = 0;
    bubbleSort(arrBubble_sort_sp,  n_sp, bubble_count_swaps);

    cout << "\nBubble Sort";
    cout << "\n n_sp-----------------------------------";
    display(arrBubble_sort_sp,  n_sp);
    cout << "no of times swapped for bubble sort: " << bubble_count_swaps << endl;

    // quick Sort memory allocation 
    Student *arrQuick_sort_sp = new Student[ n_sp];
    for (int i = 0; i <  n_sp; i++){
        arrQuick_sort_sp[i] = arr_sp[i];
    }

    if(!arrQuick_sort_sp){
        cout<<"main(): memory allocation failed";
        exit(-1);
    }

    int quick_count_swaps = 0;
    Quicksort(arrQuick_sort_sp, 0,  n_sp-1, quick_count_swaps);

    cout<<"\nQuick sort ";
    cout << "\n n_sp-----------------------------------";
    display(arrQuick_sort_sp,  n_sp);
    cout<<"no of times swapped for quick sort: "<<quick_count_swaps;


    //free memory
    delete[] arr_sp;
    delete[] arrBubble_sort_sp;
    delete[] arrQuick_sort_sp;


    return 0;
}
