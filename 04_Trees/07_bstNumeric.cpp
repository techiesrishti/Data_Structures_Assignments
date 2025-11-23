#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
#include<string>
using namespace std;

class Node_sp {
public:
    int key_sp;
    Node_sp *left_sp, *right_sp;

    Node_sp(int value_sp) {
        key_sp = value_sp;
        left_sp = right_sp = NULL;
    }
};

class BST_sp {
public:
    Node_sp *root_sp;

    BST_sp() { root_sp = NULL; }

    Node_sp* insert_sp(Node_sp* node_sp, int value_sp) {
        if (node_sp == NULL)
            return new Node_sp(value_sp);

        if (value_sp < node_sp->key_sp)
            node_sp->left_sp = insert_sp(node_sp->left_sp, value_sp);
        else if (value_sp > node_sp->key_sp)
            node_sp->right_sp = insert_sp(node_sp->right_sp, value_sp);
        return node_sp;
    }

    void create_sp(int value_sp) {
        root_sp = insert_sp(root_sp, value_sp);
    }

    Node_sp* findMin_sp(Node_sp* node_sp) {
        while (node_sp && node_sp->left_sp)
            node_sp = node_sp->left_sp;
        return node_sp;
    }

    Node_sp* delete_sp(Node_sp* node_sp, int value_sp) {
        if (node_sp == NULL) {
            cout << "Key not found!\n";
            return node_sp;
        }

        if (value_sp < node_sp->key_sp)
            node_sp->left_sp = delete_sp(node_sp->left_sp, value_sp);
        else if (value_sp > node_sp->key_sp)
            node_sp->right_sp = delete_sp(node_sp->right_sp, value_sp);
        else {
            if (!node_sp->left_sp) {
                Node_sp* temp = node_sp->right_sp;
                delete node_sp;
                return temp;
            }
            if (!node_sp->right_sp) {
                Node_sp* temp = node_sp->left_sp;
                delete node_sp;
                return temp;
            }
            Node_sp* temp = findMin_sp(node_sp->right_sp);
            node_sp->key_sp = temp->key_sp;
            node_sp->right_sp = delete_sp(node_sp->right_sp, temp->key_sp);
        }
        return node_sp;
    }

    bool find_sp(Node_sp* node_sp, int value_sp) {
        if (node_sp == NULL)
            return false;
        if (node_sp->key_sp == value_sp)
            return true;
        if (value_sp < node_sp->key_sp)
            return find_sp(node_sp->left_sp, value_sp);
        return find_sp(node_sp->right_sp, value_sp);
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

                cout << setw(spaceBetween_sp) << (curr_sp ? to_string(curr_sp->key_sp) : " ");

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
    BST_sp tree_sp;
    int choice_sp, value_sp;

    while (true) {
        cout << "\n-----------MENU---------------";
        cout << "\n1. Insert Node";
        cout << "\n2. Delete Node";
        cout << "\n3. Find Node";
        cout << "\n4. Display BST";
        cout << "\n5. Exit";
        cout << "\n------------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "Enter numeric key to insert: ";
                cin >> value_sp;
                tree_sp.create_sp(value_sp);
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> value_sp;
                tree_sp.root_sp = tree_sp.delete_sp(tree_sp.root_sp, value_sp);
                break;

            case 3:
                cout << "Enter key to find: ";
                cin >> value_sp;
                if (tree_sp.find_sp(tree_sp.root_sp, value_sp))
                    cout << "Key found in BST.\n";
                else
                    cout << "Key not found.\n";
                break;

            case 4:
                cout << "\nBinary Search Tree (Horizontal View):\n\n";
                tree_sp.display_sp(tree_sp.root_sp);
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
