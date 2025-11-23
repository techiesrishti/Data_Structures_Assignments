# Assignment No: 8 (UNIT 6)  
# Title: WAP to simulate employee databases as a hash table. Search a particular faculty by using Mid square method as a hash function for linear probing method of collision handling technique. Assume suitable data for faculty record.

## Concepts Used:
- Hash Table  
- Hash Function: Mid-Square Method  
- Collision Resolution: Linear Probing  
- Employee record with fields: ID, Name  
- Searching by employee ID  
- Displaying table content  

## Pseudocode:

### 1. Initialize Hash Table
Step 1: Input `size` of hash table  
Step 2: Initialize array of `Employee` objects  
Step 3: Each slot contains `id = -1` and `occ = false` (Empty)  

### 2. Mid-Square Hash Function
Step 1: Square the employee ID  
Step 2: Convert to string  
Step 3: Extract middle two digits  
Step 4: Convert back to integer and return `num % size`  

### 3. Insert Employee Record
Step 1: Compute `index = midSquareHash(id)`  
Step 2: If table[index] is empty, insert record  
Step 3: Else, linearly probe to next empty slot  
Step 4: Insert record at first available slot  

### 4. Search Employee Record
Step 1: Compute `index = midSquareHash(id)`  
Step 2: Traverse table linearly with wrap-around  
Step 3: If matching ID found, display record  
Step 4: If full cycle without match, record not found  

### 5. Display Hash Table
Step 1: For each index 0 to size-1:  
- If `occ == false` → print `empty`  
- Else → print `ID  Name`  

## Stepwise :
1. Input hash table size  
2. Input number of employees  
3. For each employee, input `ID` and `Name`  
4. Insert into hash table using mid-square hashing and linear probing  
5. Display hash table after all insertions  
6. Input employee ID to search  
7. Display search result  
8. Program terminates  

## Output:

Enter table size: 4
Enter number of employees: 3
Enter ID and Name: 111 Meera
Enter ID and Name: 222 Missy
Enter ID and Name: 333 Sheldon

---- Employee Hash Table ----
0 : 222  Missy
1 : 333  Sheldon
2 : empty
3 : 111  Meera

Enter Employee ID to search: 111

Employee Found:
ID: 111  Name: Meera

---