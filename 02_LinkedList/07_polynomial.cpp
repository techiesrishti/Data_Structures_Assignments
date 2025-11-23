#include<iostream>
using namespace std;

struct Node{
    int coefficient;
    int power;
    Node* next;
};

class PolynomialAddition{
    public:
        Node* head;

        PolynomialAddition(){
            head = NULL;
        }

        void insert(int coefficient, int power){
            Node* newNode = new Node;
            newNode->coefficient = coefficient;
            newNode->power = power;
            newNode->next = NULL;

            if(head == NULL){
                head = newNode;
            }
            else{
                Node* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout<< temp->coefficient <<"x^"<<temp->power;
                temp = temp->next;
                if(temp != NULL){
                    cout<<" + ";
                }

            }
            cout<<endl;
        }
        void displayLinkedList() {
            Node* temp = head;
            while (temp != NULL) {
                cout << "[" << temp->coefficient << "x^" << temp->power << "] -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
        static PolynomialAddition add(PolynomialAddition p1, PolynomialAddition p2){
                PolynomialAddition result;
                Node* t1 = p1.head;
                Node* t2 = p2.head;

                while(t1 != NULL && t2 != NULL){
                    if(t1->power == t2->power){
                        int sum = t1->coefficient + t2->coefficient;
                        if(sum != 0){
                            result.insert(sum, t1->power);
                        }
                        t1 = t1->next;
                        t2 = t2->next;
                    }
                    else if(t1->power > t2-> power){
                        result.insert(t1->coefficient, t1->power);
                        t1 = t1->next;
                    }
                    else{
                        result.insert(t2->coefficient, t2->power);
                        t2 = t2->next;
                    }
                }

                while(t1 != NULL){
                    result.insert(t1->coefficient, t1->power);
                    t1 = t1->next;
                }
                while (t2 != NULL)
                {
                    result.insert(t2->coefficient, t2->power);
                    t2 = t2->next;
                }

                return result;
                
        }

};

int main(){
    PolynomialAddition p1, p2, sum;
    int n1, n2, coef, pow;

    cout<<"enter no of terms in 1st polynomial: ";
    cin >> n1;
    cout<<"enter terms coef and power: \n";
    for(int i=0; i<n1; i++){
        cin>> coef >> pow;
        p1.insert(coef, pow);
    }

    cout<<"enter no of terms in 2ns polynomial: ";
    cin >> n2;
    cout<<"enter terms coef and power: \n";
    for(int i=0; i<n2; i++){
        cin>> coef >> pow;
        p2.insert(coef, pow);
    }

    cout<<"polynomial 1: ";
    p1.display();
    p1.displayLinkedList();

    cout<<"polynomail 2: ";
    p2.display();
    p2.displayLinkedList();

    sum = PolynomialAddition::add(p1,p2);

    cout<<"\nsum: ";
    sum.display();
    sum.displayLinkedList();

    return 0;

}