#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>
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

    Product_sp(string code, string name, float price, int qty, string received, string expiry) {
        productCode_sp = code;
        productName_sp = name;
        price_sp = price;
        quantity_sp = qty;
        dateReceived_sp = received;
        expiryDate_sp = expiry;
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
    Node_sp* insert_sp(Node_sp* node, Product_sp p) {
        if (node == NULL)
            return new Node_sp(p);

        if (p.productName_sp < node->product_sp.productName_sp)
            node->left_sp = insert_sp(node->left_sp, p);
        else if (p.productName_sp > node->product_sp.productName_sp)
            node->right_sp = insert_sp(node->right_sp, p);
        else
            cout << "Duplicate Product Name not allowed.\n";

        return node;
    }

    void insertProduct_sp(Product_sp p) {
        root_sp = insert_sp(root_sp, p);
    }

    void inorder_sp(Node_sp* node) {
        if (!node) return;

        inorder_sp(node->left_sp);
        cout << "\nCode: " << node->product_sp.productCode_sp
             << "\nName: " << node->product_sp.productName_sp
             << "\nPrice: " << node->product_sp.price_sp
             << "\nQuantity: " << node->product_sp.quantity_sp
             << "\nReceived: " << node->product_sp.dateReceived_sp
             << "\nExpiry: " << node->product_sp.expiryDate_sp
             << "\n------------------------------";
        inorder_sp(node->right_sp);
    }

    bool isExpired_sp(string expiry) {
        time_t t = time(0);
        tm* now = localtime(&t);

        int currY = now->tm_year + 1900;
        int currM = now->tm_mon + 1;
        int currD = now->tm_mday;

        int y, m, d;
        char dash;
        stringstream(expiry) >> y >> dash >> m >> dash >> d;

        if (y < currY) return true;
        if (y == currY && m < currM) return true;
        if (y == currY && m == currM && d < currD) return true;
        return false;
    }

    Node_sp* deleteByCode_sp(Node_sp* node, string code) {
        if (!node) return NULL;

        if (node->product_sp.productCode_sp == code) {

            if (!node->left_sp && !node->right_sp) {
                delete node;
                return NULL;
            }
            else if (!node->left_sp) {
                Node_sp* temp = node->right_sp;
                delete node;
                return temp;
            }
            else if (!node->right_sp) {
                Node_sp* temp = node->left_sp;
                delete node;
                return temp;
            }
            else {
                Node_sp* temp = node->right_sp;
                while (temp->left_sp != NULL)
                    temp = temp->left_sp;

                node->product_sp = temp->product_sp;
                node->right_sp = deleteByCode_sp(node->right_sp, temp->product_sp.productCode_sp);
                return node;
            }
        }

        node->left_sp = deleteByCode_sp(node->left_sp, code);
        node->right_sp = deleteByCode_sp(node->right_sp, code);

        return node;
    }

    void deleteProductByCode_sp(string code) {
        root_sp = deleteByCode_sp(root_sp, code);
        cout << "Product has been deleted successfully.\n";
    }

    Node_sp* deleteExpired_sp(Node_sp* node) {
        if (!node) return NULL;

        node->left_sp = deleteExpired_sp(node->left_sp);
        node->right_sp = deleteExpired_sp(node->right_sp);

        if (isExpired_sp(node->product_sp.expiryDate_sp)) {
            cout << "Deleting expired: " << node->product_sp.productName_sp << "\n";
            return deleteByCode_sp(node, node->product_sp.productCode_sp);
        }
        return node;
    }

    void deleteAllExpired_sp() {
        root_sp = deleteExpired_sp(root_sp);
        cout << "All expired products removed.\n";
    }
};

int main() {
    ProductBST_sp inventory;
    int choice;

    while (true) {
        cout << "\n---------- MENU ----------\n";
        cout << "1. Insert Product\n";
        cout << "2. Delete Product by Code\n";
        cout << "3. Delete All Expired Products\n";
        cout << "4. Show Inventory (Inorder)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Product_sp p;
            cout << "Enter Code: ";
            cin >> p.productCode_sp;
            cout << "Enter Name: ";
            cin >> p.productName_sp;
            cout << "Enter Price: ";
            cin >> p.price_sp;
            cout << "Enter Quantity: ";
            cin >> p.quantity_sp;
            cout << "Enter Date Received (YYYY-MM-DD): ";
            cin >> p.dateReceived_sp;
            cout << "Enter Expiry Date (YYYY-MM-DD): ";
            cin >> p.expiryDate_sp;
            inventory.insertProduct_sp(p);
        }

        else if (choice == 2) {
            string code;
            cout << "Enter product code to delete: ";
            cin >> code;
            inventory.deleteProductByCode_sp(code);
        }

        else if (choice == 3) {
            inventory.deleteAllExpired_sp();
        }

        else if (choice == 4) {
            inventory.inorder_sp(inventory.root_sp);
        }

        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
}
