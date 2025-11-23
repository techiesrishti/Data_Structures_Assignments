#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class StockPriceStack{
    private:
    Node* top;

    public:
    StockPriceStack(){
        top = NULL;
    }

    ~StockPriceStack(){
        while(!isEmpty()){
            remove();
        }
        cout<<"\nAll prices removed successfully.\n";
    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    void record(int price){
        Node* newNode = new Node(price);
        newNode->next = top;
        top = newNode;
        cout<<"recorded price : "<<price<<endl;
    }

    int remove(){
        if(isEmpty()){
            cout<<"no prices to remove!\n";
            return -1;
        }
        Node* temp = top;
        int removedPrice = temp->data;
        top = top->next;
        delete temp;
        cout<<"the most recent price has been removed: "<<removedPrice<<endl;
        return removedPrice;
    }

    int latest(){
        if(isEmpty()){
            cout<<"no prices has been recorded yet!\n";
            return -1;
        }

        cout<<"latest recorded price : "<<top->data<<endl;
        return top->data;
    }

    void display(){
        if(isEmpty()){
            cout<<"no prices recorded yet!\n";
            return;

        }
        cout<<"price history : ";
        Node* temp = top;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }


};

int main(){
    StockPriceStack sp;
    int choice_sp, price_sp;

    cout<<"-------Stock Price Tracker---------\n";
    do{
        cout<<"\n1. record new price\n 2. remove latest price\n 3. view latest price\n 4. check if empty list\n 5. display all prices\n 6. exit\n";
        cout<<"enter your choice: ";
        cin>>choice_sp;

        switch(choice_sp){
            case 1:
            cout<<"enter stock price to record: ";
            cin>>price_sp;
            sp.record(price_sp);
            break;

            case 2:
            sp.remove();
            break;

            case 3:
            sp.latest();
            break;

            case 4:
            if(sp.isEmpty()) cout<<"no prices recorded yet!\n";
            else cout<<"prices are recorded!\n";
            break;

            case 5:
            sp.display();
            break;

            case 6:
            cout<<"exiting...\n";
            break;

            default:
            cout<<"invalid choice!\n";

        }
    }while(choice_sp != 6);

    return 0;
}