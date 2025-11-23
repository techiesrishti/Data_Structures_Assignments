#include<iostream>
#include<string>
using namespace std;

typedef struct generalNode{
    int flag;
    string data;
    generalNode* down;
    generalNode* next;
}gn;

gn* createNode(string val){
    gn* node = new gn;
    node->flag = 0;
    node->data = val;
    node->down = NULL;
    node->next = NULL;
    return node;
}

gn* createSubList(gn* sub){
    gn* node = new gn;
    node->flag = 1;
    node->down = sub;
    node->next = NULL;
    return node;
}

gn* createGLL(){
    gn* head = NULL;
    gn* tail = NULL;

    int n;
    cout<<"enter no of elements in the set: ";
    cin>> n;

    for(int i=0; i<n; i++){
        cout<<"\nelement "<<i+1 <<": atom/sublist [0/1]: ";
        int type;
        cin>> type;
        
        gn* newNode = NULL;
        if(type == 0){
            string val;
            cout<<"enter atom val: ";
            cin>>val;
            newNode = createNode(val);
        }
        else{
            cout<<"creating a sublist... \n";
            newNode = createSubList(createGLL());
        }

        if(head == NULL){
            head = newNode;
        }
        else{
            tail->next = newNode;
        }

        tail = newNode;

    }
    return head;
}

void display(gn* head){
    cout<<"{ ";
    gn* temp = head;
    while(temp != NULL){
        if(temp->flag == 0){
            cout<<temp->data;
        }
        else{
            display(temp->down);
        }
        temp = temp->next;
        if(temp != NULL) cout<< ", ";
    }
    cout<<" }";
}

int main(){
    cout<<"create gll in set form: \n";
    gn* gll = createGLL();

    cout<<"\n set representation: \n";
    display(gll);
    cout<<endl;
    return 0;
}