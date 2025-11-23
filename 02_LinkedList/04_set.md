# **Assignment No: 4**

## **Title:**  
In the Second Year Computer Engineering class, there are two groups of students based on their favorite sports:
●	Set A includes students who like Cricket.
●	Set B includes students who like Football.
Write a C++ program to represent these two sets using linked lists and perform the following operations:
- Find and display the set of students who like both Cricket and Football.
- Find and display the set of students who like either Cricket or Football, but not both.
- Display the number of students who like neither Cricket nor Football.

---

## **Concepts Used**
- Singly Linked List  
- Node Insertion  
- Traversal  
- Searching in Linked List  
- Set Operations  
  - Students liking both (Intersection)  
  - Students liking either but not both (Symmetric Difference)  
  - Students liking neither (Using Union Count)  
- Dynamic Memory Allocation  
- Freeing Memory  

---

## **Pseudocode**

---

### **Node Structure**
1. Create structure `Node` with:
   - `roll` (integer)  
   - `next` (pointer to Node)

---

### **Insert Node (End Insertion)**
1. Create new node with roll number.
2. If list empty → head = new node.
3. Else traverse to last node.
4. Attach new node at the end.

---

### **Display List**
1. If head is NULL → print "List empty".
2. Else traverse from head:
   - Print each roll → until NULL.

---

### **Check if Roll Exists (contains)**
1. Traverse from head.
2. If any node's roll equals target → return true.
3. If end reached → return false.

---

### **Count Nodes**
1. Initialize count = 0.
2. Traverse whole list.
3. Increment count each time.
4. Return count.

---

### **Operation 1: Students Who Like Both (Intersection)**
1. Set tempA = head of cricket list.
2. For each node in cricket:
   - If football.contains(tempA.roll) → print roll.
3. If none found → print "None".

---

### **Operation 2: Students Who Like Either but Not Both (Symmetric Difference)**
1. For each student in cricket:
   - If NOT in football → print roll.
2. For each student in football:
   - If NOT in cricket → print roll.

---

### **Operation 3: Students Who Like Neither**
1. Compute union count:
   - Count all cricket students.
   - Add all football students not present in cricket.
2. neither = totalStudents – unionCount.
3. Print neither.

---

### **Free Memory**
1. Traverse through list:
   - Delete node one by one.

---

## **Output**

Enter total number of students in class 10

Enter number of students who like Cricket 4
Enter their roll numbers
1 2 3 4

Enter number of students who like Football 3
Enter their roll numbers
3 4 6

Cricket (Set A): 1 -> 2 -> 3 -> 4 -> NULL
Football (Set B): 3 -> 4 -> 6 -> NULL

Students who like both Cricket and Football: 3 4

Students who like either Cricket or Football but not both:
1 2 6

number of students who like neither Cricket nor Football: 3