#include<iostream>
#include<utility>
using namespace std;

void printArr(int arr_sp[], int n_sp){
    for(int i_sp= 0; i_sp < n_sp; i_sp++){
        cout<<arr_sp[i_sp];
        if(i_sp < n_sp-1)
            cout<<" ";
    }
    cout<<"\n";
}

int partition(int arr_sp[], int lb_sp, int ub_sp, int &count_sp, int &passes_sp, int n_sp){
    int pivot_sp = arr_sp[lb_sp];
    int start_sp = lb_sp + 1;
    int end_sp = ub_sp;
    int swaps_sp = 0;

    while(true){
        while(start_sp <= ub_sp && arr_sp[start_sp] <= pivot_sp){
            start_sp++;
        }
        while(arr_sp[end_sp] > pivot_sp){
            end_sp--;
        }
        if(start_sp < end_sp){
            swap(arr_sp[start_sp], arr_sp[end_sp]);
            swaps_sp++;
            count_sp++;
        }
        else{
            break;
        }
    }
    if(lb_sp != end_sp){
        swap(arr_sp[lb_sp], arr_sp[end_sp]);
        swaps_sp++;
        count_sp++;
    }

    cout<<"Pass "<<passes_sp++<<"---- pivot "<<pivot_sp<<" is placed at "<<end_sp<<"\nSwaps:"<<swaps_sp<<"\t";
    printArr(arr_sp, n_sp);

    return end_sp;
}
//recursive 
void quickSort(int arr_sp[], int lb_sp, int ub_sp, int &count_sp, int &passes_sp, int n_sp){
    if(lb_sp < ub_sp){
        int p_sp = partition(arr_sp, lb_sp, ub_sp, count_sp, passes_sp, n_sp);
        quickSort(arr_sp, lb_sp, p_sp - 1, count_sp, passes_sp, n_sp);
        quickSort(arr_sp, p_sp + 1, ub_sp, count_sp, passes_sp, n_sp);
    }
}

pair<int,int> minMax_sp(int arr_sp[], int lb_sp, int ub_sp){
    if(lb_sp == ub_sp){
        return {arr_sp[lb_sp], arr_sp[lb_sp]};
    }

    if(lb_sp + 1 == ub_sp){
        if(arr_sp[lb_sp] < arr_sp[ub_sp]) 
            return {arr_sp[lb_sp], arr_sp[ub_sp]};
        else 
            return {arr_sp[ub_sp], arr_sp[lb_sp]};
    }
    int mid_sp = (lb_sp + ub_sp)/ 2;
    pair<int,int> left_sp = minMax_sp(arr_sp, lb_sp, mid_sp);
    pair<int,int> right_sp = minMax_sp(arr_sp, mid_sp + 1, ub_sp);
    int mn_sp = (left_sp.first < right_sp.first) ? left_sp.first : right_sp.first;
    int mx_sp = (left_sp.second > right_sp.second) ? left_sp.second : right_sp.second;
    return {mn_sp, mx_sp};
}

int main(){
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "No students.\n";
        return 0;
    }

    int *marks = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];
    }

    cout<<"\noriginal array \n";
    printArr(marks, n);

    cout<<endl;
    int swaps = 0, passes = 1;
    quickSort(marks, 0, n-1, swaps, passes, n);
    cout<<endl;
    cout<<"sorted marks in ascending order \n";
    printArr(marks, n);
    cout<<endl;
    cout<<"total swaps performed: "<<swaps<<endl;

    pair<int,int> result_sp = minMax_sp(marks, 0, n-1);
    cout<<"min marks "<<result_sp.first<<endl;
    cout<<"max marks "<<result_sp.second<<endl;

    delete[] marks;
    return 0;
}