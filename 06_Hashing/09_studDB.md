# Assignment No: 9 (UNIT 5)  
# Title: WAP to simulate student databases as a hash table. a student database management system using hashing techniques to allow efficient insertion, search, and deletion of student records. 

## Concepts Used:
- Hash Table  
- Collision Resolution: Linear Probing  
- Lazy Deletion using a `deleted` flag  
- Student record with fields: Roll Number, Name  
- Searching, Inserting, Deleting by roll number  
- Displaying table content  

## Pseudocode:

### 1. Initialize Hash Table
Step 1: Input `size` of hash table  
Step 2: Initialize array of `Student` objects  
Step 3: Each slot contains `roll = -1`, `occ = false`, `del = false` (Empty)  

### 2. Hash Function
Step 1: For a roll number, return `roll % size`  

### 3. Insert Student Record
Step 1: Compute `index = hashFunc(roll)`  
Step 2: If table[index] is empty or marked deleted, insert record  
Step 3: Else, linearly probe to next empty or deleted slot  
Step 4: Insert record at first available slot  

### 4. Search Student Record
Step 1: Compute `index = hashFunc(roll)`  
Step 2: Traverse table linearly with wrap-around  
Step 3: If matching roll found and not deleted, display record  
Step 4: If full cycle without match, record not found  

### 5. Delete Student Record
Step 1: Compute `index = hashFunc(roll)`  
Step 2: Traverse table linearly with wrap-around  
Step 3: If matching roll found and not deleted, mark `del = true`  
Step 4: If full cycle without match, record not found  

### 6. Display Hash Table
Step 1: For each index 0 to size-1:  
- If slot is occupied and not deleted - print `Roll  Name`  
- Else - print `empty`  

## Stepwise :
1. Input hash table size  
2. Menu-driven operations:  
   - Insert student record  
   - Search student record by roll number  
   - Delete student record by roll number  
   - Display table  
   - Exit program  

## Output:

Enter table size: 7

Insert Student

Search Student

Delete Student

Display

Exit
Enter choice: 1
Enter roll and name: 12 Alice

Enter choice: 1
Enter roll and name: 7 MEERA

Enter choice: 1
Enter roll and name: 23 SIMPLE

Enter choice: 4

---- Student Hash Table ----
0 : empty
1 : 23 SIMPLE
2 : 12 Alice
3 : 7 MEERA
4 : empty
5 : empty
6 : empty

Enter choice: 2
Enter roll to search: 7

Student Found:
Roll: 7 Name: MEERA

Enter choice: 3
Enter roll to delete: 12

Student Deleted

Enter choice: 4

---- Student Hash Table ----
0 : empty
1 : 23 SIMPLE
2 : empty
3 : 7 MEERA
4 : empty
5 : empty
6 : empty

---