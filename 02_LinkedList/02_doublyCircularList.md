# **Assignment No: 2 (UNIT 2)**  
## **Title:**  
The ticket reservation system for Galaxy Multiplex is to be implemented using a C++ program. The multiplex has 8 rows, with 8 seats in each row. A doubly circular linked list will be used to track the availability of seats in each row.Initially, assume that some seats are randomly booked. An array will store head pointers for each row’s linked list.The system should support the following operations:
- Display the current list of available seats.
- Book one or more seats as per customer request.
- Cancel an existing booking when requested.


## **Concepts Used**
- Doubly Linked List  
- Circular Linked List  
- Dynamic Memory Allocation  
- Node Traversal  
- Searching  
- Updating Node Data  
- Menu-driven Program  

---

## **Pseudocode**

---

### **Node Structure**
1. Define a class `Node` with:  
   - seatNo (integer)  
   - booked (boolean)  
   - next (Node pointer)  
   - prev (Node pointer)  
2. Constructor initializes values and sets pointers to NULL.

---

### **1. Create a Row (Doubly Circular Linked List of 8 Seats)**
1. Loop seat numbers from 1 to 8  
2. Create a new Node  
3. If head is NULL:  
   - head = newNode  
   - head.next = head  
   - head.prev = head  
4. Else:  
   - Insert newNode before head (attach at the end)  
   - Update previous last node  
   - Maintain circular links  

---

### **2. Randomly Book Seats**
1. Generate a random number `numBooked` between 2 to 4  
2. Repeat numBooked times:  
   - Pick a random seat number 1–8  
   - Traverse row until seat found  
   - Mark that seat as booked  

---

### **3. Display a Row**
1. If head is NULL → return  
2. Set temp = head  
3. Print “[”  
4. Loop through row using do-while:  
   - If seat booked print “X”  
   - Else print seatNo  
   - Move temp = temp.next  
5. Stop when temp returns to head  
6. Close with “]”  

---

### **4. Book a Seat**
1. Input seat number  
2. Traverse the circular list:  
   - If seat matches:  
       - If booked → show “already booked”  
       - Else mark booked = true  
       - Show success  
3. If seat not found → print “Invalid seat number”  

---

### **5. Cancel a Seat**
1. Input seat number  
2. Traverse list:  
   - If found:  
       - If not booked → print “not booked yet”  
       - Else mark booked = false  
       - Show cancellation message  
3. If not found → print “Invalid seat number”  

---

### **6. Menu-Driven Program**
1. Create an array of 8 rows  
2. For each row:  
   - Call createRow()  
   - Call randomBooking()  
3. Show menu repeatedly:  
   - 1 → Display seats  
   - 2 → Book seat  
   - 3 → Cancel booking  
   - 0 → Exit  
4. Execute desired actions  

---

## **Output**

Galaxy Multiplex Ticket Reservation

Display Available Seats

Book Seats

Cancel Booking

Exit
Enter your choice: 1

No of Seats Available
Row 1: [ X 2 3 X 5 6 7 8 ]
Row 2: [ 1 2 X 4 5 6 7 8 ]
Row 3: [ 1 X 3 4 5 X 7 8 ]
Row 4: [ 1 2 3 4 X 6 7 8 ]
Row 5: [ X 2 3 4 5 6 7 X ]
Row 6: [ 1 2 3 X 5 6 7 8 ]
Row 7: [ 1 2 X 4 5 6 7 8 ]
Row 8: [ 1 X 3 4 5 6 7 8 ]

Enter your choice: 2
Enter row number: 3
How many seats to book? 2
Enter seat number: 1
Seat 1 booked successfully!
Enter seat number: 4
Seat 4 booked successfully!

Enter your choice: 3
Enter row number: 3
Enter seat number to cancel: 4
Booking for seat 4 canceled.

Enter your choice: 0
Exiting...
Bye...