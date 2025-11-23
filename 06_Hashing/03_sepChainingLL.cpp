#include <iostream>
using namespace std;

// Node for linked list
class Node_sp {
public:
    int data_sp;
    Node_sp* next_sp;

    Node_sp(int value_sp) {
        data_sp = value_sp;
        next_sp = nullptr;
    }
};

class HashTable_sp {
private:
    int size_sp;
    Node_sp** table_sp;   // array of linked list heads

public:
    HashTable_sp(int s_sp) {
        size_sp = s_sp;
        table_sp = new Node_sp*[size_sp];

        for (int i = 0; i < size_sp; i++)
            table_sp[i] = nullptr;
    }

    // Hash function
    int hashFunction_sp(int key_sp) {
        return key_sp % size_sp;
    }

    // Insert key into linked list
    void insert_sp(int key_sp) {
        int index_sp = hashFunction_sp(key_sp);
        Node_sp* newNode_sp = new Node_sp(key_sp);

        // Insert at beginning of linked list
        newNode_sp->next_sp = table_sp[index_sp];
        table_sp[index_sp] = newNode_sp;

        cout << "Inserted " << key_sp << " at bucket " << index_sp << endl;
    }

    // Search for a key
    void search_sp(int key_sp) {
        int index_sp = hashFunction_sp(key_sp);
        Node_sp* temp_sp = table_sp[index_sp];

        while (temp_sp != nullptr) {
            if (temp_sp->data_sp == key_sp) {
                cout << key_sp << " found in bucket " << index_sp << endl;
                return;
            }
            temp_sp = temp_sp->next_sp;
        }

        cout << key_sp << " not found!" << endl;
    }

    // Display hash table
    void display_sp() {
        cout << "\nHash Table (Separate Chaining using Linked Lists):\n";
        for (int i = 0; i < size_sp; i++) {
            cout << i << " --> ";

            Node_sp* temp_sp = table_sp[i];
            if (temp_sp == nullptr) {
                cout << "Empty";
            } else {
                while (temp_sp != nullptr) {
                    cout << temp_sp->data_sp << " -> ";
                    temp_sp = temp_sp->next_sp;
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

int main() {
    int size_sp;
    cout << "Enter hash table size: ";
    cin >> size_sp;

    HashTable_sp ht_sp(size_sp);

    int choice_sp, key_sp;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key_sp;
                ht_sp.insert_sp(key_sp);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key_sp;
                ht_sp.search_sp(key_sp);
                break;

            case 3:
                ht_sp.display_sp();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
