# Assignment No: 10 (UNIT 6)  
# Title: Design and implement a smart college placement portal that uses advanced hashing techniques to efficiently manage student placement records with high performance and low collision probability, even under dynamic data growth.

## Concepts Used:
- Hash Table  
- Collision Resolution: Double Hashing  
  - Primary hash: `h1(k) = k % table_size`  
  - Secondary hash: `h2(k) = r - (k % r)` (r is a small prime < table_size)  
- Dynamic rehashing (table doubles in size when full)  
- Placement record with fields: ID, Name, Company, Package  
- Searching, Inserting, Deleting by student ID  
- Displaying the table  

## Pseudocode:

### 1. Initialize Placement Portal
Step 1: Input initial `size` of hash table  
Step 2: Initialize array of `Student` objects  
Step 3: Each slot contains `id = -1` and `used = false` (Empty)  

### 2. Hash Functions
- Primary hash: `h1(k) = k % size`  
- Secondary hash: `h2(k) = r - (k % r)`  

### 3. Insert Student Record
Step 1: Compute `idx = (h1(id) + i * h2(id)) % size` for i = 0,1,...  
Step 2: If table[idx] is empty, insert record  
Step 3: Else, increment i and try next slot  
Step 4: If table is full, perform rehash (double table size) and reinsert all records  

### 4. Search Student Record
Step 1: Compute `idx = (h1(id) + i * h2(id)) % size`  
Step 2: Check table[idx]  
Step 3: If ID matches and slot used → display record  
Step 4: Else increment i and repeat until full cycle  
Step 5: If not found → record not found  

### 5. Delete Student Record
Step 1: Compute `idx = (h1(id) + i * h2(id)) % size`  
Step 2: If ID matches and slot used → mark `used = false`  
Step 3: Else increment i and repeat until full cycle  
Step 4: If not found → record not found  

### 6. Display Hash Table
Step 1: For each index 0 to size-1:  
- If slot is used - print `ID, Name, Company, Package`  
- Else - print `empty`  

## Stepwise :
1. Initialize Placement Portal with a table of given size  
2. Menu-driven operations:  
   - Insert student record  
   - Search student record by ID  
   - Delete student record by ID  
   - Display table  
   - Exit program  

## Output:


1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 1
Enter ID Name Company Package: 111 Missy IBM 14

1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 1
Enter ID Name Company Package: 232 Manav Persistent 16

1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 1
Enter ID Name Company Package: 333 Simple Google 40

1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 1
Enter ID Name Company Package: 109 Dimple Meta 30

1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 4

--- Placement Records ---
0 -> empty
1 -> ID:111  Name:Missy  Company:IBM  Package:14
2 -> ID:232  Name:Manav  Company:Persistent  Package:16
3 -> ID:333  Name:Simple  Company:Google  Package:40
4 -> empty
5 -> empty
6 -> empty
7 -> empty
8 -> empty
9 -> ID:109  Name:Dimple  Company:Meta  Package:30

1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 2
Enter ID: 109

Record Found:
ID: 109
Name: Dimple
Company: Meta
Package: 30

1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 3
Enter ID: 109

Record Deleted

1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 4

--- Placement Records ---
0 -> empty
1 -> ID:111  Name:Missy  Company:IBM  Package:14
2 -> ID:232  Name:Manav  Company:Persistent  Package:16
3 -> ID:333  Name:Simple  Company:Google  Package:40
4 -> empty
5 -> empty
6 -> empty
7 -> empty
8 -> empty
9 -> empty

1.Insert
2.Search
3.Delete
4.Display
5.Exit
Enter choice: 5

---