# Assignment No: 4 (UNIT 6)
# Title: Store and retrieve student records using roll numbers. 

## Concepts Used:
- Hash Table  
- Separate Chaining using Linked Lists  
- Student record with fields: Roll Number, Name, Marks  
- Hash function: roll_number % table_size  
- Insertion at head of linked list  
- Searching by roll number  
- Displaying all student records in table  

## Pseudocode:

### 1. Initialize Hash Table
Step 1: Input `size` of hash table  
Step 2: Initialize `table[size]` as array of null pointers  

### 2. Hash Function
Step 1: For a student roll number, return `roll_number % size`  

### 3. Insert Student Record
Step 1: Compute `index = hashFunction(roll_number)`  
Step 2: Create new student object with roll, name, marks  
Step 3: Create new node with student object  
Step 4: Insert node at beginning of linked list at `table[index]`  

### 4. Search Student Record
Step 1: Compute `index = hashFunction(roll_number)`  
Step 2: Traverse linked list at `table[index]`  
        Step 2.1: If node's roll number matches, print student details and return  
Step 3: If end of list reached, record not found  

### 5. Display Hash Table
Step 1: For each index from 0 to size-1:  
        Step 1.1: If linked list empty, print `Empty`  
        Step 1.2: Else, print all student records in linked list followed by `NULL`  

## Stepwise :
1. Input hash table size  
2. Initialize table as array of linked list heads  
3. Menu-driven operations:  
   - Insert student record with roll number, name, and marks  
   - Search student record by roll number  
   - Display all buckets with student records  
   - Exit program  

## Output:
Enter hash table size: 4

1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter choice: 1
Enter Roll Number: 12 
Enter Name: missy
Enter Marks: 50
Inserted roll 12 at bucket 0

1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter choice: 1
Enter Roll Number: 23
Enter Name: sheldon
Enter Marks: 79
Inserted roll 23 at bucket 3

1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter choice: 3

Hash Table (Student Records):
0 --> [Roll: 12, Name: missy, Marks: 50] -> NULL
1 --> Empty
2 --> Empty
3 --> [Roll: 23, Name: sheldon, Marks: 79] -> NULL

1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter choice: 2
Enter Roll Number to search: 23

Record Found:
Roll: 23
Name: sheldon
Marks: 79

1. Insert Student
2. Search Student
3. Display Table
4. Exit
Enter choice: 4

---