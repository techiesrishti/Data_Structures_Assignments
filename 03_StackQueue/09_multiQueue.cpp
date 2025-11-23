#include <iostream>
using namespace std;

class MultiQueue {
    int front1_sp, rear1_sp, front2_sp, rear2_sp;
    int size_sp;
    int *queue1_sp, *queue2_sp;

public:
    MultiQueue(int n_sp) {
        size_sp = n_sp;
        queue1_sp = new int[size_sp];
        queue2_sp = new int[size_sp];
        front1_sp = rear1_sp = -1;
        front2_sp = rear2_sp = -1;
    }

    void enqueue1(int val_sp) {
        if (rear1_sp == size_sp - 1) {
            cout << "queue 1 overflow!\n";
            return;
        }
        if (front1_sp == -1) front1_sp = 0;
        queue1_sp[++rear1_sp] = val_sp;
        cout << "inserted " << val_sp << " into Queue 1\n";
    }

    void dequeue1() {
        if (front1_sp == -1 || front1_sp > rear1_sp) {
            cout << "queue 1 underflow!\n";
            return;
        }
        cout << "deleted " << queue1_sp[front1_sp++] << " from Queue 1\n";
    }

    void display1() {
        if (front1_sp == -1 || front1_sp > rear1_sp) {
            cout << "queue 1 is empty.\n";
            return;
        }
        cout << "queue 1 elements: ";
        for (int i = front1_sp; i <= rear1_sp; i++)
            cout << queue1_sp[i] << " ";
        cout << endl;
    }

    void enqueue2(int val_sp) {
        if (rear2_sp == size_sp - 1) {
            cout << "queue 2 overflow!\n";
            return;
        }
        if (front2_sp == -1) front2_sp = 0;
        queue2_sp[++rear2_sp] = val_sp;
        cout << "inserted " << val_sp << " into Queue 2\n";
    }

    void dequeue2() {
        if (front2_sp == -1 || front2_sp > rear2_sp) {
            cout << "queue 2 underflow!\n";
            return;
        }
        cout << "deleted " << queue2_sp[front2_sp++] << " from Queue 2\n";
    }

    void display2() {
        if (front2_sp == -1 || front2_sp > rear2_sp) {
            cout << "queue 2 is empty.\n";
            return;
        }
        cout << "queue 2 elements: ";
        for (int i = front2_sp; i <= rear2_sp; i++)
            cout << queue2_sp[i] << " ";
        cout << endl;
    }

    ~MultiQueue() {
        delete[] queue1_sp;
        delete[] queue2_sp;
    }
};

int main() {
    int size_sp, choice_sp, qno_sp, val_sp;

    cout << "Enter size of each queue: ";
    cin >> size_sp;

    MultiQueue mq_sp(size_sp);

    do {
        cout << "\n--------- MENU ---------\n";
        cout << "1. Add to Queue\n";
        cout << "2. Delete from Queue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "Enter queue number (1/2): ";
                cin >> qno_sp;
                cout << "Enter value: ";
                cin >> val_sp;
                if (qno_sp == 1) mq_sp.enqueue1(val_sp);
                else if (qno_sp == 2) mq_sp.enqueue2(val_sp);
                else cout << "Invalid queue number!\n";
                break;

            case 2:
                cout << "Enter queue number (1/2): ";
                cin >> qno_sp;
                if (qno_sp == 1) mq_sp.dequeue1();
                else if (qno_sp == 2) mq_sp.dequeue2();
                else cout << "Invalid queue number!\n";
                break;

            case 3:
                mq_sp.display1();
                mq_sp.display2();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice_sp != 4);

    return 0;
}
