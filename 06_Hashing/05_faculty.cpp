#include <iostream>
#include <string>
using namespace std;

class Faculty_sp {
public:
    int id_sp;
    string name_sp;
    string dept_sp;

    Faculty_sp() {
        id_sp = -1;
        name_sp = "";
        dept_sp = "";
    }
};

class HashTable_sp {
private:
    int size_sp;
    Faculty_sp* table_sp;

public:
    HashTable_sp(int s_sp) {
        size_sp = s_sp;
        table_sp = new Faculty_sp[size_sp];
    }

    int hashFunction_sp(int key_sp) {
        return key_sp % size_sp;   // MOD hash function
    }

    void insert_sp(int id_sp, string name_sp, string dept_sp) {
        int index_sp = hashFunction_sp(id_sp);

        // Linear probing
        int start_sp = index_sp;
        while (table_sp[index_sp].id_sp != -1) {
            index_sp = (index_sp + 1) % size_sp;
            if (index_sp == start_sp) {
                cout << "Hash Table is FULL! Cannot insert.\n";
                return;
            }
        }

        table_sp[index_sp].id_sp = id_sp;
        table_sp[index_sp].name_sp = name_sp;
        table_sp[index_sp].dept_sp = dept_sp;

        cout << "Inserted at index " << index_sp << endl;
    }

    void search_sp(int id_sp) {
        int index_sp = hashFunction_sp(id_sp);

        int start_sp = index_sp;
        while (table_sp[index_sp].id_sp != -1) {
            if (table_sp[index_sp].id_sp == id_sp) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table_sp[index_sp].id_sp << endl;
                cout << "Name: " << table_sp[index_sp].name_sp << endl;
                cout << "Department: " << table_sp[index_sp].dept_sp << endl;
                return;
            }
            index_sp = (index_sp + 1) % size_sp;

            if (index_sp == start_sp) break;
        }

        cout << "\nFaculty NOT found!\n";
    }

    void display_sp() {
        cout << "\n--- Faculty Hash Table ---\n";
        for (int i_sp = 0; i_sp < size_sp; i_sp++) {
            cout << i_sp << ": ";
            if (table_sp[i_sp].id_sp == -1) {
                cout << "Empty\n";
            } else {
                cout << "[ID: " << table_sp[i_sp].id_sp 
                     << ", Name: " << table_sp[i_sp].name_sp
                     << ", Dept: " << table_sp[i_sp].dept_sp << "]\n";
            }
        }
    }
};

int main() {
    int size_sp;
    cout << "Enter hash table size: ";
    cin >> size_sp;

    HashTable_sp ht_sp(size_sp);

    int choice_sp;

    while (true) {
        cout << "\n1. Insert Faculty\n2. Search Faculty\n3. Display Table\n4. Exit\nEnter choice: ";
        cin >> choice_sp;

        if (choice_sp == 1) {
            int id_sp;
            string name_sp, dept_sp;

            cout << "Enter Faculty ID: ";
            cin >> id_sp;
            cout << "Enter Name: ";
            cin >> name_sp;
            cout << "Enter Department: ";
            cin >> dept_sp;

            ht_sp.insert_sp(id_sp, name_sp, dept_sp);
        }
        else if (choice_sp == 2) {
            int id_sp;
            cout << "Enter Faculty ID to search: ";
            cin >> id_sp;

            ht_sp.search_sp(id_sp);
        }
        else if (choice_sp == 3) {
            ht_sp.display_sp();
        }
        else if (choice_sp == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
