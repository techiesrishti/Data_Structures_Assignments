#include <iostream>
#include <cmath>
#include <queue>
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

class BST_sp {
private:
    Node_sp* root_sp;

    Node_sp* insert_sp(Node_sp* node_sp, int val_sp) {
        if (node_sp == NULL)
            return new Node_sp(val_sp);

        if (val_sp < node_sp->data_sp)
            node_sp->left_sp = insert_sp(node_sp->left_sp, val_sp);
        else if (val_sp > node_sp->data_sp)
            node_sp->right_sp = insert_sp(node_sp->right_sp, val_sp);

        return node_sp;
    }

    int countNodes_sp(Node_sp* node_sp) {
        if (node_sp == NULL)
            return 0;
        return 1 + countNodes_sp(node_sp->left_sp) + countNodes_sp(node_sp->right_sp);
    }

    int height_sp(Node_sp* node_sp) {
        if (node_sp == NULL)
            return 0;
        return 1 + max(height_sp(node_sp->left_sp), height_sp(node_sp->right_sp));
    }

    void mirror_sp(Node_sp* node_sp) {
        if (node_sp == NULL)
            return;
        Node_sp* temp_sp = node_sp->left_sp;
        node_sp->left_sp = node_sp->right_sp;
        node_sp->right_sp = temp_sp;
        mirror_sp(node_sp->left_sp);
        mirror_sp(node_sp->right_sp);
    }

    void displayTree_sp(Node_sp* root_sp) {
        if (!root_sp) {
            cout << "Tree is empty!\n";
            return;
        }

        int h_sp = height_sp(root_sp);
        int maxNodes_sp = pow(2, h_sp) - 1;
        int width_sp = maxNodes_sp * 3;

        queue<Node_sp*> q_sp;
        q_sp.push(root_sp);
        int level_sp = 0;

        while (!q_sp.empty()) {
            int n_sp = q_sp.size();
            int space_sp = width_sp / pow(2, level_sp + 1);

            for (int i_sp = 0; i_sp < n_sp; i_sp++) {
                Node_sp* curr_sp = q_sp.front();
                q_sp.pop();

                if (curr_sp) {
                    cout << setw(space_sp) << curr_sp->data_sp;
                    q_sp.push(curr_sp->left_sp);
                    q_sp.push(curr_sp->right_sp);
                } else {
                    cout << setw(space_sp) << " ";
                    q_sp.push(NULL);
                    q_sp.push(NULL);
                }
                cout << setw(space_sp) << " ";
            }
            cout << "\n";
            level_sp++;

            if (level_sp == h_sp)
                break;
        }
    }

public:
    BST_sp() {
        root_sp = NULL;
    }

    void insertNode_sp(int val_sp) {
        root_sp = insert_sp(root_sp, val_sp);
    }

    void displayTree_sp() {
        displayTree_sp(root_sp);
    }

    void countTotalNodes_sp() {
        cout << "Total no of nodes: " << countNodes_sp(root_sp) << endl;
    }

    void computeHeight_sp() {
        cout << "Height of BST: " << height_sp(root_sp) << endl;
    }

    void mirrorImage_sp() {
        mirror_sp(root_sp);
        cout << "Mirror image created successfully \n";
    }
};

int main() {
    BST_sp tree_sp;
    int choice_sp, val_sp;

    do {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Tree \n";
        cout << "3. Count Total Nodes\n";
        cout << "4. Compute Height of BST\n";
        cout << "5. Mirror Image of BST\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val_sp;
                tree_sp.insertNode_sp(val_sp);
                break;

            case 2:
                cout << "\nTree structure:\n";
                tree_sp.displayTree_sp();
                break;

            case 3:
                tree_sp.countTotalNodes_sp();
                break;

            case 4:
                tree_sp.computeHeight_sp();
                break;

            case 5:
                tree_sp.mirrorImage_sp();
                cout << "\nTree after mirror img:  \n";
                tree_sp.displayTree_sp();
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice \n";
        }

    } while (choice_sp != 6);

    return 0;
}
