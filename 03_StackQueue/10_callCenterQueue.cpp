#include <iostream>
#include <string>
using namespace std;

struct Node {
    string customerName_sp;
    Node* next_sp;
};

class CallCenterQueue {
    Node* front_sp;
    Node* rear_sp;

public:
    CallCenterQueue() {
        front_sp = rear_sp = NULL;
    }

    void enqueue(string name_sp) {
        Node* newNode_sp = new Node;
        newNode_sp->customerName_sp = name_sp;
        newNode_sp->next_sp = NULL;

        if (rear_sp == NULL) {
            front_sp = rear_sp = newNode_sp;
            cout << "call from " << name_sp << " added to the queue.\n";
            return;
        }

        rear_sp->next_sp = newNode_sp;
        rear_sp = newNode_sp;
        cout << "call from " << name_sp << " added to the queue.\n";
    }

    void dequeue() {
        if (front_sp == NULL) {
            cout << "No calls in queue. System is waiting...\n";
            return;
        }

        Node* temp_sp = front_sp;
        cout << "call from " << front_sp->customerName_sp << " is being attended by an agent.\n";
        front_sp = front_sp->next_sp;

        if (front_sp == NULL)
            rear_sp = NULL;

        delete temp_sp;
    }

    void display() {
        if (front_sp == NULL) {
            cout << "No calls in queue \n";
            return;
        }

        cout << "Calls waiting in queue:\n";
        Node* temp_sp = front_sp;
        while (temp_sp != NULL) {
            cout << " " << temp_sp->customerName_sp << endl;
            temp_sp = temp_sp->next_sp;
        }
    }

    ~CallCenterQueue() {
        while (front_sp != NULL) {
            Node* temp_sp = front_sp;
            front_sp = front_sp->next_sp;
            delete temp_sp;
        }
    }
};

int main() {
    CallCenterQueue ccq_sp;
    int choice_sp;
    string name_sp;

    do {
        cout << "\n------ CALL CENTER MENU ------\n";
        cout << "1. New Call Arrived -> Enqueue\n";
        cout << "2. Assign Call to Agent -> Dequeue\n";
        cout << "3. Show Waiting Calls\n";
        cout << "4. Exit\n";
        cout << "-------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name_sp;
                ccq_sp.enqueue(name_sp);
                break;

            case 2:
                ccq_sp.dequeue();
                break;

            case 3:
                ccq_sp.display();
                break;

            case 4:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice_sp != 4);

    return 0;
}
