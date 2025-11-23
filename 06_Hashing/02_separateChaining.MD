# Assignment No: 2 (UNIT 6)  
# Title: Implement collision handling using separate chaining.

## Concepts Used:
- Hash Table  
- Separate Chaining for collision resolution  
- Hash function: key % table_size  
- Vector of vectors to store chains  
- Searching, inserting, and displaying elements  

## Pseudocode:

### 1. Initialize Hash Table
Step 1: Input `size` of hash table  
Step 2: Initialize `table[size]` as empty lists (vectors)  

### 2. Hash Function
Step 1: For a key, return `key % size`  

### 3. Insert Key
Step 1: Compute `index = hashFunction(key)`  
Step 2: Append `key` to `table[index]`  

### 4. Search Key
Step 1: Compute `index = hashFunction(key)`  
Step 2: For each element `val` in `table[index]`:  
        Step 2.1: If `val == key`, key found in bucket; return  
Step 3: If not found, print key not found  

### 5. Display Table
Step 1: For each index from 0 to size-1:  
        Step 1.1: If `table[index]` is empty, print `Empty`  
        Step 1.2: Else, print all elements in the chain followed by `NULL`  

## Stepwise :
1. Input hash table size  
2. Initialize table as vector of empty vectors  
3. Menu-driven operations:  
   - Insert key into respective bucket  
   - Search key in bucket  
   - Display all buckets with chained elements  
   - Exit  

## Output:
Enter hash table size: 4

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter key to insert: 44
Inserted 44 at bucket 0

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter key to insert: 56
Inserted 56 at bucket 0

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 2
Enter key to search: 56
56 found in bucket 0

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 3

Hash Table (Separate Chaining):
0 --> 44 -> 56 -> NULL
1 --> Empty
2 --> Empty
3 --> Empty

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter key to insert: 12
Inserted 12 at bucket 0

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter key to insert: 9
Inserted 9 at bucket 1

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 2
Enter key to search: 9
9 found in bucket 1

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 3

Hash Table (Separate Chaining):
0 --> 44 -> 56 -> 12 -> NULL
1 --> 9 -> NULL
2 --> Empty
3 --> Empty

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 4

---