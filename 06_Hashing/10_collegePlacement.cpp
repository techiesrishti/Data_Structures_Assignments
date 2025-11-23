#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student_sp {
    int id;
    string name;
    string company;
    float pkg;
    bool used;
    Student_sp() { id = -1; used = false; }
};

class PlacementPortal_sp {
public:
    int sz;
    vector<Student_sp> table;

    PlacementPortal_sp(int s) {
        sz = s;
        table.resize(sz);
    }

    int h1(int k) { return k % sz; }

    int h2(int k) {
        int r = 7;
        return r - (k % r);
    }

    void rehash_sp() {
        vector<Student_sp> old = table;
        sz *= 2;
        table.clear();
        table.resize(sz);
        for (auto &x : old) if (x.used) insert_sp(x.id, x.name, x.company, x.pkg);
    }

    void insert_sp(int id, string name, string comp, float pkg) {
        int i = 0;
        int idx;
        while (i < sz) {
            idx = (h1(id) + i * h2(id)) % sz;
            if (!table[idx].used) {
                table[idx].id = id;
                table[idx].name = name;
                table[idx].company = comp;
                table[idx].pkg = pkg;
                table[idx].used = true;
                return;
            }
            i++;
        }
        rehash_sp();
        insert_sp(id, name, comp, pkg);
    }

    void search_sp(int id) {
        int i = 0;
        int idx;
        while (i < sz) {
            idx = (h1(id) + i * h2(id)) % sz;
            if (table[idx].used && table[idx].id == id) {
                cout << "\nRecord Found:\n";
                cout << "ID: " << table[idx].id << "\nName: " << table[idx].name 
                     << "\nCompany: " << table[idx].company 
                     << "\nPackage: " << table[idx].pkg << "\n";
                return;
            }
            i++;
        }
        cout << "\nRecord Not Found\n";
    }

    void delete_sp(int id) {
        int i = 0;
        int idx;
        while (i < sz) {
            idx = (h1(id) + i * h2(id)) % sz;
            if (table[idx].used && table[idx].id == id) {
                table[idx].used = false;
                cout << "\nRecord Deleted\n";
                return;
            }
            i++;
        }
        cout << "\nRecord Not Found\n";
    }

    void display_sp() {
        cout << "\n--- Placement Records ---\n";
        for (int i = 0; i < sz; i++) {
            if (table[i].used) {
                cout << i << " -> ID:" << table[i].id 
                     << "  Name:" << table[i].name 
                     << "  Company:" << table[i].company
                     << "  Package:" << table[i].pkg << "\n";
            } else {
                cout << i << " -> empty\n";
            }
        }
    }
};

int main() {
    PlacementPortal_sp obj(10);
    int ch;
    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\nEnter choice: ";
        cin >> ch;
        if (ch == 1) {
            int id; string name, comp; float pkg;
            cout << "Enter ID Name Company Package: ";
            cin >> id >> name >> comp >> pkg;
            obj.insert_sp(id, name, comp, pkg);
        }
        else if (ch == 2) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            obj.search_sp(id);
        }
        else if (ch == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            obj.delete_sp(id);
        }
        else if (ch == 4) obj.display_sp();
        else if (ch == 5) break;
        else cout << "Invalid\n";
    }
}
