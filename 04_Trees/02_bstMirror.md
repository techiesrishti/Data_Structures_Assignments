# **Assignment No: 2 (UNIT 4)**
# **Title: Write a program to perform Binary Search Tree (BST) operations (Count the total number of nodes, Compute the height of the BST, Mirror Image ).**

---

## Concepts used
- Binary Search Tree (BST)
- Node structure with `data`, `left`, and `right` pointers
- Recursive insertion
- Counting total nodes in BST
- Calculating height of BST
- Generating mirror image of BST
- Level-order traversal for tree display
- Handling empty tree conditions

---

## PseudoCode

**STEP 1:** Start

**STEP 2:** Initialize empty BST:  
&nbsp;&nbsp;&nbsp;&nbsp;`root_sp = NULL`

**STEP 3:** Display Menu:  

**STEP 4:** Repeat until choice == 6:

- **IF choice == 1 (Insert Node):**  
  - Input value (`val_sp`)  
  - Call recursive function to insert node:  
    - IF node is NULL → create new node  
    - ELSE IF value < node->data → insert in left subtree  
    - ELSE IF value > node->data → insert in right subtree  

- **IF choice == 2 (Display Tree):**  
  - IF root is NULL → display `"Tree is empty!"`  
  - ELSE → perform level-order traversal  
    - Use queue to traverse each level  
    - Display nodes with spacing to resemble tree structure  

- **IF choice == 3 (Count Total Nodes):**  
  - Use recursive function to count nodes in left and right subtree  
  - Display total nodes

- **IF choice == 4 (Compute Height):**  
  - Use recursive function to compute height:  
    `height = 1 + max(height(left), height(right))`  
  - Display height of BST

- **IF choice == 5 (Mirror Image):**  
  - Swap left and right subtrees recursively for all nodes  
  - Display `"Mirror image created successfully"`  
  - Optionally display mirrored tree

- **IF choice == 6 (Exit):**  
  - Exit program

**STEP 5:** End

---

## Output

--- Binary Search Tree Operations ---
1. Insert Node
2. Display Tree
3. Count Total Nodes
4. Compute Height of BST
5. Mirror Image of BST
6. Exit
Enter your choice: 1
Enter value to insert: 50

Enter your choice: 1
Enter value to insert: 30

Enter your choice: 1
Enter value to insert: 70

Enter your choice: 2
Tree structure:
       50       
   30           70   

Enter your choice: 3
Total no of nodes: 3

Enter your choice: 4
Height of BST: 2

Enter your choice: 5
Mirror image created successfully

Tree after mirror image:
       50       
   70           30   

---

