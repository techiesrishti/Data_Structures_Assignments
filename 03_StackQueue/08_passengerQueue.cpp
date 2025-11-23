#include <iostream>
#include <string>
using namespace std;

class PassengerQueue {
    int front_sp, rear_sp, size_sp, count_sp;
    string *queue_sp;   

public:
    PassengerQueue(int n_sp) {
        size_sp = n_sp;
        queue_sp = new string[size_sp];
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

    void insertPassenger(string name_sp) {
        if (isFull()) {
            cout << "queue is full! cannot add " << name_sp << "\n";
            return;
        }
        rear_sp = (rear_sp + 1) % size_sp;
        queue_sp[rear_sp] = name_sp;
        count_sp++;
        cout << "passenger '" << name_sp << "' added to the queue.\n";
    }

    void removePassenger() {
        if (isEmpty()) {
            cout << "queue is empty! no passengers to remove.\n";
            return;
        }
        cout << "passenger '" << queue_sp[front_sp] << "' has been served and removed from the queue.\n";
        front_sp = (front_sp + 1) % size_sp;
        count_sp--;
    }

    void showFrontPassenger() {
        if (isEmpty()) {
            cout << "queue is empty! No passenger at front.\n";
            return;
        }
        cout << "passenger at front of queue: " << queue_sp[front_sp] << endl;
    }

    void displayPassengers() {
        if (isEmpty()) {
            cout << "no passengers waiting.\n";
            return;
        }
        cout << "\ncurrent passengers in queue:\n";
        int i_sp = front_sp;
        for (int c_sp = 0; c_sp < count_sp; c_sp++) {
            cout << "  " << queue_sp[i_sp] << endl;
            i_sp = (i_sp + 1) % size_sp;
        }
    }

    void totalPassengers() {
        cout << "\n no of passengers left in queue: " << count_sp << endl;
    }

    ~PassengerQueue() {
        delete[] queue_sp;
    }
};

int main() {
    int n_sp, choice_sp;
    string name_sp;

    cout << "enter max no of passengers that can wait: ";
    cin >> n_sp;

    PassengerQueue pq_sp(n_sp);

    do {
        cout << "\n------- PASSENGER QUEUE MENU -------\n";
        cout << "1. Insert new passenger\n";
        cout << "2. Show passenger at front\n";
        cout << "3. Remove passenger from front\n";
        cout << "4. Display all waiting passengers\n";
        cout << "5. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "Enter passenger name: ";
                cin.ignore();
                getline(cin, name_sp);
                pq_sp.insertPassenger(name_sp);
                break;

            case 2:
                pq_sp.showFrontPassenger();
                break;

            case 3:
                pq_sp.removePassenger();
                break;

            case 4:
                pq_sp.displayPassengers();
                break;

            case 5:
                pq_sp.totalPassengers();
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice_sp != 5);

    return 0;
}
