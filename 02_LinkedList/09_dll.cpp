#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node() {
        int val = this->data;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
    }
};

// for printing the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << " <-> NULL" << endl;
}

// length of ll
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node*& tail, Node*& head, int d) {
    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node*& tail, Node*& head, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node*& tail, Node*& head, int position, int d) {
    if (position == 1) {
        insertAtHead(tail, head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, head, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node*& head) {
    if (position == 1) {
        Node* temp = head;
        if (temp->next != NULL) {
            temp->next->prev = NULL;
        }
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while (cnt < position && curr != NULL) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (curr->next != NULL)
            curr->next->prev = prev;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int choice;
    do {
        cout << "\n----------doubly linked list implementation ---------- \n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Node\n";
        cout << "5. Display Linked List\n";
        cout << "6. Display Length\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int data;
            cout << "Enter data to insert at head: ";
            cin >> data;
            insertAtHead(tail, head, data);
            print(head);
            break;
        }
        case 2: {
            int data;
            cout << "Enter data to insert at tail: ";
            cin >> data;
            insertAtTail(tail, head, data);
            print(head);
            break;
        }
        case 3: {
            int data, pos;
            cout << "Enter position and data: ";
            cin >> pos >> data;
            insertAtPosition(tail, head, pos, data);
            print(head);
            break;
        }
        case 4: {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;
            deleteNode(pos, head);
            print(head);
            break;
        }
        case 5:
            cout << "Linked List: ";
            print(head);
            break;
        case 6:
            cout << "Length of Linked List: " << getLength(head) << endl;
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
