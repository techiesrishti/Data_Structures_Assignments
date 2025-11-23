# **Assignment No: 7 (UNIT 4)**
# **Title:** Write a program to illustrate operations on a BST holding numeric keys. The menu must include: • Insert • Delete • Find • Show

---

## Concepts Used
- Binary Search Tree (BST) with numeric keys.
- Node structure: `key_sp`, `left_sp`, `right_sp`.
- BST Operations:
  - Insert Node
  - Delete Node
  - Find/Search Node
  - Display BST in a horizontal/pyramid style
- Height calculation for proper spacing in display.

---

## PseudoCode

**STEP 1:** Start  

**STEP 2:** Initialize BST:  
root_sp = NULL


**STEP 3:** Display Menu:
1. Insert Node
2. Delete Node
3. Find Node
4. Display BST
5. Exit

**STEP 4:** Repeat until choice == 5:
- **Insert Node**:
  - Input `value_sp`
  - Recursively insert in BST:
    - IF value < node->key → go left
    - ELSE → go right
- **Delete Node**:
  - Input `value_sp`
  - Recursively find node:
    - IF node has no child → delete directly
    - IF node has one child → replace node with child
    - IF node has two children → find inorder successor, replace, delete successor
- **Find Node**:
  - Input `value_sp`
  - Recursively search:
    - IF node->key == value → found
    - IF value < node->key → go left
    - ELSE → go right
- **Display BST**:
  - Compute height
  - Print tree level by level with spacing

**STEP 5:** End

---

## Output

-----------MENU---------------
1. Insert Node
2. Delete Node
3. Find Node
4. Display BST
5. Exit
------------------------------
Enter your choice: 1
Enter numeric key to insert: 13

-----------MENU---------------
1. Insert Node
2. Delete Node
3. Find Node
4. Display BST
5. Exit
------------------------------
Enter your choice: 1
Enter numeric key to insert: 66

-----------MENU---------------
1. Insert Node
2. Delete Node
3. Find Node
4. Display BST
5. Exit
------------------------------
Enter your choice: 1
Enter numeric key to insert: 5

-----------MENU---------------
1. Insert Node
2. Delete Node
3. Find Node
4. Display BST
5. Exit
------------------------------
Enter your choice: 1
Enter numeric key to insert: 8

-----------MENU---------------
1. Insert Node
2. Delete Node
3. Find Node
4. Display BST
5. Exit
------------------------------
Enter your choice: 4

Binary Search Tree (Horizontal View):

                   13

             5            66

               8


-----------MENU---------------
1. Insert Node
2. Delete Node
3. Find Node
4. Display BST
5. Exit
------------------------------
Enter your choice: 2
Enter key to delete: 8

-----------MENU---------------
1. Insert Node
2. Delete Node
3. Find Node
4. Display BST
5. Exit
------------------------------
Enter your choice: 3
Enter key to find: 66
Key found in BST.

-----------MENU---------------
1. Insert Node
2. Delete Node
3. Find Node
4. Display BST
5. Exit
------------------------------
Enter your choice: 4

Binary Search Tree (Horizontal View):

       13

     5    66


-----------MENU---------------
1. Insert Node
2. Delete Node
3. Find Node
4. Display BST
5. Exit
------------------------------
Enter your choice: 5
Exiting...

---
