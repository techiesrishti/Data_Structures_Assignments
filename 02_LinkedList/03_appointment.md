# Assignment No: 3

## Title:
Develop a C++ program to store and manage an appointment schedule for a single day. Appointments should be scheduled randomly using a linked list. The system must define the start time, end time, and specify the minimum and maximum duration allowed for each appointment slot.
The program should include the following operations:
- Display the list of currently available time slots.
- Book a new appointment within the defined time limits.
- Cancel an existing appointment after validating its time, availability, and correctness.
- Sort the appointment list in order of appointment times.
- Sort the list based on appointment times using pointer manipulation (without swapping data values).



---

## Concepts Used:
- Singly Linked List  
- Node creation and traversal  
- Unsorted insertion  
- Deletion of a node  
- Overlap checking  
- Sorting using data swapping  
- Sorting using pointer manipulation  
- Dynamic memory allocation  

---

## Pseudocode:

### Display Appointments
1. If head is NULL, print "No appointments booked".
2. Else set temp = head.
3. While temp is not NULL:
   - Print temp.start and temp.end.
   - Move temp to temp.next.

---

### Check Availability
1. If start < scheduleStart OR end > scheduleEnd → return false.
2. Set temp = head.
3. While temp is not NULL:
   - If new slot overlaps with temp slot → return false.
   - Move to next node.
4. Return true.

---

### Book Appointment
1. Read start time and duration.
2. Compute end = start + duration.
3. Validate duration range (min to max).
4. Call availability check.
5. If unavailable → exit.
6. Create a new appointment node.
7. If list empty → head = new node.
8. Else traverse to last node and insert new node.
9. Print confirmation message.

---

### Cancel Appointment
1. If head is NULL → print "No appointments to cancel" and exit.
2. Read start time to delete.
3. Traverse list until matching start time found.
4. If not found → print "No appointment found".
5. Else adjust pointers, delete node, print success message.

---

### Sort by Data Swapping
1. For each node i:
   - For each node j after i:
     - If i.start > j.start:
       - Swap i.start with j.start.
       - Swap i.end with j.end.
2. Print sorting confirmation.

---

### Sort by Pointer Manipulation
1. Create empty sorted list.
2. While head is not NULL:
   - Remove first node (curr) from head.
   - Insert curr in correct position inside sorted list.
3. Set head = sorted list.
4. Print sorting confirmation.

---

## Output:
---- Appointment Schedule Menu ----

Display Appointments

Book Appointment

Cancel Appointment

Sort Appointments (Data Swapping)

Sort Appointments (Pointer Manipulation)

Exit
Enter choice: 2

Enter start time (e.g., 9 for 9 AM): 10
Enter duration (in hours): 2
Appointment booked from 10 to 12.

Enter choice: 2
Enter start time (e.g., 9 for 9 AM): 13
Enter duration (in hours): 1
Appointment booked from 13 to 14.

Enter choice: 1
Booked Appointments:
10 to 12
13 to 14

Enter choice: 4
Appointments sorted by swapping data values.

Enter choice: 3
Enter start time of appointment to cancel: 10
Appointment at 10 cancelled.

Enter choice: 1
Booked Appointments:
13 to 14

Enter choice: 6
Exiting...