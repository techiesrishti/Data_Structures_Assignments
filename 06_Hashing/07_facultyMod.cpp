#include <iostream>
#include <vector>
using namespace std;

struct Faculty_sp {
    int id_sp;
    string name_sp;
    bool occ_sp;
    Faculty_sp() {
        id_sp = -1;
        name_sp = "";
        occ_sp = false;
    }
};

class HashTable_sp {
private:
    vector<Faculty_sp> table_sp;
    int size_sp;

public:
    HashTable_sp(int s_sp) {
        size_sp = s_sp;
        table_sp.resize(size_sp);
    }

    int hashFunction_sp(int key_sp) {
        return key_sp % size_sp;
    }

    void insertFaculty_sp(int id_sp, string name_sp) {
        int index_sp = hashFunction_sp(id_sp);

        if (!table_sp[index_sp].occ_sp) {
            table_sp[index_sp].id_sp = id_sp;
            table_sp[index_sp].name_sp = name_sp;
            table_sp[index_sp].occ_sp = true;
            return;
        }

        int oldID_sp = table_sp[index_sp].id_sp;
        int homeOld_sp = hashFunction_sp(oldID_sp);

        if (homeOld_sp != index_sp) {
            int tempID_sp = table_sp[index_sp].id_sp;
            string tempName_sp = table_sp[index_sp].name_sp;

            table_sp[index_sp].id_sp = id_sp;
            table_sp[index_sp].name_sp = name_sp;

            id_sp = tempID_sp;
            name_sp = tempName_sp;
        }

        int i_sp = (index_sp + 1) % size_sp;
        while (table_sp[i_sp].occ_sp) {
            i_sp = (i_sp + 1) % size_sp;
        }

        table_sp[i_sp].id_sp = id_sp;
        table_sp[i_sp].name_sp = name_sp;
        table_sp[i_sp].occ_sp = true;
    }

    void searchFaculty_sp(int id_sp) {
        int index_sp = hashFunction_sp(id_sp);
        int start_sp = index_sp;

        while (table_sp[index_sp].occ_sp) {
            if (table_sp[index_sp].id_sp == id_sp) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table_sp[index_sp].id_sp 
                     << "  Name: " << table_sp[index_sp].name_sp << "\n";
                return;
            }
            index_sp = (index_sp + 1) % size_sp;
            if (index_sp == start_sp) break;
        }

        cout << "\nFaculty Not Found\n";
    }

    void displayTable_sp() {
        cout << "\n---- Faculty Hash Table ----\n";
        for (int i_sp = 0; i_sp < size_sp; i_sp++) {
            cout << i_sp << " : ";
            if (table_sp[i_sp].occ_sp)
                cout << table_sp[i_sp].id_sp << "  " << table_sp[i_sp].name_sp << "\n";
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

    int n_sp;
    cout << "Enter number of faculty: ";
    cin >> n_sp;

    for (int i_sp = 0; i_sp < n_sp; i_sp++) {
        int id_sp;
        string name_sp;
        cout << "Enter ID and Name: ";
        cin >> id_sp >> name_sp;
        h_sp.insertFaculty_sp(id_sp, name_sp);
    }

    h_sp.displayTable_sp();

    int find_sp;
    cout << "\nEnter faculty ID to search: ";
    cin >> find_sp;

    h_sp.searchFaculty_sp(find_sp);

    return 0;
}
