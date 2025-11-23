#include <iostream>
#include <cstdlib> 
using namespace std;

struct Appointment {
    int start;
    int end;
    Appointment* next;
};

class Schedule {
    Appointment* head;
    int startTime, endTime, minDur, maxDur;

public:
    Schedule(int s, int e, int minD, int maxD) {
        head = NULL;
        startTime = s;
        endTime = e;
        minDur = minD;
        maxDur = maxD;
    }

    // Display available appointments
    void display() {
        if (head == NULL) {
            cout << "\nNo appointments booked yet.\n";
            return;
        }
        cout << "\nBooked Appointments:\n";
        Appointment* temp = head;
        while (temp != NULL) {
            cout << temp->start << " to " << temp->end << endl;
            temp = temp->next;
        }
    }

    // Check if a slot is available
    bool isAvailable(int s, int e) {
        if (s < startTime || e > endTime) return false;
        Appointment* temp = head;
        while (temp != NULL) {
            if (!(e <= temp->start || s >= temp->end))
                return false; // overlap
            temp = temp->next;
        }
        return true;
    }

    // Book a new appointment (unsorted insertion)
    void book() {
        int s, d;
        cout << "\nEnter start time (e.g., 9 for 9 AM): ";
        cin >> s;
        cout << "Enter duration (in hours): ";
        cin >> d;

        if (d < minDur || d > maxDur) {
            cout << "Duration must be between " << minDur << " and " << maxDur << " hours.\n";
            return;
        }

        int e = s + d;
        if (!isAvailable(s, e)) {
            cout << "Slot not available or invalid.\n";
            return;
        }

        Appointment* newAppt = new Appointment;
        newAppt->start = s;
        newAppt->end = e;
        newAppt->next = NULL;

        // Insert at end (unsorted)
        if (head == NULL) head = newAppt;
        else {
            Appointment* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newAppt;
        }

        cout << "Appointment booked from " << s << " to " << e << ".\n";
    }

    // Cancel an appointment
    void cancel() {
        if (head == NULL) {
            cout << "No appointments to cancel.\n";
            return;
        }

        int s;
        cout << "Enter start time of appointment to cancel: ";
        cin >> s;

        Appointment* temp = head;
        Appointment* prev = NULL;

        while (temp != NULL && temp->start != s) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "No appointment found at " << s << ".\n";
            return;
        }

        if (prev == NULL) head = temp->next;
        else prev->next = temp->next;

        delete temp;
        cout << "Appointment at " << s << " cancelled.\n";
    }

    // Sort using data swapping
    void sortBySwap() {
        if (head == NULL || head->next == NULL) return;

        for (Appointment* i = head; i != NULL; i = i->next) {
            for (Appointment* j = i->next; j != NULL; j = j->next) {
                if (i->start > j->start) {
                    // swap data
                    swap(i->start, j->start);
                    swap(i->end, j->end);
                }
            }
        }
        cout << "\nAppointments sorted by swapping data values.\n";
    }

    // Sort using pointer manipulation (no swapping data)
    void sortByPointer() {
        if (head == NULL || head->next == NULL) return;

        Appointment* sorted = NULL;

        while (head != NULL) {
            Appointment* curr = head;
            head = head->next;

            if (sorted == NULL || curr->start < sorted->start) {
                curr->next = sorted;
                sorted = curr;
            } else {
                Appointment* temp = sorted;
                while (temp->next != NULL && temp->next->start < curr->start)
                    temp = temp->next;
                curr->next = temp->next;
                temp->next = curr;
            }
        }

        head = sorted;
        cout << "\nAppointments sorted by pointer manipulation.\n";
    }

    // Destructor to free memory
    ~Schedule() {
        Appointment* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Schedule day(9, 17, 1, 3); // from 9 AM to 5 PM, 1–3 hr duration

    int choice;
    do {
        cout << "\n---- Appointment Schedule Menu ----";
        cout << "\n1. Display Appointments";
        cout << "\n2. Book Appointment";
        cout << "\n3. Cancel Appointment";
        cout << "\n4. Sort Appointments (Data Swapping)";
        cout << "\n5. Sort Appointments (Pointer Manipulation)";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: day.display(); break;
        case 2: day.book(); break;
        case 3: day.cancel(); break;
        case 4: day.sortBySwap(); break;
        case 5: day.sortByPointer(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
