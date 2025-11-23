#include <iostream>
#include <vector>
using namespace std;

class HashTable_SC {
private:
    int size_sp;
    vector<vector<int>> table_sp;   

public:
    HashTable_SC(int s_sp) {
        size_sp = s_sp;
        table_sp.resize(size_sp);
    }

    int hashFunction_sp(int key_sp) {
        return key_sp % size_sp;
    }

    void insert_sp(int key_sp) {
        int index_sp = hashFunction_sp(key_sp);
        table_sp[index_sp].push_back(key_sp);
        cout << "Inserted " << key_sp << " at bucket " << index_sp << endl;
    }

    void search_sp(int key_sp) {
        int index_sp = hashFunction_sp(key_sp);

        for (int val_sp : table_sp[index_sp]) {
            if (val_sp == key_sp) {
                cout << key_sp << " found in bucket " << index_sp << endl;
                return;
            }
        }

        cout << key_sp << " not found!" << endl;
    }

    void display_sp() {
        cout << "\nHash Table (Separate Chaining):\n";
        for (int i = 0; i < size_sp; i++) {
            cout << i << " --> ";

            if (table_sp[i].empty()) {
                cout << "Empty";
            } else {
                for (int val_sp : table_sp[i]) {
                    cout << val_sp << " -> ";
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

    HashTable_SC ht_sp(size_sp);

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
