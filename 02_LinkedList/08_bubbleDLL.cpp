#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class BubbleSort{
    public:
        Node* head;
        Node* tail;

    BubbleSort(){
        head = NULL;
        tail = NULL;
    }

    ~BubbleSort(){
        Node* current = head;
        Node* nextNode;

        while(current != NULL){
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data;
            if(temp->next) 
                cout<<" <-> ";
            temp = temp->next;
        }
        cout<<" <-> NULL \n";
    }

    void bubbleSort(){
        if(!head)
            return;
        bool swapped;
        Node* ptr_sp;
        Node* last = NULL;

        do{
            swapped = false;
            ptr_sp = head;

            while(ptr_sp->next != last){
                if(ptr_sp->data > ptr_sp->next->data){
                    int temp = ptr_sp->data;
                    ptr_sp->data = ptr_sp->next->data;
                    ptr_sp->next->data = temp;
                    swapped = true;
                }
                ptr_sp = ptr_sp->next;
            }
            last = ptr_sp;
        }while(swapped);
    }
};

int main(){
    BubbleSort bs_sp;
    int n_sp, val_sp;

    cout<<"enter no of elements: ";
    cin>>n_sp;

    cout<<"enter elements: ";
    for(int i=0; i<n_sp; i++){
        cin>>val_sp;
        bs_sp.insertAtEnd(val_sp);
    }

    cout<<"\nlist: ";
    bs_sp.display();

    bs_sp.bubbleSort();

    cout<<"sorted using bubble sort: ";
    bs_sp.display();

    return 0;
}