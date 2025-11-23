#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Faculty_sp {
public:
    int id_sp;
    string name_sp;
    string dept_sp;
    int next_sp;   

    Faculty_sp() {
        id_sp = -1;
        name_sp = "";
        dept_sp = "";
        next_sp = -1;
    }
};

class HashTable_sp {
private:
    int size_sp;
    vector<Faculty_sp> table_sp;

public:
    HashTable_sp(int size_sp_) {
        size_sp = size_sp_;
        table_sp.resize(size_sp);
    }

    int hashFunction_sp(int key_sp) {
        return key_sp % size_sp;
    }

    int getFreeIndex_sp() {
        for (int i_sp = 0; i_sp < size_sp; i_sp++) {
            if (table_sp[i_sp].id_sp == -1)
                return i_sp;
        }
        return -1;  
    }

    void insert_sp(int id_sp, string name_sp, string dept_sp) {
        int index_sp = hashFunction_sp(id_sp);

        if (table_sp[index_sp].id_sp == -1) {
            table_sp[index_sp].id_sp = id_sp;
            table_sp[index_sp].name_sp = name_sp;
            table_sp[index_sp].dept_sp = dept_sp;
            return;
        }

        int freeIndex_sp = getFreeIndex_sp();
        if (freeIndex_sp == -1) {
            cout << "Hash Table FULL! Cannot insert.\n";
            return;
        }
        table_sp[freeIndex_sp].id_sp = id_sp;
        table_sp[freeIndex_sp].name_sp = name_sp;
        table_sp[freeIndex_sp].dept_sp = dept_sp;

        int start_sp = index_sp;

        while (table_sp[start_sp].next_sp != -1) {
            start_sp = table_sp[start_sp].next_sp;
        }

        table_sp[start_sp].next_sp = freeIndex_sp;
    }

    void search_sp(int id_sp) {
        int index_sp = hashFunction_sp(id_sp);

        int current_sp = index_sp;

        while (current_sp != -1) {
            if (table_sp[current_sp].id_sp == id_sp) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table_sp[current_sp].id_sp << endl;
                cout << "Name: " << table_sp[current_sp].name_sp << endl;
                cout << "Department: " << table_sp[current_sp].dept_sp << endl;
                return;
            }
            current_sp = table_sp[current_sp].next_sp;
        }

        cout << "\nFaculty NOT found!\n";
    }

    void display_sp() {
        cout << "\n--- Faculty Hash Table Linear Probing with chaining ---\n\n";

        for (int i_sp = 0; i_sp < size_sp; i_sp++) {
            cout << "[" << i_sp << "]  ";
            if (table_sp[i_sp].id_sp == -1) {
                cout << "EMPTY\n";
            } else {
                cout << "ID: " << table_sp[i_sp].id_sp
                     << ", Name: " << table_sp[i_sp].name_sp
                     << ", Dept: " << table_sp[i_sp].dept_sp
                     << ", Next = " << table_sp[i_sp].next_sp << endl;
            }
        }
    }
};

int main() {
    int size_sp;
    cout << "Enter Hash Table Size: ";
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
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}
