#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>
#include <queue>
#include <cmath>
using namespace std;

class Product_sp {
public:
    string productCode_sp;
    string productName_sp;
    float price_sp;
    int quantity_sp;
    string dateReceived_sp;
    string expiryDate_sp;

    Product_sp() {}

    Product_sp(string c_sp, string n_sp, float p_sp, int q_sp, string d_sp, string e_sp) {
        productCode_sp = c_sp;
        productName_sp = n_sp;
        price_sp = p_sp;
        quantity_sp = q_sp;
        dateReceived_sp = d_sp;
        expiryDate_sp = e_sp;
    }
};

class Node_sp {
public:
    Product_sp product_sp;
    Node_sp *left_sp, *right_sp;

    Node_sp(Product_sp p_sp) {
        product_sp = p_sp;
        left_sp = right_sp = NULL;
    }
};

class ProductBST_sp {
public:
    Node_sp *root_sp;

    ProductBST_sp() {
        root_sp = NULL;
    }

    Node_sp* insert_sp(Node_sp* node_sp, Product_sp p_sp) {
        if (node_sp == NULL)
            return new Node_sp(p_sp);

        if (p_sp.productName_sp < node_sp->product_sp.productName_sp)
            node_sp->left_sp = insert_sp(node_sp->left_sp, p_sp);
        else if (p_sp.productName_sp > node_sp->product_sp.productName_sp)
            node_sp->right_sp = insert_sp(node_sp->right_sp, p_sp);
        else
            cout << "Duplicate product name not allowed.\n";

        return node_sp;
    }

    void insertProduct_sp(Product_sp p_sp) {
        root_sp = insert_sp(root_sp, p_sp);
    }

    void inorder_sp(Node_sp* node_sp) {
        if (node_sp == NULL) return;

        inorder_sp(node_sp->left_sp);
        cout << "\nProduct Code: " << node_sp->product_sp.productCode_sp;
        cout << "\nProduct Name: " << node_sp->product_sp.productName_sp;
        cout << "\nPrice: " << node_sp->product_sp.price_sp;
        cout << "\nQuantity: " << node_sp->product_sp.quantity_sp;
        cout << "\nReceived: " << node_sp->product_sp.dateReceived_sp;
        cout << "\nExpiry: " << node_sp->product_sp.expiryDate_sp;
        cout << "\n-----------------------------";
        inorder_sp(node_sp->right_sp);
    }

    bool isExpired_sp(string expiry_sp) {
        time_t t = time(0);
        tm* now_sp = localtime(&t);

        int cy = now_sp->tm_year + 1900;
        int cm = now_sp->tm_mon + 1;
        int cd = now_sp->tm_mday;

        int ey, em, ed;
        char dash;

        stringstream(expiry_sp) >> ey >> dash >> em >> dash >> ed;

        if (ey < cy) return true;
        if (ey == cy && em < cm) return true;
        if (ey == cy && em == cm && ed < cd) return true;
        return false;
    }

    void preorderExpired_sp(Node_sp* node_sp) {
        if (node_sp == NULL) return;

        if (isExpired_sp(node_sp->product_sp.expiryDate_sp)) {
            cout << "\nExpired: " << node_sp->product_sp.productName_sp
                 << " | Code: " << node_sp->product_sp.productCode_sp
                 << " | Expiry: " << node_sp->product_sp.expiryDate_sp;
        }

        preorderExpired_sp(node_sp->left_sp);
        preorderExpired_sp(node_sp->right_sp);
    }

    int height_sp(Node_sp* node_sp) {
        if (node_sp == NULL) return 0;
        int lh = height_sp(node_sp->left_sp);
        int rh = height_sp(node_sp->right_sp);
        return 1 + (lh > rh ? lh : rh);
    }

    void displayTree_sp(Node_sp* root_sp) {
        if (root_sp == NULL) {
            cout << "Tree is empty!\n";
            return;
        }

        int h_sp = height_sp(root_sp);
        int maxNodes_sp = pow(2, h_sp) - 1;
        int maxWidth_sp = 8 * maxNodes_sp;

        queue<Node_sp*> q_sp;
        q_sp.push(root_sp);

        for (int lvl_sp = 0; lvl_sp < h_sp; lvl_sp++) {
            int count_sp = q_sp.size();
            int gap_sp = maxWidth_sp / (count_sp + 1);

            for (int i = 0; i < count_sp; i++) {
                Node_sp* curr_sp = q_sp.front();
                q_sp.pop();

                if (curr_sp)
                    cout << setw(gap_sp) << curr_sp->product_sp.productName_sp;
                else
                    cout << setw(gap_sp) << " ";

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
    ProductBST_sp inventory_sp;
    int choice_sp;

    while (1) {
        cout << "\n------------ MENU ----------------";
        cout << "\n1. Insert Product";
        cout << "\n2. Display Inventory (Inorder)";
        cout << "\n3. Show Expired Products (Preorder)";
        cout << "\n4. Display Product Tree";
        cout << "\n5. Exit";
        cout << "\n----------------------------------";
        cout << "\nEnter choice: ";
        cin >> choice_sp;

        if (choice_sp == 1) {
            Product_sp p_sp;
            cout << "Code: ";
            cin >> p_sp.productCode_sp;
            cout << "Name: ";
            cin >> p_sp.productName_sp;
            cout << "Price: ";
            cin >> p_sp.price_sp;
            cout << "Qty: ";
            cin >> p_sp.quantity_sp;
            cout << "Received (YYYY-MM-DD): ";
            cin >> p_sp.dateReceived_sp;
            cout << "Expiry (YYYY-MM-DD): ";
            cin >> p_sp.expiryDate_sp;

            inventory_sp.insertProduct_sp(p_sp);
        }

        else if (choice_sp == 2) {
            cout << "\n----- Inventory (Sorted by Name) -----\n";
            inventory_sp.inorder_sp(inventory_sp.root_sp);
            cout << "\n";
        }

        else if (choice_sp == 3) {
            cout << "\n----- Expired Products (Preorder) -----\n";
            inventory_sp.preorderExpired_sp(inventory_sp.root_sp);
            cout << "\n";
        }

        else if (choice_sp == 4) {
            cout << "\n----- Product Tree (Horizontal View) -----\n";
            inventory_sp.displayTree_sp(inventory_sp.root_sp);
        }

        else if (choice_sp == 5) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
