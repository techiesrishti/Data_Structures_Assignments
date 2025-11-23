# **Assignment No: 1 (UNIT 2)**  
## **Title:** 
Implementation of Singly Linked List to Manage ‘Vertex Club’ Membership Records.
The Department of Computer Engineering has a student club named ‘Vertex Club’ for second, third, and final year students. The first member is the President and the last member is the Secretary. Write a C++ program to:
●	Add/delete members (including President/Secretary)
●	Count members
●	Display members
●	Concatenate two division lists
 Also implement: reverse, search by PRN, and sort by PRN operations.

## **Concepts Used**
- Singly Linked List  
- Dynamic Memory Allocation  
- Node Insertion (Beginning, Middle, End)  
- Node Deletion  
- Traversal  
- Search  
- Reverse  
- Sorting (Bubble Sort)  
- Concatenation of Lists  

---

## **Pseudocode**

---

### **Node Structure**
1. Define a structure Node with:
   - PRN (integer)
   - Name (string)
   - next (pointer to Node)

---

### **1. Add President (Insert at Beginning)**
1. Create a new node.
2. Read PRN and Name.
3. Set newNode.next = head.
4. Update head = newNode.
5. President added at the beginning.

---

### **2. Add Secretary (Insert at End)**
1. Create a new node.
2. Read PRN and Name.
3. If head is NULL:
   - Set head = newNode.
4. Else:
   - Traverse to the last node.
   - Set lastNode.next = newNode.
5. Secretary added at the end.

---

### **3. Add Member (Insert in Middle before Secretary)**
1. If list is empty:
   - Display “Add President and Secretary first.”
   - Stop.
2. Create a new node and read PRN, Name.
3. Traverse the list until second-last node (node before secretary).
4. Insert node before secretary:
   - newNode.next = current.next
   - current.next = newNode

---

### **4. Delete President**
1. If head is NULL:
   - Display “No members.”
   - Stop.
2. Store current head in temp.
3. Update head = head.next.
4. Delete temp.

---

### **5. Delete Secretary**
1. If head is NULL:
   - Display “No members.”
   - Stop.
2. If only one node exists:
   - Delete head.
   - Set head = NULL.
3. Else:
   - Traverse until second-last node.
   - Delete the last node.
   - Set second-last.next = NULL.

---

### **6. Delete Member by PRN**
1. Input PRN to delete.
2. Traverse list, tracking current (p) and previous (q).
3. If p is NULL:
   - Member not found.
4. If q is NULL:
   - Deleting head → set head = p.next.
5. Else:
   - q.next = p.next.
6. Delete p.

---

### **7. Count Members**
1. Initialize count = 0.
2. Traverse entire list.
3. Increment count for each node.
4. Display total count.

---

### **8. Display Members**
1. If head is NULL:
   - Display “No members.”
   - Stop.
2. Start from head.
3. Print PRN and Name for each node until NULL.

---

### **9. Reverse Linked List**
1. Initialize prev = NULL, curr = head.
2. Loop while curr is not NULL:
   - Store curr.next in nextNode.
   - Set curr.next = prev.
   - Move prev = curr.
   - Move curr = nextNode.
3. Set head = prev.
4. Display reversed list.

---

### **10. Search by PRN**
1. Input PRN to search.
2. Traverse list node by node.
3. If PRN matches:
   - Display name and details.
   - Stop.
4. If end reached:
   - Display “Member not found.”

---

### **11. Sort List by PRN**
1. Use Bubble Sort logic:
2. Repeat until no swaps:
   - Traverse from head.
   - If current.PRN > next.PRN:
     - Swap PRN values.
     - Swap names.
3. Display sorted list.

---

### **12. Concatenate Two Lists**
1. If first list is empty:
   - head1 = head2.
2. Else:
   - Traverse to last node of list1.
   - Set lastNode.next = head2.
3. Concatenation complete.

---

## **Output**
-------Vertex Club Menu--------

Add President

Add Secretary

Add Member

Delete Secretary

Delete President

Delete Member by PRN

Count Members

Display Members

Reverse

Search

Sort

Concatenate Lists

Exit

Enter choice: 1
Enter PRN: 101
Enter Name: Aarav
President added successfully.

Enter choice: 2
Enter PRN: 199
Enter Name: Rohan
Secretary added successfully.

Enter choice: 3
Enter PRN: 145
Enter Name: Meera
Member added successfully.

Enter choice: 8
[PRN: 101 | Name: Aarav] -> [PRN: 145 | Name: Meera] -> [PRN: 199 | Name: Rohan] -> NULL

Enter choice: 7
Total Members: 3

Enter choice: 10
Enter PRN to search: 145
Member found: Meera

Enter choice: 9
List reversed.
[199 Rohan] -> [145 Meera] -> [101 Aarav]

Enter choice: 11
List sorted by PRN.
[101 Aarav] -> [145 Meera] -> [199 Rohan]

---
