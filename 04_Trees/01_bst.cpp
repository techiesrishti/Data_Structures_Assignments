#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

class Node_sp {
public:
    int data_sp;
    Node_sp *left_sp, *right_sp;
    Node_sp(int value_sp) {
        data_sp = value_sp;
        left_sp = right_sp = NULL;
    }
};

class BST_sp {
    Node_sp* root_sp;

    Node_sp* insertNode_sp(Node_sp* node_sp, int value_sp) {
        if (node_sp == NULL)
            return new Node_sp(value_sp);
        if (value_sp < node_sp->data_sp)
            node_sp->left_sp = insertNode_sp(node_sp->left_sp, value_sp);
        else if (value_sp > node_sp->data_sp)
            node_sp->right_sp = insertNode_sp(node_sp->right_sp, value_sp);
        return node_sp;
    }

    Node_sp* findMin_sp(Node_sp* node_sp) {
        while (node_sp && node_sp->left_sp)
            node_sp = node_sp->left_sp;
        return node_sp;
    }

    Node_sp* deleteNode_sp(Node_sp* node_sp, int value_sp) {
        if (!node_sp) return node_sp;
        if (value_sp < node_sp->data_sp)
            node_sp->left_sp = deleteNode_sp(node_sp->left_sp, value_sp);
        else if (value_sp > node_sp->data_sp)
            node_sp->right_sp = deleteNode_sp(node_sp->right_sp, value_sp);
        else {
            if (!node_sp->left_sp) {
                Node_sp* temp_sp = node_sp->right_sp;
                delete node_sp;
                return temp_sp;
            } else if (!node_sp->right_sp) {
                Node_sp* temp_sp = node_sp->left_sp;
                delete node_sp;
                return temp_sp;
            }
            Node_sp* temp_sp = findMin_sp(node_sp->right_sp);
            node_sp->data_sp = temp_sp->data_sp;
            node_sp->right_sp = deleteNode_sp(node_sp->right_sp, temp_sp->data_sp);
        }
        return node_sp;
    }

    int height_sp(Node_sp* node_sp) {
        if (!node_sp) return 0;
        return 1 + max(height_sp(node_sp->left_sp), height_sp(node_sp->right_sp));
    }

public:
    BST_sp() { root_sp = NULL; }

    void insert_sp(int value_sp) { root_sp = insertNode_sp(root_sp, value_sp); }

    void deleteValue_sp(int value_sp) { root_sp = deleteNode_sp(root_sp, value_sp); }

    void displayTree_sp() {
        if (!root_sp) {
            cout << "Tree is empty!\n";
            return;
        }

        int h_sp = height_sp(root_sp);
        int maxNodes_sp = pow(2, h_sp) - 1;
        int spacing_sp = 3;

        queue<Node_sp*> q_sp;
        q_sp.push(root_sp);

        for (int level_sp = 1; level_sp <= h_sp; level_sp++) {
            int levelNodes_sp = pow(2, level_sp - 1);
            int spaceBetween_sp = spacing_sp * pow(2, h_sp - level_sp);

            cout << setw(spaceBetween_sp);

            queue<Node_sp*> temp_sp;

            while (!q_sp.empty()) {
                Node_sp* curr_sp = q_sp.front();
                q_sp.pop();

                if (curr_sp) {
                    cout << curr_sp->data_sp;
                    temp_sp.push(curr_sp->left_sp);
                    temp_sp.push(curr_sp->right_sp);
                } else {
                    cout << " ";
                    temp_sp.push(NULL);
                    temp_sp.push(NULL);
                }

                cout << setw(spaceBetween_sp * 2);
            }

            cout << "\n\n";
            q_sp = temp_sp;
        }
    }
};

int main() {
    BST_sp tree_sp;
    int choice_sp, value_sp;

    do {
        cout << "\n--- Binary Search Tree Operations ---";
        cout << "\n1. Insert Node";
        cout << "\n2. Delete Node";
        cout << "\n3. Display Tree (Tree Format)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value_sp;
                tree_sp.insert_sp(value_sp);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value_sp;
                tree_sp.deleteValue_sp(value_sp);
                break;

            case 3:
                tree_sp.displayTree_sp();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice_sp != 4);

    return 0;
}
