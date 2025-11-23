# Assignment No: 3 (UNIT 6)  
# Title: Implement collision resolution using linked lists. 

## Concepts Used:
- Hash Table  
- Separate Chaining for collision resolution  
- Linked List for handling collisions  
- Hash function: key % table_size  
- Insertion at head of linked list  
- Searching in linked list  
- Displaying hash table contents  

## Pseudocode:

### 1. Initialize Hash Table
Step 1: Input `size` of hash table  
Step 2: Initialize `table[size]` as array of null pointers  

### 2. Hash Function
Step 1: For a key, return `key % size`  

### 3. Insert Key
Step 1: Compute `index = hashFunction(key)`  
Step 2: Create a new node with `key`  
Step 3: Insert new node at the beginning of `table[index]` linked list  

### 4. Search Key
Step 1: Compute `index = hashFunction(key)`  
Step 2: Traverse linked list at `table[index]`  
        Step 2.1: If a node's data equals `key`, key found; return  
Step 3: If end of list reached, key not found  

### 5. Display Table
Step 1: For each index from 0 to size-1:  
        Step 1.1: If linked list empty, print `Empty`  
        Step 1.2: Else, print all node values followed by `NULL`  

## Stepwise :
1. Input hash table size  
2. Initialize table as array of linked list heads  
3. Menu-driven operations:  
   - Insert key into respective bucket using linked list  
   - Search key in linked list of bucket  
   - Display all buckets with linked list contents  
   - Exit  

## Output:
Enter hash table size: 4

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter key to insert: 33
Inserted 33 at bucket 1

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter key to insert: 55
Inserted 55 at bucket 3

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter key to insert: 77
Inserted 77 at bucket 1

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter key to insert: 11
Inserted 11 at bucket 3

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 3

Hash Table (Separate Chaining using Linked Lists):
0 --> Empty
1 --> 77 -> 33 -> NULL
2 --> Empty
3 --> 11 -> 55 -> NULL

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 2
Enter key to search: 77
77 found in bucket 1

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 4

---