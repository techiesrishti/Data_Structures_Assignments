# Assignment No: 6 (UNIT 6)  
# Title: WAP to simulate a faculty database as a hash table. Search a particular faculty by using 'divide' as a hash function for linear probing with chaining without replacement method of collision handling technique. Assume suitable data for faculty record.

## Concepts Used:
- Hash Table  
- Collision Resolution:
  - Primary: Linear Probing  
  - Secondary: Chaining via `next` indices  
- Faculty record with fields: ID, Name, Department  
- Hash function: `id % table_size`  
- Searching by faculty ID  
- Displaying the table with `next` links for chaining  

## Pseudocode:

### 1. Initialize Hash Table
Step 1: Input `size` of hash table  
Step 2: Initialize array of `Faculty` objects  
Step 3: Each slot contains `id = -1` and `next = -1` (Empty)  

### 2. Hash Function
Step 1: For a faculty ID, return `id % size`  

### 3. Insert Faculty Record
Step 1: Compute `index = hashFunction(id)`  
Step 2: If table[index] is empty, insert record  
Step 3: Else, find first free index in table  
Step 4: Insert record at free index  
Step 5: Traverse chain starting from `index` and link the last node's `next` to the new index  

### 4. Search Faculty Record
Step 1: Compute `index = hashFunction(id)`  
Step 2: Traverse chain using `next` links  
Step 3: If matching ID found, display record  
Step 4: If end of chain reached without match, record not found  

### 5. Display Hash Table
Step 1: For each index 0 to size-1:  
- If ID == -1 → `EMPTY`  
- Else → print `[ID, Name, Dept, Next]`  

## Stepwise :
1. Input hash table size  
2. Initialize table as array of faculty objects with `next = -1`  
3. Menu-driven operations:  
   - Insert faculty record  
   - Search faculty record by ID  
   - Display table including `next` links  
   - Exit program  

## Output:
Enter Hash Table Size: 5

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 1
Enter Faculty ID: 11
Enter Name: Prof.Vishal_Sir
Enter Department: Computer

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 1
Enter Faculty ID: 343
Enter Name: Prof.Vivek_Sir
Enter Department: Mechanical

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 3

--- Faculty Hash Table Linear Probing with chaining ---

[0]  EMPTY
[1]  ID: 11, Name: Prof.Vishal_Sir, Dept: Computer, Next = -1
[2]  EMPTY
[3]  ID: 343, Name: Prof.Vivek_Sir, Dept: Mechanical, Next = -1
[4]  EMPTY

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 2
Enter Faculty ID to search: 11

Faculty Found:
ID: 11
Name: Prof.Vishal_Sir
Department: Computer

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 4

---