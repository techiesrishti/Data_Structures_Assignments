# **Assignment No: 1 (UNIT 4)**
# **Title: Write a program to perform Binary Search Tree (BST) operations (Create, Insert, Delete,Levelwise display )**

---

## Concepts used
- Binary Search Tree (BST)
- Node structure with `data`, `left`, and `right` pointers
- Recursive insertion and deletion in BST
- Level-order traversal for tree display
- Handling empty tree conditions

---

## PseudoCode

**STEP 1:** Start

**STEP 2:** Initialize empty BST:  
&nbsp;&nbsp;&nbsp;&nbsp;`root_sp = NULL`

**STEP 3:** Display Menu:  
Insert Node

Delete Node

Display Tree (Tree Format)

Exit


**STEP 4:** Repeat until choice == 4:

- **IF choice == 1 (Insert Node):**  
  - Input value (`value_sp`)  
  - Call `insertNode_sp(root_sp, value_sp)`  
    - IF node is NULL: return new node with value  
    - ELSE IF value < node->data: insert in left subtree  
    - ELSE IF value > node->data: insert in right subtree  
  - Update `root_sp` after insertion

- **IF choice == 2 (Delete Node):**  
  - Input value (`value_sp`)  
  - Call `deleteNode_sp(root_sp, value_sp)`  
    - IF node is NULL: return NULL  
    - ELSE IF value < node->data: delete from left subtree  
    - ELSE IF value > node->data: delete from right subtree  
    - ELSE (node found):  
      - IF node has no left child: replace with right child  
      - ELSE IF node has no right child: replace with left child  
      - ELSE (node has two children):  
        - Find minimum node in right subtree  
        - Replace node's value with minimum value  
        - Delete minimum node in right subtree  
  - Update `root_sp` after deletion

- **IF choice == 3 (Display Tree):**  
  - IF `root_sp == NULL`: display `"Tree is empty!"`  
  - ELSE: perform level-order traversal  
    - Calculate height of tree  
    - Use queue to traverse each level  
    - Display nodes with spacing to resemble tree structure

- **IF choice == 4 (Exit):**  
  - Exit program

**STEP 5:** End

---

## Output
--- Binary Search Tree Operations ---
1. Insert Node
2. Delete Node
3. Display Tree (Tree Format)
4. Exit
Enter your choice: 1
Enter value to insert: 50

Enter your choice: 1
Enter value to insert: 30

Enter your choice: 1
Enter value to insert: 70

Enter your choice: 3
       50       

   30           70   


Enter your choice: 2
Enter value to delete: 30

Enter your choice: 3
       50       

                70
---

