#include <iostream>
#include <string>
using namespace std;

class Node_sp {
public:
    string name_sp;
    int marks_sp;
    Node_sp *left_sp, *right_sp;

    Node_sp(string n_sp, int m_sp) {
        name_sp = n_sp;
        marks_sp = m_sp;
        left_sp = right_sp = NULL;
    }
};

class BST_sp {
public:
    Node_sp* root_sp;
    int roll_sp; 

    BST_sp() {
        root_sp = NULL;
        roll_sp = 1;
    }

    Node_sp* insert_sp(Node_sp* node_sp, string name_sp, int marks_sp) {
        if (node_sp == NULL)
            return new Node_sp(name_sp, marks_sp);

        if (marks_sp < node_sp->marks_sp)
            node_sp->left_sp = insert_sp(node_sp->left_sp, name_sp, marks_sp);
        else
            node_sp->right_sp = insert_sp(node_sp->right_sp, name_sp, marks_sp);

        return node_sp;
    }

    void create_sp(string name_sp, int marks_sp) {
        root_sp = insert_sp(root_sp, name_sp, marks_sp);
    }

    void inorderAssign_sp(Node_sp* root_sp) {
        if (root_sp == NULL)
            return;

        inorderAssign_sp(root_sp->left_sp);

        cout << "Roll No. " << roll_sp++ << " → "
             << root_sp->name_sp << " (Marks: " << root_sp->marks_sp << ")\n";

        inorderAssign_sp(root_sp->right_sp);
    }

    
    void assignRollDescending_sp(Node_sp* root_sp) {
        if (root_sp == NULL)
            return;

        assignRollDescending_sp(root_sp->right_sp);

        cout << "Roll No. " << roll_sp++ << " -> "
             << root_sp->name_sp << " (Marks: " << root_sp->marks_sp << ")\n";

        assignRollDescending_sp(root_sp->left_sp);
    }
};

int main() {
    BST_sp bst_sp;
    int n_sp;
    string name_sp;
    int marks_sp;

    cout << "Enter number of students: ";
    cin >> n_sp;

    for (int i = 0; i < n_sp; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin >> name_sp;
        cout << "Enter marks of " << name_sp << ": ";
        cin >> marks_sp;

        bst_sp.create_sp(name_sp, marks_sp);
    }

    cout << "\n--- Roll Number Assignment Based on Marks ---\n";
    cout << "Topper gets Roll No. 1 \n\n";

    bst_sp.roll_sp = 1;  
    bst_sp.assignRollDescending_sp(bst_sp.root_sp);

    return 0;
}
