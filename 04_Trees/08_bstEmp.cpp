#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

class Employee_sp {
public:
    int emp_id_sp;
    string name_sp;
    float salary_sp;

    Employee_sp(int id_sp = 0, string name_sp = "", float sal_sp = 0.0) {
        this->emp_id_sp = id_sp;
        this->name_sp = name_sp;
        this->salary_sp = sal_sp;
    }
};

class Node_sp {
public:
    Employee_sp emp_sp;
    Node_sp *left_sp, *right_sp;

    Node_sp(Employee_sp e_sp) {
        emp_sp = e_sp;
        left_sp = right_sp = NULL;
    }
};

class EmployeeBST_sp {
public:
    Node_sp *root_sp;

    EmployeeBST_sp() { root_sp = NULL; }

    Node_sp* insert_sp(Node_sp* node_sp, Employee_sp emp_sp) {
        if (node_sp == NULL)
            return new Node_sp(emp_sp);

        if (emp_sp.emp_id_sp < node_sp->emp_sp.emp_id_sp)
            node_sp->left_sp = insert_sp(node_sp->left_sp, emp_sp);
        else if (emp_sp.emp_id_sp > node_sp->emp_sp.emp_id_sp)
            node_sp->right_sp = insert_sp(node_sp->right_sp, emp_sp);
        else
            cout << "Duplicate Employee ID not allowed!\n";

        return node_sp;
    }

    void create_sp(Employee_sp emp_sp) {
        root_sp = insert_sp(root_sp, emp_sp);
    }

    Node_sp* search_sp(Node_sp* node_sp, int id_sp) {
        if (node_sp == NULL || node_sp->emp_sp.emp_id_sp == id_sp)
            return node_sp;

        if (id_sp < node_sp->emp_sp.emp_id_sp)
            return search_sp(node_sp->left_sp, id_sp);
        else
            return search_sp(node_sp->right_sp, id_sp);
    }

    void inorder_sp(Node_sp* node_sp) {
        if (node_sp == NULL)
            return;

        inorder_sp(node_sp->left_sp);
        cout << "EmpID: " << node_sp->emp_sp.emp_id_sp
             << " | Name: " << node_sp->emp_sp.name_sp
             << " | Salary: " << node_sp->emp_sp.salary_sp << endl;
        inorder_sp(node_sp->right_sp);
    }

    int height_sp(Node_sp* node_sp) {
        if (!node_sp) return 0;
        return 1 + max(height_sp(node_sp->left_sp), height_sp(node_sp->right_sp));
    }

    void display_sp(Node_sp* root_sp) {
        if (!root_sp) {
            cout << "Tree is empty!\n";
            return;
        }

        int h_sp = height_sp(root_sp);
        int maxNodes_sp = pow(2, h_sp) - 1;
        int maxWidth_sp = 6 * maxNodes_sp;

        queue<Node_sp*> q_sp;
        q_sp.push(root_sp);

        for (int level_sp = 0; level_sp < h_sp; level_sp++) {
            int levelCount_sp = q_sp.size();
            int spaceBetween_sp = maxWidth_sp / (levelCount_sp + 1);

            for (int i = 0; i < levelCount_sp; i++) {
                Node_sp* curr_sp = q_sp.front();
                q_sp.pop();

                if (curr_sp)
                    cout << setw(spaceBetween_sp) << curr_sp->emp_sp.emp_id_sp;
                else
                    cout << setw(spaceBetween_sp) << " ";

                if (curr_sp) {
                    q_sp.push(curr_sp->left_sp);
                    q_sp.push(curr_sp->right_sp);
                } else {
                    q_sp.push(NULL);
                    q_sp.push(NULL);
                }
            }
            cout << "\n\n";
        }
    }
};

int main() {
    EmployeeBST_sp bst_sp;
    int choice_sp;

    while (true) {
        cout << "\n-----------MENU---------------";
        cout << "\n1. Insert Employee Record";
        cout << "\n2. Search Employee by ID";
        cout << "\n3. Display All Employees (Sorted by ID)";
        cout << "\n4. Display Tree ";
        cout << "\n5. Exit";
        cout << "\n------------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1: {
                Employee_sp emp_sp;
                cout << "Enter Employee ID: ";
                cin >> emp_sp.emp_id_sp;
                cout << "Enter Employee Name: ";
                cin >> emp_sp.name_sp;
                cout << "Enter Salary: ";
                cin >> emp_sp.salary_sp;
                bst_sp.create_sp(emp_sp);
                break;
            }
            case 2: {
                int id_sp;
                cout << "Enter Employee ID to search: ";
                cin >> id_sp;
                Node_sp* res_sp = bst_sp.search_sp(bst_sp.root_sp, id_sp);
                if (res_sp)
                    cout << "Employee Found -> ID: " << res_sp->emp_sp.emp_id_sp
                         << ", Name: " << res_sp->emp_sp.name_sp
                         << ", Salary: " << res_sp->emp_sp.salary_sp << endl;
                else
                    cout << "Employee not found!\n";
                break;
            }
            case 3:
                cout << "\nEmployees (Sorted by ID):\n";
                bst_sp.inorder_sp(bst_sp.root_sp);
                break;

            case 4:
                cout << "\nEmployee BST :\n\n";
                bst_sp.display_sp(bst_sp.root_sp);
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
