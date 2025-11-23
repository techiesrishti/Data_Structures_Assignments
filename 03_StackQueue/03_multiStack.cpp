#include <iostream>
using namespace std;

class MultiStack {
    int *arr;
    int *top;
    int *startIndex;
    int *endIndex;
    int n, k;

public:
    MultiStack(int k1, int n1) {
        k = k1;
        n = n1;
        arr = new int[n];
        top = new int[k];
        startIndex = new int[k];
        endIndex = new int[k];

        int base = n / k;
        int rem = n % k;

        int idx = 0;
        for (int i = 0; i < k; ++i) {
            int sz = base + (i < rem ? 1 : 0);      
            startIndex[i] = idx;
            endIndex[i] = idx + sz - 1;
            top[i] = startIndex[i] - 1;            
            idx += sz;
        }

        cout << "\n[Debug] Partitions (start..end) for each stack:\n";
        for (int i = 0; i < k; ++i) {
            cout << " Stack " << i+1 << ": ";
            if (startIndex[i] > endIndex[i]) cout << "(no space assigned)\n";
            else cout << startIndex[i] << " .. " << endIndex[i] << "\n";
        }
        cout << endl;
    }

    bool isFull(int sn) {
        if (sn < 0 || sn >= k) return true;           
        if (startIndex[sn] > endIndex[sn]) return true;
        return top[sn] == endIndex[sn];
    }

    bool isEmpty(int sn) {
        if (sn < 0 || sn >= k) return true;           
        return top[sn] < startIndex[sn];
    }

    void push(int item, int sn) {
        if (sn < 0 || sn >= k) {
            cout << "Invalid stack number!\n";
            return;
        }
        if (isFull(sn)) {
            cout << "push(): Stack Overflow! Cannot push " << item << " into stack " << sn + 1 << endl;
            return;
        }
        top[sn]++;
        arr[top[sn]] = item;
        cout << "Pushed " << item << " into stack " << sn + 1 << endl;
    }

    void pop(int sn) {
        if (sn < 0 || sn >= k) {
            cout << "Invalid stack number!\n";
            return;
        }
        if (isEmpty(sn)) {
            cout << "pop(): Stack Underflow! Stack " << sn + 1 << " is empty\n";
            return;
        }
        int val = arr[top[sn]];
        top[sn]--;
        cout << "Popped value: " << val << " from stack " << sn + 1 << endl;
    }

    void displayAll() {
        for (int i = 0; i < k; ++i) {
            if (startIndex[i] > endIndex[i]) {
                cout << "Stack " << i+1 << " has no allocated space\n";
                continue;
            }
            if (isEmpty(i)) {
                cout << "Stack " << i + 1 << " is empty.\n";
            } else {
                cout << "Stack " << i + 1 << ": ";
                for (int j = top[i]; j >= startIndex[i]; --j)
                    cout << arr[j] << " ";
                cout << endl;
            }
        }
    }

    ~MultiStack() {
        delete[] arr;
        delete[] top;
        delete[] startIndex;
        delete[] endIndex;
    }
};

int main() {
    int numStacks, totalSize;
    cout << "Enter number of stacks: ";
    cin >> numStacks;
    cout << "Enter total array size: ";
    cin >> totalSize;

    if (numStacks <= 0 || totalSize <= 0) {
        cout << "Invalid sizes. Exiting.\n";
        return 0;
    }

    MultiStack ms(numStacks, totalSize);

    int choice, sn, val;
    do {
        cout << "\n---------MENU----------\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter stack number (1-" << numStacks << "): ";
                cin >> sn;
                cout << "Enter value to push: ";
                cin >> val;
                ms.push(val, sn - 1);
                break;
            case 2:
                cout << "Enter stack number (1-" << numStacks << "): ";
                cin >> sn;
                ms.pop(sn - 1);
                break;
            case 3:
                ms.displayAll();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
