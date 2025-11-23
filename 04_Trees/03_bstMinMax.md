# **Assignment No: 3 (UNIT 4)**
# **Title: Write a Program to create a Binary Tree Search and Find Minimum/Maximum in BST **

---

## Concepts used
- Binary Search Tree (BST)
- Node structure with `data`, `left`, and `right` pointers
- Recursive insertion
- Finding minimum and maximum node values
- Level-order traversal for tree display
- Handling empty tree conditions

---

## PseudoCode

**STEP 1:** Start

**STEP 2:** Initialize empty BST:  
&nbsp;&nbsp;&nbsp;&nbsp;`root_sp = NULL`

**STEP 3:** Display Menu:  
Insert Node

Find min

Find max

Display tree

Exit


**STEP 4:** Repeat until choice == 5:

- **IF choice == 1 (Insert Node):**  
  - Input value (`value_sp`)  
  - Call recursive function to insert node:  
    - IF node is NULL → create new node  
    - ELSE IF value < node->data → insert in left subtree  
    - ELSE IF value > node->data → insert in right subtree  

- **IF choice == 2 (Find min):**  
  - IF root is NULL → display `"Tree is empty"`  
  - ELSE → traverse left-most nodes until NULL  
  - Display minimum value

- **IF choice == 3 (Find max):**  
  - IF root is NULL → display `"Tree is empty"`  
  - ELSE → traverse right-most nodes until NULL  
  - Display maximum value

- **IF choice == 4 (Display tree):**  
  - IF root is NULL → display `"Tree is empty"`  
  - ELSE → perform level-order traversal with spacing to resemble tree structure  

- **IF choice == 5 (Exit):**  
  - Exit program

**STEP 5:** End

---

## Output
-----------MENU---------------
1.Insert Node
2.Find min
3.Find max
4.Display tree
5.Exit

------------------------------
Enter your choice: 1
Enter the value: 50

Enter your choice: 1
Enter the value: 30

Enter your choice: 1
Enter the value: 70

Enter your choice: 2
Min value: 30

Enter your choice: 3
Max value: 70

Enter your choice: 4

Binary Search Tree: 
       50       
   30           70   

---
