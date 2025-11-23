#include <iostream>
#include <string>
using namespace std;

class Queue {
    int front_sp, rear_sp, size_sp, count_sp;
    string *arr_sp;

public:
    Queue(int n_sp) {
        size_sp = n_sp;
        arr_sp = new string[size_sp];
        front_sp = 0;
        rear_sp = -1;
        count_sp = 0;
    }

    bool isFull() {
        return (count_sp == size_sp);
    }

    bool isEmpty() {
        return (count_sp == 0);
    }

    void enqueue(string name_sp) {
        if (isFull()) {
            cout << "queue overflow! no more patients can be added.\n";
            return;
        }
        rear_sp = (rear_sp + 1) % size_sp;
        arr_sp[rear_sp] = name_sp;
        count_sp++;
        cout << "Patient " << name_sp << " has been checked in.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "queue underflow! no patients to serve.\n";
            return;
        }
        cout << "Doctor is now seeing patient: " << arr_sp[front_sp] << endl;
        front_sp = (front_sp + 1) % size_sp;
        count_sp--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patients waiting.\n";
            return;
        }
        cout << "\nPatients waiting in queue:\n";
        int i_sp = front_sp;
        for (int c = 0; c < count_sp; c++) {
            cout << "  " << arr_sp[i_sp] << endl;
            i_sp = (i_sp + 1) % size_sp;
        }
    }

    ~Queue() {
        delete[] arr_sp;
    }
};

int main() {
    int n_sp, choice_sp;
    cout << "Enter maximum no of patients queue can hold: ";
    cin >> n_sp;

    Queue q_sp(n_sp);
    string name_sp;

    do {
        cout << "\n--------- MENU ----------\n";
        cout << "1. check-in new patient\n";
        cout << "2. assign next patient to doctor\n";
        cout << "3. display waiting patients\n";
        cout << "4. exit\n";
        cout << "--------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "Enter patient name: ";
                cin.ignore();
                getline(cin, name_sp);
                q_sp.enqueue(name_sp);
                break;
            case 2:
                q_sp.dequeue();
                break;
            case 3:
                q_sp.display();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice_sp != 4);

    return 0;
}
