#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    int size_sp;
    vector<int> table_sp;

public:
    HashTable(int s_sp) {
        size_sp = s_sp;
        table_sp.assign(size_sp, -1);  
    }

    int hashFunction_sp(int key_sp) {
        return key_sp % size_sp;
    }

    void insert_sp(int key_sp) {
        int index_sp = hashFunction_sp(key_sp);
        int start_sp = index_sp;

        while (table_sp[index_sp] != -1) {   
            index_sp = (index_sp + 1) % size_sp;

            if (index_sp == start_sp) {     
                cout << "Hash table is full!\n";
                return;
            }
        }

        table_sp[index_sp] = key_sp;
        cout << "Inserted " << key_sp << " at index " << index_sp << endl;
    }

    void search_sp(int key_sp) {
        int index_sp = hashFunction_sp(key_sp);
        int start_sp = index_sp;

        while (table_sp[index_sp] != -1) {
            if (table_sp[index_sp] == key_sp) {
                cout << key_sp << " found at index " << index_sp << endl;
                return;
            }
            index_sp = (index_sp + 1) % size_sp;

            if (index_sp == start_sp) break;  
        }

        cout << key_sp << " not found!\n";
    }

    void display_sp() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size_sp; i++) {
            cout << i << " --> ";
            if (table_sp[i] == -1)
                cout << "Empty";
            else
                cout << table_sp[i];
            cout << endl;
        }
    }
};

int main() {
    int size_sp;
    cout << "Enter hash table size: ";
    cin >> size_sp;

    HashTable ht_sp(size_sp);

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
