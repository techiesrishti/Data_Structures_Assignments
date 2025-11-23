#include<iostream>
#include<stdexcept>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

class LinkedList {
    public:
        Node* head;
    LinkedList(){
        head = NULL;
    }

    ~LinkedList(){
        free();
    }

    void free(){
        Node* temp;
        while(head != NULL){
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp->data;
            if(temp->next != NULL){
                cout<<" -> ";
            }
            temp = temp->next;
        }
        cout<<" -> NULL";
        cout<<endl;
    }

    void FrontBackSplit(LinkedList &front, LinkedList &back){
        if(head == NULL)
            throw invalid_argument("error: the list is null.");
        if(head->next == NULL)
            throw invalid_argument("error: at least 2 nodes are needed for splitting. ");

        Node* slow = head;
        Node* fast = head->next;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }

        front.head = head;
        back.head = slow->next;
        slow->next = NULL;

        this->head = NULL;
    }
};

int main(){
    LinkedList l, f, b;
    int n, val;

    cout<<"enter no of elements in the list: ";
    cin>>n;

    if(n <= 0){
        cout<<"!!at least one node is needed"<<endl;
        return 0;
    }

    cout<<"enter elements: ";
    for(int i=0; i<n; i++){
        cin>>val;
        l.insertAtEnd(val);
    }

    cout<<"\n List: ";
    l.display();

    try{
        l.FrontBackSplit(f, b);
        cout<<"front half of the list: ";
        f.display();
        cout<<"back half of the list: ";
        b.display();
    }catch(const invalid_argument &e){
        cout<< e.what() <<endl;
    }
    

    return 0;
}