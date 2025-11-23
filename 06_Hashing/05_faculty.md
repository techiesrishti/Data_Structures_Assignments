# Assignment No: 5 (UNIT 6)  
# Title: WAP to simulate a faculty database as a hash table. Search a particular faculty by using MOD as a hash function for linear probing method of collision handling technique. Assume suitable data for faculty record. 

## Concepts Used:
- Hash Table  
- Open Addressing with Linear Probing  
- Faculty record with fields: ID, Name, Department  
- Hash function: `id % table_size`  
- Collision resolution using linear probing  
- Searching by faculty ID  
- Displaying all faculty records in table  

## Pseudocode:

### 1. Initialize Hash Table
Step 1: Input `size` of hash table  
Step 2: Initialize array of `Faculty` objects with ID = -1 (Empty)  

### 2. Hash Function
Step 1: For a faculty ID, return `id % size`  

### 3. Insert Faculty Record
Step 1: Compute `index = hashFunction(id)`  
Step 2: If table[index] is empty (ID == -1), insert record  
Step 3: Else, use linear probing:  
        Step 3.1: index = (index + 1) % size  
        Step 3.2: Repeat until empty slot found or table is full  

### 4. Search Faculty Record
Step 1: Compute `index = hashFunction(id)`  
Step 2: Traverse table using linear probing:  
        Step 2.1: If table[index].ID matches, display record and return  
        Step 2.2: If empty slot reached or returned to start index, record not found  

### 5. Display Hash Table
Step 1: For each index from 0 to size-1:  
        Step 1.1: If ID == -1, print `Empty`  
        Step 1.2: Else, print `[ID, Name, Department]`  

## Stepwise :
1. Input hash table size  
2. Initialize table as array of faculty objects  
3. Menu-driven operations:  
   - Insert faculty record with ID, Name, and Department  
   - Search faculty record by ID  
   - Display all table slots with faculty details  
   - Exit program  

## Output:
Enter hash table size: 4

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 1
Enter Faculty ID: 111
Enter Name: Prof.Vishal_Sir
Enter Department: Computer
Inserted at index 3

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 1
Enter Faculty ID: 323
Enter Name: Prof.Disha_Ma'am
Enter Department: Computer
Inserted at index 0

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 3

--- Faculty Hash Table ---
0: [ID: 323, Name: Prof.Disha_Ma'am, Dept: Computer]
1: Empty
2: Empty
3: [ID: 111, Name: Prof.Vishal_Sir, Dept: Computer]

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 1
Enter Faculty ID: 444
Enter Name: Prof.Sandeep_Sir
Enter Department: IT
Inserted at index 1

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 2
Enter Faculty ID to search: 111

Faculty Found:
ID: 111
Name: Prof.Vishal_Sir
Department: Computer

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 3

--- Faculty Hash Table ---
0: [ID: 323, Name: Prof.Disha_Ma'am, Dept: Computer]
1: [ID: 444, Name: Prof.Sandeep_Sir, Dept: IT]
2: Empty
3: [ID: 111, Name: Prof.Vishal_Sir, Dept: Computer]

1. Insert Faculty
2. Search Faculty
3. Display Table
4. Exit
Enter choice: 4

---
