#include<iostream>
#include<cctype>
#include<iomanip>

using namespace std;
struct Node{
    char data;
    Node* next;
    Node(char val){
        data = val;
        next = NULL;
    }
};

class Stack{
    private:
    Node* top;

    public:
    Stack(){
        top = NULL;
    }

    bool isEmpty(){
        return (top == NULL);
    }

    void push(char c){
        Node* newNode = new Node(c);
        newNode->next = top;
        top = newNode;
    }

    char pop(){
        if(isEmpty()) 
            return '\0';
        char val= top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    char peek(){
        if(isEmpty())
            return '\0';
        return top->data;
    }

    string getStackStr(){
        string s = "";
        Node* temp = top;
        while(temp != NULL){
            s = temp->data + s;
            temp = temp->next;
        }
        return s;
    }

    ~Stack(){
        while(!isEmpty())
            pop();
    }
};

int priority(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infiToPost(string infix){
    Stack s;
    string postfix = "";

    cout<<"\n"<< left <<setw(10)<<"symbol"<<setw(20)<<"stack"<<setw(20)<<"postfix"<<endl;
    cout<<"-----------------------------------------------------------\n";

    for(int i =0; i<infix.length(); i++){
        char c= infix[i];

        if(c == ' ') continue; 

        if(isalnum(c)){
            postfix = postfix + c;
        }

        else if(c == '('){
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix = postfix + s.pop();
            }
            s.pop(); 

        }

        else{
            while(!s.isEmpty() && priority(c) <= priority(s.peek())){
                postfix = postfix + s.pop();
            }
            s.push(c);
        }

         cout << left << setw(10) << c
             << setw(20) << s.getStackStr()
             << setw(20) << postfix << endl;
    }

    while (!s.isEmpty()) {
        postfix = postfix + s.pop();
        cout << left << setw(10) << " " 
             << setw(20) << s.getStackStr()
             << setw(20) << postfix << endl;
    }

    cout << "\nFinal Postfix Ans: " << postfix << endl;
    return postfix;
}

int main(){
    string infix;
    cout<<"enter infix exp: ";
    cin>>infix;

    infiToPost(infix);

    return 0;
}

