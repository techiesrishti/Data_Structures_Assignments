#include <iostream>
using namespace std;

class PizzaParlour {
    int front_sp, rear_sp, size_sp, count_sp;
    int *order_sp;   

public:
    PizzaParlour(int n_sp) {
        size_sp = n_sp;
        order_sp = new int[size_sp];
        front_sp = 0;
        rear_sp = -1;
        count_sp = 0;
    }

    bool isFull() {
        return (count_sp == size_sp);
    }

    bool isEmpty() {
        return (count_sp == 0);
    }

    void placeOrder(int id_sp) {
        if (isFull()) {
            cout << "cannot place order " << id_sp << " parlour is full!\n";
            return;
        }
        rear_sp = (rear_sp + 1) % size_sp;
        order_sp[rear_sp] = id_sp;
        count_sp++;
        cout << "order " << id_sp << " placed successfully!\n";
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "no orders to serve parlour is empty!\n";
            return;
        }
        cout << "serving order number: " << order_sp[front_sp] << endl;
        front_sp = (front_sp + 1) % size_sp;
        count_sp--;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "no pending orders.\n";
            return;
        }
        cout << "\npending Orders:\n";
        int i_sp = front_sp;
        for (int c_sp = 0; c_sp < count_sp; c_sp++) {
            cout << "  order ID: " << order_sp[i_sp] << endl;
            i_sp = (i_sp + 1) % size_sp;
        }
    }

    ~PizzaParlour() {
        delete[] order_sp;
    }
};

int main() {
    int n_sp, choice_sp, id_sp;
    cout << "enter maximum no of pizza orders parlour can accept: ";
    cin >> n_sp;

    PizzaParlour p_sp(n_sp);

    do {
        cout << "\n------- PIZZA PARLOUR MENU -------\n";
        cout << "1. place new order\n";
        cout << "2. serve next order\n";
        cout << "3. display pending orders\n";
        cout << "4. exit\n";
        cout << "----------------------------------\n";
        cout << "enter your choice: ";
        cin >> choice_sp;

        switch (choice_sp) {
            case 1:
                cout << "enter order number (ID): ";
                cin >> id_sp;
                p_sp.placeOrder(id_sp);
                break;
            case 2:
                p_sp.serveOrder();
                break;
            case 3:
                p_sp.displayOrders();
                break;
            case 4:
                cout << "closing Pizza Parlour system...\n";
                break;
            default:
                cout << "invalid choice!\n";
        }
    } while (choice_sp != 4);

    return 0;
}
