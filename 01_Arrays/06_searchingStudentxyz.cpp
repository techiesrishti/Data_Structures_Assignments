#include <iostream>
using namespace std;

struct Student {
    string name_sp;
    string div_sp;
    int rollNo_sp;
    string year_sp;
};

int main() {
    // search student
    string search_name_sp = "XYZ";
    string search_div_sp = "X";
    int search_roll_sp = 17;
    string search_yr_sp = "SY";

    Student s;
    int count = 1;

    while (true) {
        cout << "Enter student details.. type stop to exit:\n";
        cin >> s.name_sp;

        if (s.name_sp == "stop") {
            cout << "Stopped. No record found\n";
            break;
        }

        cin >> s.div_sp >> s.rollNo_sp >> s.year_sp;

        if (s.name_sp == search_name_sp && s.div_sp == search_div_sp &&
            s.rollNo_sp == search_roll_sp && s.year_sp == search_yr_sp) {
            cout << "Student found at  " << count << "\n";
            break;
        } else {
            cout << "No record found.\n";
        }

        count++;
    }

    return 0;
}
