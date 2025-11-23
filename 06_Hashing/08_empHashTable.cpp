#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee_sp {
    int id_sp;
    string name_sp;
    bool occ_sp;
    Employee_sp() {
        id_sp = -1;
        name_sp = "";
        occ_sp = false;
    }
};

class HashTable_sp {
private:
    vector<Employee_sp> table_sp;
    int size_sp;

public:
    HashTable_sp(int s_sp) {
        size_sp = s_sp;
        table_sp.resize(size_sp);
    }

    int midSquareHash_sp(int key_sp) {
        long long sq_sp = (long long)key_sp * key_sp;
        string s_sp = to_string(sq_sp);
        int len_sp = s_sp.length();
        if (len_sp < 2) return key_sp % size_sp;
        int mid_sp = len_sp / 2;
        string midDigits_sp = s_sp.substr(mid_sp - 1, 2);
        int num_sp = stoi(midDigits_sp);
        return num_sp % size_sp;
    }

    void insertEmployee_sp(int id_sp, string name_sp) {
        int index_sp = midSquareHash_sp(id_sp);
        if (!table_sp[index_sp].occ_sp) {
            table_sp[index_sp].id_sp = id_sp;
            table_sp[index_sp].name_sp = name_sp;
            table_sp[index_sp].occ_sp = true;
            return;
        }

        int i_sp = (index_sp + 1) % size_sp;
        while (table_sp[i_sp].occ_sp) {
            i_sp = (i_sp + 1) % size_sp;
        }

        table_sp[i_sp].id_sp = id_sp;
        table_sp[i_sp].name_sp = name_sp;
        table_sp[i_sp].occ_sp = true;
    }

    void searchEmployee_sp(int id_sp) {
        int index_sp = midSquareHash_sp(id_sp);
        int start_sp = index_sp;

        while (table_sp[index_sp].occ_sp) {
            if (table_sp[index_sp].id_sp == id_sp) {
                cout << "\nEmployee Found:\n";
                cout << "ID: " << table_sp[index_sp].id_sp
                     << "  Name: " << table_sp[index_sp].name_sp << "\n";
                return;
            }
            index_sp = (index_sp + 1) % size_sp;
            if (index_sp == start_sp) break;
        }

        cout << "\nEmployee Not Found\n";
    }

    void displayTable_sp() {
        cout << "\n---- Employee Hash Table ----\n";
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
    cout << "Enter number of employees: ";
    cin >> n_sp;

    for (int i_sp = 0; i_sp < n_sp; i_sp++) {
        int id_sp;
        string name_sp;
        cout << "Enter ID and Name: ";
        cin >> id_sp >> name_sp;
        h_sp.insertEmployee_sp(id_sp, name_sp);
    }

    h_sp.displayTable_sp();

    int find_sp;
    cout << "\nEnter Employee ID to search: ";
    cin >> find_sp;

    h_sp.searchEmployee_sp(find_sp);

    return 0;
}
