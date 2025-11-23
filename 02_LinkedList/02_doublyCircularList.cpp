#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node {
public:
    int seatNo;
    bool booked;
    Node* next;
    Node* prev;

    Node(int num) {
        seatNo = num;
        booked = false;
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircularList {
public:
    Node* head;

    DoublyCircularList() {
        head = NULL;
    }

    // free memory
    ~DoublyCircularList() {
        if (head == NULL) return;

        Node* temp = head->next;
        while (temp != head) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete head; // delete the last node
        head = NULL;
    }

    // creating rows 
    void createRow() {
        for (int i = 1; i <= 8; i++) {
            Node* newNode = new Node(i);
            if (head == NULL) {
                head = newNode;
                head->next = head;
                head->prev = head;
            } else {
                newNode->prev = head->prev;
                newNode->next = head;
                head->prev->next = newNode;
                head->prev = newNode;
            }
        }
    }

    // randomly booked seats
    void randomBooking() {
        int numBooked = 2 + rand() % 3; 
        for (int i = 0; i < numBooked; i++) {
            int seatNum = 1 + rand() % 8;
            Node* temp = head;
            do {
                if (temp->seatNo == seatNum) {
                    temp->booked = true;
                    break;
                }
                temp = temp->next;
            } while (temp != head);
        }
    }

    void displayRow() {
        if (head == NULL) return;

        Node* temp = head;
        cout << "[ ";
        do {
            if (temp->booked)
                cout << "X ";
            else
                cout << temp->seatNo << " "; 
            temp = temp->next;
        } while (temp != head);
        cout << "]\n";
    }

    // book seat
    void bookSeat(int seatNum) {
        if (head == NULL) return;

        Node* temp = head;
        do {
            if (temp->seatNo == seatNum) {
                if (temp->booked)
                    cout << "Seat " << seatNum << " is already booked.\n";
                else {
                    temp->booked = true;
                    cout << "Seat " << seatNum << " booked successfully!\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Invalid seat number!\n";
    }

    // Cancel seat
    void cancelSeat(int seatNum) {
        if (head == NULL) return;

        Node* temp = head;
        do {
            if (temp->seatNo == seatNum) {
                if (!temp->booked)
                    cout << "Seat " << seatNum << " is not booked.\n";
                else {
                    temp->booked = false;
                    cout << "Booking for seat " << seatNum << " canceled.\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "invalid seat number\n";
    }
};

int main() {
    srand(time(0));

    DoublyCircularList multiplex[8]; 

    for (int i = 0; i < 8; i++) {
        multiplex[i].createRow();
        multiplex[i].randomBooking();
    }

    int choice, row, seat, n;

    do {
        cout << "\n Galaxy Multiplex Ticket Reservation \n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seats\n";
        cout << "3. Cancel Booking\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nNo of Seats Available \n";
            for (int i = 0; i < 8; i++) {
                cout << "Row " << (i + 1) << ": ";
                multiplex[i].displayRow();
            }
            break;

        case 2:
            cout << "Enter row number: ";
            cin >> row;
            if (row < 1 || row > 8) {
                cout << "Invalid row.\n";
                break;
            }
            cout << "How many seats to book? ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter seat number: ";
                cin >> seat;
                multiplex[row - 1].bookSeat(seat);
            }
            break;

        case 3:
            cout << "Enter row number: ";
            cin >> row;
            if (row < 1 || row > 8) {
                cout << "Invalid row.\n";
                break;
            }
            cout << "Enter seat number to cancel: ";
            cin >> seat;
            multiplex[row - 1].cancelSeat(seat);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    cout << "Bye...\n";
    return 0;
}
