# **Assignment No: 2**
## **Title:**  
Implementation of Doubly Linked List with Operations: Insert at Head, Insert at Tail, Insert at Position, Delete Node, Traverse, and Find Length.

---

## **Concepts Used**
- Doubly Linked List  
- Dynamic Memory Allocation  
- Node Creation & Deletion  
- Traversal  
- Insertion Operations  
- Deletion Operations  
- Pointer Manipulation  
- Memory Handling Using Destructors  

---

## **Pseudocode**

---

## **Node Structure**
1. Define class Node with:
   - data (integer)
   - prev pointer
   - next pointer
2. Constructor initializes data, prev = NULL, next = NULL.
3. Destructor prints a message and frees memory.

---

## **1. Traverse / Print List**
1. Set temp = head.
2. While temp is not NULL:
   - Print temp.data.
   - Move temp to temp.next.
3. End.

---

## **2. Get Length of Doubly Linked List**
1. Initialize count = 0.
2. Set temp = head.
3. While temp ≠ NULL:
   - Increment count.
   - Move temp = temp.next.
4. Return count.

---

## **3. Insert at Head**
1. If head is NULL:
   - Create newNode.
   - Set head = tail = newNode.
2. Else:
   - Create newNode.
   - Set newNode.next = head.
   - Set head.prev = newNode.
   - Update head = newNode.

---

## **4. Insert at Tail**
1. If tail is NULL:
   - Create newNode.
   - Set head = tail = newNode.
2. Else:
   - Create newNode.
   - Set tail.next = newNode.
   - Set newNode.prev = tail.
   - Update tail = newNode.

---

## **5. Insert at Position**
1. If position = 1:
   - Call insertAtHead().
2. Traverse from head until position − 1.
3. If inserting at last:
   - Call insertAtTail().
4. Else:
   - Create newNode.
   - Set newNode.next = temp.next.
   - Set newNode.prev = temp.
   - Adjust pointers:
     - temp.next.prev = newNode
     - temp.next = newNode

---

## **6. Delete a Node**
1. If position = 1:
   - Store temp = head.
   - Update head = head.next.
   - Set head.prev = NULL.
   - Delete temp.
2. Else:
   - Traverse to given position.
   - Adjust prev and next pointers:
     - prev.next = curr.next
     - If curr.next exists, set curr.next.prev = prev
   - Delete curr.

---

## **Output**

List:
Length = 0

Inserting 11 at head:
11

Inserting 9 at head:
9 11

Inserting 8 at head:
8 9 11

Inserting 25 at tail:
8 9 11 25

Insert 100 at position 2:
8 100 9 11 25

Insert 101 at position 1:
101 8 100 9 11 25

Head = 101
Tail = 25

Insert 102 at position 7:
101 8 100 9 11 25 102

Delete node at position 7:
101 8 100 9 11 25

Tail = 25