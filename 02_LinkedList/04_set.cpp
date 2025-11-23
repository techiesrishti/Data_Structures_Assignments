#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int roll) {
        Node* newNode = new Node;
        newNode->roll = roll;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void displayStud() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty \n";
            return;
        }
        while (temp != NULL) {
            cout << temp->roll;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    bool contains(int roll) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->roll == roll)
                return true;
            temp = temp->next;
        }
        return false;
    }

    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void freeMemory() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList cricket, football;
    int totalStudents, n1, n2;

    cout << "Enter total number of students in class ";
    cin >> totalStudents;

    cout << "\nEnter number of students who like Cricket ";
    cin >> n1;
    cout << "Enter their roll numbers \n";
    for (int i = 0; i < n1; i++) {
        int roll;
        cin >> roll;
        cricket.insert(roll);
    }

    cout << "\nEnter number of students who like Football ";
    cin >> n2;
    cout << "Enter their roll numbers \n";
    for (int i = 0; i < n2; i++) {
        int roll;
        cin >> roll;
        football.insert(roll);
    }

    cout << "\nCricket (Set A): ";
    cricket.displayStud();

    cout << "Football (Set B): ";
    football.displayStud();

    // students who like both
    cout << "\n1. Students who like both Cricket and Football: ";
    Node* tempA = cricket.head;
    bool found = false;
    while (tempA != NULL) {
        if (football.contains(tempA->roll)) {
            cout << tempA->roll << " ";
            found = true;
        }
        tempA = tempA->next;
    }
    if (!found) cout << "None";
    cout << endl;

    // students who like either but not both
    cout << "2. Students who like either Cricket or Football but not both: ";
    tempA = cricket.head;
    while (tempA != NULL) {
        if (!football.contains(tempA->roll))
            cout << tempA->roll << " ";
        tempA = tempA->next;
    }
    Node* tempB = football.head;
    while (tempB != NULL) {
        if (!cricket.contains(tempB->roll))
            cout << tempB->roll << " ";
        tempB = tempB->next;
    }
    cout << endl;

    // students who like neither
    int unionCount = 0;
    tempA = cricket.head;
    while (tempA != NULL) {
        unionCount++;
        tempA = tempA->next;
    }
    tempB = football.head;
    while (tempB != NULL) {
        if (!cricket.contains(tempB->roll))
            unionCount++;
        tempB = tempB->next;
    }

    cout << "3. number of students who like neither Cricket nor Football: "
         << (totalStudents - unionCount) << endl;

    cricket.freeMemory();
    football.freeMemory();

    return 0;
}
