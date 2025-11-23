#include<iostream>
#include<iomanip>
#include<queue>
#include<math.h>
using namespace std;

class Node_sp{
    public:
    int data_sp;
    Node_sp *left_sp, *right_sp;

    Node_sp(int val_sp){
        data_sp = val_sp;
        left_sp = NULL;
        right_sp = NULL; 
    }
};

class BST_sp{
    public:
    Node_sp *root_sp;

    BST_sp(){
        root_sp = NULL;
    }

    Node_sp* insert_sp(Node_sp* node_sp, int value_sp){
        if(node_sp == NULL){
            return new Node_sp(value_sp);
        }

        if(value_sp < node_sp->data_sp){
            node_sp->left_sp = insert_sp(node_sp->left_sp, value_sp);
        }
        else if(value_sp > node_sp->data_sp){
            node_sp->right_sp = insert_sp(node_sp->right_sp, value_sp);
        }

        return node_sp;
    }

    void create_sp(int value_sp){
        root_sp = insert_sp(root_sp, value_sp);
    }

    int minOfBST_sp(Node_sp* node_sp){
        if(node_sp == NULL){
            cout<<"Tree is empty "<<endl;
            return -1;
        }

        while(node_sp->left_sp != NULL){
            node_sp = node_sp->left_sp;
        }
        return node_sp->data_sp;
    }

    int maxOfBST_sp(Node_sp* node_sp){
        if(node_sp == NULL){
            cout<<"Tree is empty "<<endl;
            return -1;
        }
        while(node_sp->right_sp != NULL){
            node_sp = node_sp->right_sp;
        }

        return node_sp->data_sp;
    }

    int height_sp(Node_sp* node_sp) {
        if (node_sp == NULL)
            return 0;
        return 1 + max(height_sp(node_sp->left_sp), height_sp(node_sp->right_sp));
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
};

int main(){
    BST_sp tree_sp;
    int choice_sp, value_sp;

    while(true){
        cout<<"\n-----------MENU---------------";
        cout<<"\n1.Insert Node";
        cout<<"\n2.Find min";
        cout<<"\n3.Find max";
        cout<<"\n4.Display tree";
        cout<<"\n5.Exit";
        cout<<"\n------------------------------";
        cout<<"\nEnter your choice: ";
        cin>>choice_sp;

        switch(choice_sp){
            case 1:
                cout<<"Enter the value: ";
                cin>>value_sp;
                tree_sp.create_sp(value_sp);
                break;
            case 2:
                cout<<"Min value: "<<tree_sp.minOfBST_sp(tree_sp.root_sp)<<endl;
                break;
            case 3:
                cout<<"Max value: "<<tree_sp.maxOfBST_sp(tree_sp.root_sp)<<endl;
                break;
            case 4:
                cout<<"\nBinary Search Tree: \n";
                tree_sp.displayTree_sp(tree_sp.root_sp);
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                return 0;
            default:
                cout<<"Invalid choice "<<endl;
        }

    }
}