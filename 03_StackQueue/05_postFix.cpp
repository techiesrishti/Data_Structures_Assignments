#include<iostream>
#include<string>

using namespace std;

class Stack {
    int top_sp;
    int size_sp;
    int *arr_sp;

    public:
        Stack(int n_sp){
            size_sp = n_sp;
            arr_sp = new int[size_sp];
            top_sp = -1;
        }

        bool isEmpty(){
            return (top_sp == -1);
        }

        bool isFull(){
            return (top_sp == size_sp - 1);
        }

        void push(int value_sp){
            if(isFull()){
                cout<<"Stack overflow! cannot push "<<value_sp<<endl;
                return;
            }
            arr_sp[++top_sp]= value_sp;
        }

        int pop(){
            if(isEmpty()){
                cout<<"stack underflow!"<<endl;
                return -1;

            }
            return arr_sp[top_sp--];
        }

        int peek(){
            if(isEmpty()){
                cout<<"stack is empty! "<<endl;
                return -1;
            }

            return arr_sp[top_sp];
        }

        ~Stack(){
            delete[] arr_sp;
        }
};

int evaluate_sp(string str_sp){
    Stack st_sp(str_sp.length());

    for(int i_sp = 0; i_sp < str_sp.length(); i_sp++){
        char ch_sp = str_sp[i_sp];

        if(ch_sp == ' ') continue;

        if(isdigit(ch_sp)){
            st_sp.push(ch_sp - '0');
        }
        else{
            int val2_sp = st_sp.pop();
            int val1_sp = st_sp.pop();

            switch(ch_sp){
                case '+': st_sp.push(val1_sp + val2_sp); break;
                case '-': st_sp.push(val1_sp - val2_sp); break;
                case '*': st_sp.push(val1_sp * val2_sp); break;
                case '/': st_sp.push(val1_sp / val2_sp); break;

                default:
                    cout<<"invalid operator: "<<ch_sp<<endl;
                    return -1;
            }
        }
    }

    return st_sp.pop();
}

int main(){
    string str_sp;
    cout<<"enter postfix expression: ";
    getline(cin, str_sp);

    int result_sp = evaluate_sp(str_sp);
    cout<<"result : "<<result_sp<<endl;

    return 0;

}