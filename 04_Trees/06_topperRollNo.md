# **Assignment No: 6 (UNIT 4)**
# **Title:** Write a program, using trees, to assign the roll nos. to the students of your class as per their previous years result. i.e topper will be roll no. 1

---

## Concepts Used
- Binary Search Tree (BST) where nodes contain student `name` and `marks`.
- Insertion into BST based on marks (marks used as key for ordering).
- Inorder traversal (ascending marks) or reverse inorder traversal (descending marks).
- Roll numbers assigned based on descending marks (topper gets Roll No. 1).

---

## PseudoCode

**STEP 1:** Start  

**STEP 2:** Initialize BST:  
root_sp = NULL
roll_sp = 1


**STEP 3:** Input number of students (`n_sp`)  

**STEP 4:** For each student:
- Input `name_sp` and `marks_sp`
- Insert node into BST based on marks:
  - IF BST empty → create root node
  - ELSE → recursively insert:
    - IF marks < current node marks → go left
    - ELSE → go right

**STEP 5:** Assign roll numbers based on marks (descending order):
- Perform reverse inorder traversal:
  - Visit right subtree (higher marks)
  - Assign current roll number to student and increment roll counter
  - Visit left subtree (lower marks)

**STEP 6:** Display student names with assigned roll numbers  

**STEP 7:** End

---

## Output

Enter number of students: 3

Enter name of student 1: Himanshi
Enter marks of Himanshi: 85

Enter name of student 2: Simple
Enter marks of Simple: 92

Enter name of student 3: Dev
Enter marks of Dev: 78

--- Roll Number Assignment Based on Marks ---
Topper gets Roll No. 1 

Roll No. 1 -> Simple (Marks: 92)
Roll No. 2 -> Himanshi (Marks: 85)
Roll No. 3 -> Dev (Marks: 78)

---
