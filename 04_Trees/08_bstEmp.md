# **Assignment No: 8 (UNIT 4)**
# **Title:** Write a program to efficiently search a particular employee record by using Tree data structure. Also sort the data on emp­id in ascending order.

---

## Concepts Used
- Binary Search Tree (BST) for storing Employee Records.
- Employee structure: `emp_id_sp`, `name_sp`, `salary_sp`.
- BST Operations:
  - Insert Employee
  - Search Employee by ID
  - Display Employees in sorted order (Inorder)
  - Display Tree in horizontal format
- Tree height calculation for proper display spacing.

---

## Pseudocode

**STEP 1:** Start

**STEP 2:** Initialize BST:
root_sp = NULL


**STEP 3:** Display Menu:
1. Insert Employee Record
2. Search Employee by ID
3. Display All Employees (Sorted by ID)
4. Display Tree 
5. Exit

**STEP 4:** Repeat until choice == 5:
- **Insert Employee**:
  - Input `emp_id_sp`, `name_sp`, `salary_sp`
  - Recursively insert in BST using `emp_id_sp` as key:
    - IF id < node->emp_id → go left
    - ELSE → go right
- **Search Employee by ID**:
  - Input `id_sp`
  - Recursively traverse BST:
    - IF node->emp_id == id → found
    - ELSE IF id < node->emp_id → left
    - ELSE → right
- **Display Employees (Inorder)**:
  - Traverse BST inorder
  - Print Employee Records sorted by ID
- **Display Tree**:
  - Compute height
  - Print tree level by level with spacing

**STEP 5:** End

---

## Output

-----------MENU---------------
1. Insert Employee Record
2. Search Employee by ID
3. Display All Employees (Sorted by ID)
4. Display Tree 
5. Exit
------------------------------
Enter your choice: 1
Enter Employee ID: 123
Enter Employee Name: harry
Enter Salary: 30000

-----------MENU---------------
1. Insert Employee Record
2. Search Employee by ID
3. Display All Employees (Sorted by ID)
4. Display Tree 
5. Exit
------------------------------
Enter your choice: 1
Enter Employee ID: 343
Enter Employee Name: shiv
Enter Salary: 24000 

-----------MENU---------------
1. Insert Employee Record
2. Search Employee by ID
3. Display All Employees (Sorted by ID)
4. Display Tree 
5. Exit
------------------------------
Enter your choice: 2
Enter Employee ID to search: 343
Employee Found -> ID: 343, Name: shiv, Salary: 24000

-----------MENU---------------
1. Insert Employee Record
2. Search Employee by ID
3. Display All Employees (Sorted by ID)
4. Display Tree 
5. Exit
------------------------------
Enter your choice: 3

Employees (Sorted by ID):
EmpID: 123 | Name: harry | Salary: 30000
EmpID: 343 | Name: shiv | Salary: 24000

-----------MENU---------------
1. Insert Employee Record
2. Search Employee by ID
3. Display All Employees (Sorted by ID)
4. Display Tree 
5. Exit
------------------------------
Enter your choice: 4

Employee BST :

      123

         343


-----------MENU---------------
1. Insert Employee Record
2. Search Employee by ID
3. Display All Employees (Sorted by ID)
4. Display Tree 
5. Exit
------------------------------
Enter your choice: 5
Exiting...

---