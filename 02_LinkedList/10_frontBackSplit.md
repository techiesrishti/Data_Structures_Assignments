# Assignment No: 10 (UNIT – 2)

## Title
Given a list, split it into two sublists — one for the front half, and one for the back half. If the number of elements is odd, the extra element should go in the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}. Getting this right for all the cases is harder than it looks. You should check your solution against a few cases (length = 2, length = 3, length=4) to make sure that the list gets split correctly near the shortlist boundary conditions. If it works right for length=4, it probably works right for length=1000. You will probably need special case code to deal with the (length <2) cases.

## Concepts Used
- Singly Linked List  
- Dynamic Memory Allocation  
- Slow and Fast Pointer Technique  
- Splitting Linked List into Two Halves  
- Exception Handling (invalid_argument)  
- Linked List Traversal  

## Pseudocode

### INSERT_AT_END(value)
1. Create new node with given value  
2. If head is NULL → head = new node  
3. Else  
   - Traverse to end  
   - Attach new node at end  

### DISPLAY_LIST
1. Start at head  
2. Print each node’s data → "->" → next node  
3. End with "NULL"  

### FRONT_BACK_SPLIT(front, back)
1. If list is empty → throw error  
2. If list has only one node → throw error  
3. Initialize  
   - slow = head  
   - fast = head->next  
4. While fast not NULL  
   - Move fast = fast->next  
   - If fast not NULL  
     - Move slow = slow->next  
     - Move fast = fast->next  
5. After loop ends:  
   - front.head = head  
   - back.head = slow->next  
   - slow->next = NULL  
6. Set original list head = NULL  

### MAIN FUNCTION
1. Input number of nodes  
2. Insert values  
3. Display list  
4. Try calling FrontBackSplit()  
5. Display front and back lists  
6. Catch exceptions if any  

## Output

enter no of elements in the list: 6
enter elements: 10 20 30 40 50 60

List: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL
front half of the list: 10 -> 20 -> 30 -> NULL
back half of the list: 40 -> 50 -> 60 -> NULL