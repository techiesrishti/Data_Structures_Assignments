# **Assignment No: 5**

## **Title:**  
Write a C++ program to store a binary number using a doubly linked list. Implement the following functions:
- Calculate and display the 1’s complement and 2’s complement of the stored binary number.
- Perform addition of two binary numbers represented using doubly linked lists and display the result.

---

## **Concepts Used**
- Doubly Linked List  
- Node Insertion (Front & End)  
- Traversal  
- 1’s Complement Operation  
- 2’s Complement Operation  
- Binary Addition Using Carry  
- Copy Constructor  
- Dynamic Memory Allocation  
- Destructor for Memory Cleanup  

---

## **Pseudocode**

---

### **Node Structure**
1. Create `Node` with:  
   - bit (0 or 1)  
   - prev pointer  
   - next pointer  

---

### **Insert at End**
1. Create new node.  
2. If list empty → head = tail = newNode.  
3. Else:  
   - tail->next = newNode  
   - newNode->prev = tail  
   - tail = newNode  

---

### **Insert at Front**
1. Create new node.  
2. newNode->next = head  
3. If list not empty → head->prev = newNode  
4. Else → tail = newNode  
5. head = newNode  

---

### **Display Binary Number**
1. If head is NULL → print "Empty".  
2. Else traverse from head to tail printing bits.

---

### **1's Complement**
1. Traverse entire list.  
2. For each node:  
   - If bit = 0 → change to 1  
   - Else → change to 0  

---

### **2's Complement**
1. First call `onesComp()`  
2. Set carry = 1  
3. Start from tail:  
   - If bit = 0 → set to 1, carry = 0  
   - Else bit = 1 → set to 0, carry = 1  
   - Move to prev node  
4. After traversal:  
   - If carry = 1 → insertAtFront(1)

---

### **Add Two Binary Numbers**
1. Start from tails of both lists.  
2. Initialize carry = 0.  
3. While either list has nodes OR carry = 1:  
   - sum = carry  
   - If t1 exists → add t1->bit  
   - If t2 exists → add t2->bit  
   - Insert (sum % 2) at front of result  
   - carry = sum / 2  
4. Return result list.  

---

## **Output**

enter no of bits in binary no: 4
enter binary no: 1 0 0 1

1st binary no:
1 <-> 0 <-> 0 <-> 1 <-> NULL

1's complement:
0 <-> 1 <-> 1 <-> 0 <-> NULL

2's complement:
0 <-> 1 <-> 1 <-> 1 <-> NULL

enter no of bits in 2nd binary no: 4
enter 2nd binary no: 1 1 0 1

1st binary:
1 <-> 0 <-> 0 <-> 1 <-> NULL

2nd binary:
1 <-> 1 <-> 0 <-> 1 <-> NULL

sum:
1 <-> 0 <-> 1 <-> 1 <-> 0 <-> NULL