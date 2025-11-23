# Assignment No: 8 (UNIT 2)

## Title  
Implement Bubble sort using Doubly Linked List

## Concepts Used  
- Doubly Linked List  
- Node creation (prev and next pointers)  
- Traversal forward  
- Bubble Sort algorithm  
- Swapping node data  
- Dynamic memory allocation  
- Destructor for cleanup  

## Pseudocode

### insertAtEnd(value)
1. Create a new node with given value  
2. If list is empty:  
   - head = new node  
   - tail = new node  
3. Else  
   - Set tail->next = new node  
   - Set new node’s prev = tail  
   - Update tail = new node  

### display()
1. Start from head  
2. Print data of each node  
3. Move to next node until NULL  

### bubbleSort()
1. If list is empty → return  
2. Set swapped = true  
3. Set last pointer = NULL  
4. Repeat while swapped is true:  
   - Set swapped = false  
   - Start pointer ptr = head  
   - While ptr->next != last:  
     - If ptr->data > ptr->next->data  
       - Swap values  
       - swapped = true  
     - Move ptr to ptr->next  
   - Update last = ptr  
5. Sorting completes when no swap occurs in a full pass  

## Output
enter no of elements: 5
enter elements: 7 3 9 1 4

list: 7 <-> 3 <-> 9 <-> 1 <-> 4 <-> NULL

sorted using bubble sort: 1 <-> 3 <-> 4 <-> 7 <-> 9 <-> NULL
