#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>
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

class BT_sp {
public:
    Node_sp *root_sp;
    BT_sp() {
        root_sp = NULL;
    }

    Node_sp* insert_sp(Node_sp* node_sp, int value_sp) {
        if (node_sp == NULL)
            return new Node_sp(value_sp);

        char dir_sp;
        cout << "Insert " << value_sp << " to Left (L) or Right (R) of " << node_sp->data_sp << "? ";
        cin >> dir_sp;

        if (dir_sp == 'L' || dir_sp == 'l')
            node_sp->left_sp = insert_sp(node_sp->left_sp, value_sp);
        else
            node_sp->right_sp = insert_sp(node_sp->right_sp, value_sp);

        return node_sp;
    }

    void create_sp(int value_sp) {
        if (root_sp == NULL)
            root_sp = new Node_sp(value_sp);
        else
            insert_sp(root_sp, value_sp);
    }

    void inorder_sp(Node_sp* root_sp) {
        if (root_sp == NULL) return;
        inorder_sp(root_sp->left_sp);
        cout << root_sp->data_sp << " ";
        inorder_sp(root_sp->right_sp);
    }

    void preorder_sp(Node_sp* root_sp) {
        if (root_sp == NULL) return;
        cout << root_sp->data_sp << " ";
        preorder_sp(root_sp->left_sp);
        preorder_sp(root_sp->right_sp);
    }

    int countLeaf_sp(Node_sp* root_sp) {
        if (root_sp == NULL)
            return 0;
        if (root_sp->left_sp == NULL && root_sp->right_sp == NULL)
            return 1;
        return countLeaf_sp(root_sp->left_sp) + countLeaf_sp(root_sp->right_sp);
    }

    Node_sp* mirror_sp(Node_sp* node_sp) {
        if (node_sp == NULL)
            return NULL;
        Node_sp* temp_sp = node_sp->left_sp;
        node_sp->left_sp = mirror_sp(node_sp->right_sp);
        node_sp->right_sp = mirror_sp(temp_sp);
        return node_sp;
    }

    int height_sp(Node_sp* root_sp) {
        if (root_sp == NULL)
            return 0;
        return 1 + max(height_sp(root_sp->left_sp), height_sp(root_sp->right_sp));
    }

    void displayTree_sp(Node_sp* root_sp) {
        if (!root_sp) return;
        int h_sp = height_sp(root_sp);
        int maxNodes_sp = pow(2, h_sp) - 1;

        queue<Node_sp*> q_sp;
        q_sp.push(root_sp);

        int level_sp = 1;
        int space_sp = 6 * (h_sp - 1); 

        while (!q_sp.empty() && level_sp <= h_sp) {
            int levelNodes_sp = pow(2, level_sp - 1);
            int count_sp = q_sp.size();

            for (int i = 0; i < space_sp; i++) cout << " ";

            
            for (int i = 0; i < count_sp; i++) {
                Node_sp* node_sp = q_sp.front();
                q_sp.pop();

                if (node_sp) {
                    cout << setw(2) << node_sp->data_sp;
                    q_sp.push(node_sp->left_sp);
                    q_sp.push(node_sp->right_sp);
                } else {
                    cout << "  ";
                    q_sp.push(NULL);
                    q_sp.push(NULL);
                }

                for (int j = 0; j < space_sp * 2 - 2; j++)
                    cout << " ";
            }
            cout << endl;
            level_sp++;
            space_sp /= 2; 
        }
    }
};

int main() {
    BT_sp bt_sp;
    int choice_sp, value_sp;

    while (true) {
        cout << "\n----------- MENU -----------";
        cout << "\n1. Insert Node";
        cout << "\n2. Inorder Traversal (Recursive)";
        cout << "\n3. Preorder Traversal (Recursive)";
        cout << "\n4. Count Leaf Nodes";
        cout << "\n5. Mirror Image of Tree";
        cout << "\n6. Display Tree";
        cout << "\n7. Exit";
        cout << "\n----------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "Enter value: ";
                cin >> value_sp;
                bt_sp.create_sp(value_sp);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                bt_sp.inorder_sp(bt_sp.root_sp);
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                bt_sp.preorder_sp(bt_sp.root_sp);
                cout << endl;
                break;

            case 4:
                cout << "Number of Leaf Nodes: " << bt_sp.countLeaf_sp(bt_sp.root_sp) << endl;
                break;

            case 5:
                bt_sp.root_sp = bt_sp.mirror_sp(bt_sp.root_sp);
                cout << "Mirror Image Created.\n";
                bt_sp.displayTree_sp(bt_sp.root_sp);
                break;

            case 6:
                cout << "\nTree Display:\n";
                bt_sp.displayTree_sp(bt_sp.root_sp);
                break;

            case 7:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
