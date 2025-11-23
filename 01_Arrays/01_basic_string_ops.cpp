#include<iostream>
using namespace std;

//function for calculating length of string
int calculate_length(char str_sp[]){
    int len_sp = 0;
    while(str_sp[len_sp] != '\0'){
        len_sp++;
    }
    return len_sp;
}

//function for copying string
void copy_of_String(char dest_sp[], char src_sp[]){
    int i_sp=0;
    while(src_sp[i_sp] != '\0'){
        dest_sp[i_sp] = src_sp[i_sp];
        i_sp++;
    }
    dest_sp[i_sp] = '\0';
}

//function for reversing a string
void reverse_of_string(char str_sp[]){
    int len_sp = calculate_length(str_sp);
    int start_sp = 0, end_sp = len_sp - 1;
    while(start_sp < end_sp){
        char temp_sp = str_sp[start_sp];
        str_sp[start_sp] = str_sp[end_sp];
        str_sp[end_sp] = temp_sp;
        start_sp++;
        end_sp--;
    }
}

//function to concatenate 2 strings
void concatenation_of_Strings(char str1_sp[], char str2_sp[]){
    int len3_sp = calculate_length(str1_sp);
    int i_sp = 0;
    while(str2_sp[i_sp] != '\0'){
        str1_sp[len3_sp + i_sp] = str2_sp[i_sp];
        i_sp++;
    }
    str1_sp[len3_sp + i_sp] = '\0';
}

//main function
int main(){
    char str1_sp[100], str2_sp[200], str3_sp[300];

    cout<<"Enter 1st string: ";
    cin.getline(str1_sp, 100);

    cout<<"Enter 2nd string: ";
    cin.getline(str2_sp, 100);

    cout<<"Length of 1st string: "<<calculate_length(str1_sp)<<endl;
    cout<<"Length of 2nd string: "<<calculate_length(str2_sp)<<endl;

    copy_of_String(str3_sp, str1_sp);
    cout<<"Copy of 1st string: "<<str3_sp<<endl;

    reverse_of_string(str1_sp);
    reverse_of_string(str2_sp);

    cout<<"Reverse of 1st string: "<<str1_sp<<endl;
    cout<<"Reverse of 2nd string: "<<str2_sp<<endl;

    concatenation_of_Strings(str1_sp, str2_sp);
    cout<<"Concatenated strings: "<<str1_sp<<endl;

    return 0;
}
