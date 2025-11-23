# Assignment No: 7 (UNIT 6)  
# Title: WAP to simulate a faculty database as a hash table. Search a particular faculty by using MOD as a hash function for linear probing with chaining with replacement method of collision handling technique. Assume suitable data for faculty record.

## Concepts Used:
- Hash Table  
- Collision Resolution: Modified Linear Probing (Robin Hood variant)  
- Faculty record with fields: ID, Name  
- Hash function: `id % table_size`  
- Searching by faculty ID  
- Displaying table content  

## Pseudocode:

### 1. Initialize Hash Table
Step 1: Input `size` of hash table  
Step 2: Initialize array of `Faculty` objects  
Step 3: Each slot contains `id = -1` and `occ = false` (Empty)  

### 2. Hash Function
Step 1: For a faculty ID, return `id % size`  

### 3. Insert Faculty Record
Step 1: Compute `index = hashFunction(id)`  
Step 2: If table[index] is empty, insert record  
Step 3: Else, check occupant’s home position  
- If occupant not at home index, swap with new record  
Step 4: Find next available empty slot (linear probing)  
Step 5: Insert displaced record at free slot  

### 4. Search Faculty Record
Step 1: Compute `index = hashFunction(id)`  
Step 2: Traverse table linearly with wrap-around  
Step 3: If matching ID found, display record  
Step 4: If full cycle without match, record not found  

### 5. Display Hash Table
Step 1: For each index 0 to size-1:  
- If `occ == false` → print `empty`  
- Else → print `ID  Name`  

## Stepwise :
1. Input hash table size  
2. Input number of faculty  
3. For each faculty, input `ID` and `Name`  
4. Insert into hash table using Robin Hood linear probing  
5. Display hash table after all insertions  
6. Input faculty ID to search  
7. Display search result  
8. Program terminates  

## Output:

Enter table size: 5
Enter number of faculty: 3
Enter ID and Name: 12 Prof.Disha_Ma'am
Enter ID and Name: 7 Prof.Vishal_Sir
Enter ID and Name: 17 Prof.Sandeep_Sir

---- Faculty Hash Table ----
0 : empty
1 : 17 Prof.Sandeep_Sir
2 : 12 Prof.Disha_Ma'am
3 : 7 Prof.Vishal_Sir
4 : empty

Enter faculty ID to search: 7

Faculty Found:
ID: 7 Name: Prof.Vishal_Sir

---