#include<iostream>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node(char c){
        data = c;
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
    void push(char c){
        Node* newNode = new Node(c);
        newNode->next = top;
        top = newNode;
    }

    char pop(){
        if(isEmpty()){
            return '\0';
        }
        Node* temp = top;
        char poppedEle = temp->data;
        top = top->next;
        delete temp;
        return poppedEle;
    }

    char ele(){
        if(isEmpty()) return '\0';
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }

    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }
};

bool isMAtching(char open, char close){
    return(open == '(' && close == ')') ||
          (open == '{' && close == '}') ||
          (open == '[' && close == ']');
}

bool isBalanced(string bracket){
    Stack s;
    for(char ch : bracket){
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(s.isEmpty()){
                return false;
            }
            char top = s.pop();
            if(!isMAtching(top, ch)){
                return false;
            }
        }
    }

    return s.isEmpty();
    
}
int main(){
    string bracket;
    cout<<"enter the parathenses: ";
    cin>>bracket;

    if(isBalanced(bracket)) cout<<"parentheses are balanced\n ";
    else cout<<"the paratheses are not balanced! \n";

    return 0;
}