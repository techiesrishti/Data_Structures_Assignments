#include <iostream>
#include <string>
using namespace std;

class Student_sp {
public:
    int roll_sp;
    string name_sp;
    float marks_sp;

    Student_sp(int r_sp, string n_sp, float m_sp) {
        roll_sp = r_sp;
        name_sp = n_sp;
        marks_sp = m_sp;
    }
};

class Node_sp {
public:
    Student_sp* data_sp;
    Node_sp* next_sp;

    Node_sp(Student_sp* s_sp) {
        data_sp = s_sp;
        next_sp = nullptr;
    }
};

class HashTable_sp {
private:
    int size_sp;
    Node_sp** table_sp;

public:
    HashTable_sp(int s_sp) {
        size_sp = s_sp;
        table_sp = new Node_sp*[size_sp];

        for (int i_sp = 0; i_sp < size_sp; i_sp++)
            table_sp[i_sp] = nullptr;
    }

    int hashFunction_sp(int roll_sp) {
        return roll_sp % size_sp;
    }

    // Insert student record
    void insert_sp(int roll_sp, string name_sp, float marks_sp) {
        int index_sp = hashFunction_sp(roll_sp);

        Student_sp* stu_sp = new Student_sp(roll_sp, name_sp, marks_sp);
        Node_sp* newNode_sp = new Node_sp(stu_sp);

        newNode_sp->next_sp = table_sp[index_sp];
        table_sp[index_sp] = newNode_sp;

        cout << "Inserted roll " << roll_sp << " at bucket " << index_sp << endl;
    }

    // Search for student by roll number
    void search_sp(int roll_sp) {
        int index_sp = hashFunction_sp(roll_sp);
        Node_sp* temp_sp = table_sp[index_sp];

        while (temp_sp != nullptr) {
            if (temp_sp->data_sp->roll_sp == roll_sp) {
                cout << "\nRecord Found:\n";
                cout << "Roll: " << temp_sp->data_sp->roll_sp << endl;
                cout << "Name: " << temp_sp->data_sp->name_sp << endl;
                cout << "Marks: " << temp_sp->data_sp->marks_sp << endl;
                return;
            }
            temp_sp = temp_sp->next_sp;
        }
        cout << "\nRecord NOT FOUND!\n";
    }

    // Display hash table
    void display_sp() {
        cout << "\nHash Table (Student Records):\n";

        for (int i_sp = 0; i_sp < size_sp; i_sp++) {
            cout << i_sp << " --> ";
            Node_sp* temp_sp = table_sp[i_sp];

            if (temp_sp == nullptr) {
                cout << "Empty";
            } else {
                while (temp_sp != nullptr) {
                    cout << "[Roll: " << temp_sp->data_sp->roll_sp
                         << ", Name: " << temp_sp->data_sp->name_sp
                         << ", Marks: " << temp_sp->data_sp->marks_sp
                         << "] -> ";
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

    int choice_sp;

    while (true) {
        cout << "\n1. Insert Student\n2. Search Student\n3. Display Table\n4. Exit\nEnter choice: ";
        cin >> choice_sp;

        if (choice_sp == 1) {
            int roll_sp;
            string name_sp;
            float marks_sp;

            cout << "Enter Roll Number: ";
            cin >> roll_sp;
            cout << "Enter Name: ";
            cin >> name_sp;
            cout << "Enter Marks: ";
            cin >> marks_sp;

            ht_sp.insert_sp(roll_sp, name_sp, marks_sp);
        }
        else if (choice_sp == 2) {
            int roll_sp;
            cout << "Enter Roll Number to search: ";
            cin >> roll_sp;

            ht_sp.search_sp(roll_sp);
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
