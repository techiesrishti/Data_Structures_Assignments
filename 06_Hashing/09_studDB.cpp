#include <iostream>
#include <vector>
using namespace std;

struct Student_sp {
    int roll_sp;
    string name_sp;
    bool occ_sp;
    bool del_sp;
    Student_sp() {
        roll_sp = -1;
        name_sp = "";
        occ_sp = false;
        del_sp = false;
    }
};

class HashTable_sp {
private:
    vector<Student_sp> table_sp;
    int size_sp;

public:
    HashTable_sp(int s_sp) {
        size_sp = s_sp;
        table_sp.resize(size_sp);
    }

    int hashFunc_sp(int key_sp) {
        return key_sp % size_sp;
    }

    void insertStudent_sp(int roll_sp, string name_sp) {
        int index_sp = hashFunc_sp(roll_sp);

        if (!table_sp[index_sp].occ_sp || table_sp[index_sp].del_sp) {
            table_sp[index_sp].roll_sp = roll_sp;
            table_sp[index_sp].name_sp = name_sp;
            table_sp[index_sp].occ_sp = true;
            table_sp[index_sp].del_sp = false;
            return;
        }

        int i_sp = (index_sp + 1) % size_sp;
        while (table_sp[i_sp].occ_sp && !table_sp[i_sp].del_sp) {
            i_sp = (i_sp + 1) % size_sp;
        }

        table_sp[i_sp].roll_sp = roll_sp;
        table_sp[i_sp].name_sp = name_sp;
        table_sp[i_sp].occ_sp = true;
        table_sp[i_sp].del_sp = false;
    }

    void searchStudent_sp(int roll_sp) {
        int index_sp = hashFunc_sp(roll_sp);
        int start_sp = index_sp;

        while (table_sp[index_sp].occ_sp || table_sp[index_sp].del_sp) {
            if (table_sp[index_sp].roll_sp == roll_sp && !table_sp[index_sp].del_sp) {
                cout << "\nStudent Found:\n";
                cout << "Roll: " << table_sp[index_sp].roll_sp 
                     << "  Name: " << table_sp[index_sp].name_sp << "\n";
                return;
            }
            index_sp = (index_sp + 1) % size_sp;
            if (index_sp == start_sp) break;
        }

        cout << "\nStudent Not Found\n";
    }

    void deleteStudent_sp(int roll_sp) {
        int index_sp = hashFunc_sp(roll_sp);
        int start_sp = index_sp;

        while (table_sp[index_sp].occ_sp || table_sp[index_sp].del_sp) {
            if (table_sp[index_sp].roll_sp == roll_sp && !table_sp[index_sp].del_sp) {
                table_sp[index_sp].del_sp = true;
                cout << "\nStudent Deleted\n";
                return;
            }
            index_sp = (index_sp + 1) % size_sp;
            if (index_sp == start_sp) break;
        }

        cout << "\nStudent Not Found\n";
    }

    void displayTable_sp() {
        cout << "\n---- Student Hash Table ----\n";
        for (int i_sp = 0; i_sp < size_sp; i_sp++) {
            cout << i_sp << " : ";
            if (table_sp[i_sp].occ_sp && !table_sp[i_sp].del_sp)
                cout << table_sp[i_sp].roll_sp << "  " << table_sp[i_sp].name_sp << "\n";
            else
                cout << "empty\n";
        }
    }
};

int main() {
    int size_sp;
    cout << "Enter table size: ";
    cin >> size_sp;

    HashTable_sp h_sp(size_sp);

    int choice_sp;
    do {
        cout << "\n1. Insert Student\n2. Search Student\n3. Delete Student\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice_sp;

        if (choice_sp == 1) {
            int r_sp;
            string n_sp;
            cout << "Enter roll and name: ";
            cin >> r_sp >> n_sp;
            h_sp.insertStudent_sp(r_sp, n_sp);
        }
        else if (choice_sp == 2) {
            int r_sp;
            cout << "Enter roll to search: ";
            cin >> r_sp;
            h_sp.searchStudent_sp(r_sp);
        }
        else if (choice_sp == 3) {
            int r_sp;
            cout << "Enter roll to delete: ";
            cin >> r_sp;
            h_sp.deleteStudent_sp(r_sp);
        }
        else if (choice_sp == 4) {
            h_sp.displayTable_sp();
        }

    } while (choice_sp != 5);

    return 0;
}
