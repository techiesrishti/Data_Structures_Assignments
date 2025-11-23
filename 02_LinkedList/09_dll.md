# Assignment No: 9 (UNIT 2)

## Title
WAP to create a doubly linked list and perform following operations on it.A) Insert (all cases) 2. Delete (all cases).

## Concepts Used
- Doubly Linked List  
- Dynamic memory allocation  
- Bidirectional traversal (prev & next)  
- Insert at head  
- Insert at tail  
- Insert at any position  
- Delete node  
- Count length  
- Menu-driven program structure  

## Pseudocode

### INSERT_AT_HEAD(data)
1. If head is NULL  
   - Create new node  
   - head = tail = new node  
2. Else  
   - Create new node  
   - newNode.next = head  
   - head.prev = newNode  
   - head = newNode  

### INSERT_AT_TAIL(data)
1. If tail is NULL  
   - Create new node  
   - head = tail = new node  
2. Else  
   - Create new node  
   - tail.next = newNode  
   - newNode.prev = tail  
   - tail = newNode  

### INSERT_AT_POSITION(pos, data)
1. If pos == 1 → call INSERT_AT_HEAD  
2. Traverse list until position-1  
3. If reached tail → call INSERT_AT_TAIL  
4. Else  
   - Create new node  
   - Link it between nodes using next & prev  

### DELETE_NODE(position)
1. If position == 1  
   - temp = head  
   - head = head.next  
   - head.prev = NULL  
   - delete temp  
2. Else  
   - Traverse to node at given position  
   - Connect prev and next pointers  
   - Delete the node  

### DISPLAY_LIST
1. Start at head  
2. Print node.data  
3. Move to next until NULL  

### LENGTH
1. Initialize count = 0  
2. Traverse from head  
3. Increment count  
4. Return count  

##  Output
----------doubly linked list implementation ----------

Insert at Head

Insert at Tail

Insert at Position

Delete Node

Display Linked List

Display Length

Exit
Enter your choice: 1
Enter data to insert at head: 10
10 <-> NULL

Enter your choice: 2
Enter data to insert at tail: 20
10 <-> 20 <-> NULL

Enter your choice: 3
Enter position and data: 2 15
10 <-> 15 <-> 20 <-> NULL

Enter your choice: 4
Enter position to delete: 2
10 <-> 20 <-> NULL

Enter your choice: 6
Length of Linked List: 2

Enter your choice: 0
Exiting program...
