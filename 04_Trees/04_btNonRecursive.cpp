#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

class Node_sp {
public:
    int data_sp;
    Node_sp *left_sp, *right_sp;

    Node_sp(int val_sp) {
        data_sp = val_sp;
        left_sp = right_sp = NULL;
    }
};

class BinaryTree_sp {
public:
    Node_sp* root_sp;

    BinaryTree_sp() {
        root_sp = NULL;
    }

    Node_sp* insert_sp(Node_sp* node_sp, int val_sp) {
        if (node_sp == NULL) {
            return new Node_sp(val_sp);
        }
        if (val_sp < node_sp->data_sp)
            node_sp->left_sp = insert_sp(node_sp->left_sp, val_sp);
        else
            node_sp->right_sp = insert_sp(node_sp->right_sp, val_sp);
        return node_sp;
    }

    void create_sp(int val_sp) {
        root_sp = insert_sp(root_sp, val_sp);
    }

    void inorderNonRec_sp(Node_sp* root_sp) {
        stack<Node_sp*> st_sp;
        Node_sp* curr_sp = root_sp;
        cout << "Inorder Traversal: ";
        while (curr_sp != NULL || !st_sp.empty()) {
            while (curr_sp != NULL) {
                st_sp.push(curr_sp);
                curr_sp = curr_sp->left_sp;
            }
            curr_sp = st_sp.top();
            st_sp.pop();
            cout << curr_sp->data_sp << " ";
            curr_sp = curr_sp->right_sp;
        }
        cout << endl;
    }

    void preorderNonRec_sp(Node_sp* root_sp) {
        if (root_sp == NULL) return;
        stack<Node_sp*> st_sp;
        st_sp.push(root_sp);
        cout << "Preorder Traversal: ";
        while (!st_sp.empty()) {
            Node_sp* curr_sp = st_sp.top();
            st_sp.pop();
            cout << curr_sp->data_sp << " ";
            if (curr_sp->right_sp) st_sp.push(curr_sp->right_sp);
            if (curr_sp->left_sp) st_sp.push(curr_sp->left_sp);
        }
        cout << endl;
    }

    int countLeafNodes_sp(Node_sp* root_sp) {
        if (root_sp == NULL) return 0;
        if (root_sp->left_sp == NULL && root_sp->right_sp == NULL) return 1;
        return countLeafNodes_sp(root_sp->left_sp) + countLeafNodes_sp(root_sp->right_sp);
    }

    Node_sp* mirror_sp(Node_sp* node_sp) {
        if (node_sp == NULL) return NULL;
        Node_sp* temp_sp = node_sp->left_sp;
        node_sp->left_sp = mirror_sp(node_sp->right_sp);
        node_sp->right_sp = mirror_sp(temp_sp);
        return node_sp;
    }

    int height_sp(Node_sp* node_sp) {
        if (node_sp == NULL) return 0;
        return 1 + max(height_sp(node_sp->left_sp), height_sp(node_sp->right_sp));
    }

    void display_sp(Node_sp* root_sp) {
        if (root_sp == NULL) return;

        int h_sp = height_sp(root_sp);
        int maxNodes_sp = pow(2, h_sp) - 1;
        queue<Node_sp*> q_sp;
        q_sp.push(root_sp);

        int level_sp = 1;
        while (level_sp <= h_sp) {
            int count_sp = pow(2, level_sp - 1);
            int spaces_sp = pow(2, h_sp - level_sp + 1) - 1;

            for (int i = 0; i < count_sp; i++) {
                Node_sp* curr_sp = q_sp.front();
                q_sp.pop();

                if (i == 0)
                    cout << setw(spaces_sp * 2) << ""; 
                else
                    cout << setw(spaces_sp * 4) << ""; 

                if (curr_sp) {
                    cout << curr_sp->data_sp;
                    q_sp.push(curr_sp->left_sp);
                    q_sp.push(curr_sp->right_sp);
                } else {
                    cout << " ";
                    q_sp.push(NULL);
                    q_sp.push(NULL);
                }
            }
            cout << endl << endl;
            level_sp++;
        }
    }
};

int main() {
    BinaryTree_sp bt_sp;
    int choice_sp, val_sp;

    while (true) {
        cout << "\n---------- MENU ----------";
        cout << "\n1. Insert Node";
        cout << "\n2. Inorder Traversal (Non-Recursive)";
        cout << "\n3. Preorder Traversal (Non-Recursive)";
        cout << "\n4. Count Leaf Nodes";
        cout << "\n5. Mirror Image";
        cout << "\n6. Display Tree (Pyramid format)";
        cout << "\n7. Exit";
        cout << "\n---------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "Enter value: ";
                cin >> val_sp;
                bt_sp.create_sp(val_sp);
                break;
            case 2:
                bt_sp.inorderNonRec_sp(bt_sp.root_sp);
                break;
            case 3:
                bt_sp.preorderNonRec_sp(bt_sp.root_sp);
                break;
            case 4:
                cout << "No of leaf nodes: " << bt_sp.countLeafNodes_sp(bt_sp.root_sp) << endl;
                break;
            case 5:
                bt_sp.root_sp = bt_sp.mirror_sp(bt_sp.root_sp);
                cout << "Mirror image created successfully.\n";
                bt_sp.display_sp(bt_sp.root_sp);
                break;
            case 6:
                cout << "\nTree Display:\n\n";
                bt_sp.display_sp(bt_sp.root_sp);
                break;
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
