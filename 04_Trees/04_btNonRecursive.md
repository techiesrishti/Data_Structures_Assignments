# **Assignment No: 4 (UNIT 4)**
# **Title: Write a Program to create a Binary Tree and perform following Nonrecursive operations on it. a. Inorder Traversal b. Preorder Traversal c. Display Number of Leaf Nodes d. Mirror Image**

---

## Concepts used
- Binary Tree implementation using nodes with `data`, `left`, and `right`
- Non-recursive Inorder traversal using stack
- Non-recursive Preorder traversal using stack
- Counting leaf nodes (nodes with no children)
- Mirror image of the binary tree
- Tree display in pyramid format
- Level-order traversal using queue

---

## PseudoCode

**STEP 1:** Start  

**STEP 2:** Initialize empty Binary Tree:  
&nbsp;&nbsp;&nbsp;&nbsp;`root_sp = NULL`  

**STEP 3:** Display Menu:  
1. Insert Node
2. Inorder Traversal (Non-Recursive)
3. Preorder Traversal (Non-Recursive)
4. Count Leaf Nodes
5. Mirror Image
6. Display Tree (Pyramid format)
7. Exit


**STEP 4:** Repeat until choice == 7:

- **IF choice == 1 (Insert Node):**  
  - Input value (`val_sp`)  
  - Insert recursively:
    - IF node is NULL → create new node  
    - ELSE IF value < node->data → insert in left subtree  
    - ELSE → insert in right subtree  

- **IF choice == 2 (Inorder Non-Recursive):**  
  - Use a stack  
  - Traverse leftmost nodes, push to stack  
  - Pop nodes, print data, move to right child  

- **IF choice == 3 (Preorder Non-Recursive):**  
  - Use a stack  
  - Push root, while stack not empty:  
    - Pop node, print data  
    - Push right, then left child  

- **IF choice == 4 (Count Leaf Nodes):**  
  - Leaf node if left and right are NULL  
  - Recursively count leaves in left and right subtrees  

- **IF choice == 5 (Mirror Image):**  
  - Recursively swap left and right child nodes  
  - Display tree after mirroring  

- **IF choice == 6 (Display Tree Pyramid format):**  
  - Compute height  
  - Level-order traversal using queue  
  - Print nodes with spacing to resemble a pyramid  

- **IF choice == 7 (Exit):**  
  - Exit program  

**STEP 5:** End  

---

## Output

---------- MENU ----------
1. Insert Node
2. Inorder Traversal (Non-Recursive)
3. Preorder Traversal (Non-Recursive)
4. Count Leaf Nodes
5. Mirror Image
6. Display Tree (Pyramid format)
7. Exit
---------------------------
Enter your choice: 1
Enter value: 50

Enter your choice: 1
Enter value: 30

Enter your choice: 1
Enter value: 70

Enter your choice: 2
Inorder Traversal: 30 50 70

Enter your choice: 3
Preorder Traversal: 50 30 70

Enter your choice: 4
No of leaf nodes: 2

Enter your choice: 6

Tree Display:

       50       

   30           70   

---