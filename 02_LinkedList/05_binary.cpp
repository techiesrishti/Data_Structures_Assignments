#include<iostream>
using namespace std;

struct Node{
    int bit;
    Node* prev;
    Node* next;
};

class BinaryNo{
    public:
        Node* head;
        Node* tail;

    BinaryNo(){
        head = NULL;
        tail = NULL;
    }
    //copy constructorg
    BinaryNo(const BinaryNo &other){
        head = tail = NULL;
        Node* temp = other.head;
        while(temp != NULL){
            insertAtEnd(temp->bit);
            temp = temp->next;
        }
    }
    //free memory (destructor)
    ~BinaryNo(){
        Node* temp;
        while(head != NULL){
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
    }

    void insertAtEnd(int bit){
        Node* newNode = new Node;
        newNode->bit = bit;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display(){
        if(head == NULL){
            cout<<"list is empty\n";
            return;
        }
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->bit;
            if(temp->next != NULL){
                cout<< " <-> ";
            }
            temp = temp->next;
        }
        cout<<" <-> NULL\n";
    }

    //for finding 1's complement (1001)--(0110)
    void onesComp(){
        Node* temp = head;
        while(temp != NULL){
            temp->bit = (temp->bit == 0) ? 1 : 0;
            temp = temp->next;
        }
    }

    //for finding 2's complement (1's comp + 1) 
    // 0110
    //+   1
    // 0111

    void twosComp(){
        onesComp();
        Node* temp = tail;
        int carry = 1;

        while(temp != NULL && carry == 1){
            if(temp->bit == 0){
                temp->bit = 1;
                carry = 0;
            }
            else{
                temp->bit = 0;
                carry = 1;
            }
            temp = temp->prev;
        }
        // if there exists a carry at the end
        if(carry == 1){
            insertAtFront(1);
        }
    }
    // for adding two binary no
    static BinaryNo add(BinaryNo b1, BinaryNo b2){
        BinaryNo result;
        Node* t1 = b1.tail;
        Node* t2 = b2.tail;
        int carry = 0;

        while(t1 != NULL || t2 != NULL || carry == 1){
            int sum = carry;
            if(t1 != NULL){
                sum += t1->bit;
                t1=t1->prev;
            }
            if(t2 != NULL){
                sum += t2->bit;
                t2 = t2->prev;
            }

            result.insertAtFront(sum % 2);
            carry = sum/2;

        }
        return result;

    }
    // for inserting at front after addition
    void insertAtFront(int bit){
        Node* newNode = new Node;
        newNode->bit = bit;
        newNode->prev = NULL;
        newNode->next = head;

        if(head != NULL){
            head->prev = newNode;
        }
        else{
            tail = newNode;
        }

        head = newNode;
    }
};

int main(){
    BinaryNo bin1, bin2;
    int n;

    cout<<"enter no of bits in binary no: ";
    cin>>n;

    cout<<"enter binary no: ";
    for(int i=0; i<n; i++){
        int bit;
        cin>> bit;
        bin1.insertAtEnd(bit);
    }

    cout<<"\n1st binary no: ";
    bin1.display();

    // 1's complement
    BinaryNo ones = bin1;
    ones.onesComp();
    cout<<"\n 1's complement: ";
    ones.display();

    //2's complement
    BinaryNo twos = bin1;
    twos.twosComp();
    cout<<"\n 2's complement: ";
    twos.display();

    int m;
    cout<<"\n\n enter no of bits in 2nd binary no: ";
    cin>>m;

    cout<<"enter 2nd binary no: ";
    for(int i=0; i<m; i++){
        int bit;
        cin >> bit;
        bin2.insertAtEnd(bit);
    }

    cout<<"1st binary: ";
    bin1.display();

    cout<<"2ns Binary: ";
    bin2.display();

    BinaryNo sum = BinaryNo :: add(bin1, bin2);
    cout<< "\n sum : ";
    sum.display();

    return 0;
}