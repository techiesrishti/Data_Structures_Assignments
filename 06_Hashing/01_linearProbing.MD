# Assignment No: 1 (UNIT 6)  
# Title: Implement a hash table with collision resolution using linear probing.  

## Concepts Used:
- Hash Table  
- Linear Probing for collision resolution  
- Hash function: key % table_size  
- Searching, inserting, and displaying elements  
- Handling full table conditions  
- STL container: vector  

## Pseudocode:

### 1. Initialize Hash Table
Step 1: Input `size` of hash table  
Step 2: Initialize `table[size]` with `-1` (empty)  

### 2. Hash Function
Step 1: For a key, return `key % size`  

### 3. Insert Key
Step 1: Compute `index = hashFunction(key)`  
Step 2: Store `start = index`  
Step 3: While `table[index] != -1`:  
        Step 3.1: Increment `index = (index + 1) % size`  
        Step 3.2: If `index == start`, table is full; return  
Step 4: Insert `key` at `table[index]`  

### 4. Search Key
Step 1: Compute `index = hashFunction(key)`  
Step 2: Store `start = index`  
Step 3: While `table[index] != -1`:  
        Step 3.1: If `table[index] == key`, key found at `index`; return  
        Step 3.2: Increment `index = (index + 1) % size`  
        Step 3.3: If `index == start`, key not found; break  
Step 4: Key not found  

### 5. Display Table
Step 1: For each index from 0 to size-1:  
        Step 1.1: Print `index --> table[index]` or `Empty`  

## Stepwise :
1. Input hash table size  
2. Initialize table with -1  
3. Menu-driven operations:  
   - Insert key using linear probing  
   - Search key  
   - Display table  
   - Exit  

## Output:
Enter hash table size: 5

1. Insert
2. Search
3. Display

Exit
Enter choice: 1
Enter key to insert: 12
Inserted 12 at index 2

1. Insert
2. Search
3. Display

Exit
Enter choice: 1
Enter key to insert: 7
Inserted 7 at index 3

Search
Enter key to search: 12
12 found at index 2

Display
Hash Table:
0 --> Empty
1 --> Empty
2 --> 12
3 --> 7
4 --> Empty

---