# **Assignment No: 5 (UNIT 4)**
# **Title: Write a Program to create a Binary Tree and perform the following Recursive operations on it. a. Inorder Traversal b. Preorder Traversal c. Display Number of Leaf Nodes d. Mirror Image**

---

## Concepts used
- Binary Tree with nodes containing `data`, `left`, and `right`
- User-directed insertion (left or right of a chosen node)
- Recursive Inorder traversal
- Recursive Preorder traversal
- Counting leaf nodes
- Mirror image of the tree
- Tree display in pyramid format using level-order traversal

---

## PseudoCode

**STEP 1:** Start  

**STEP 2:** Initialize empty Binary Tree:  
&nbsp;&nbsp;&nbsp;&nbsp;`root_sp = NULL`  

**STEP 3:** Display Menu:  
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit


**STEP 4:** Repeat until choice == 7:

- **IF choice == 1 (Insert Node):**  
  - Input value (`value_sp`)  
  - IF tree is empty → create root node  
  - ELSE → recursively insert based on user input:
    - Ask: Insert left (L) or right (R) of current node  
    - Traverse left or right accordingly until position is found  

- **IF choice == 2 (Inorder Traversal):**  
  - Traverse left subtree recursively  
  - Print node data  
  - Traverse right subtree recursively  

- **IF choice == 3 (Preorder Traversal):**  
  - Print node data  
  - Traverse left subtree recursively  
  - Traverse right subtree recursively  

- **IF choice == 4 (Count Leaf Nodes):**  
  - IF node has no left or right child → count as 1  
  - ELSE → recursively count leaf nodes in left and right subtrees  

- **IF choice == 5 (Mirror Image):**  
  - Recursively swap left and right child nodes  
  - Display tree after mirroring  

- **IF choice == 6 (Display Tree):**  
  - Level-order traversal using queue  
  - Print nodes with spacing to resemble a pyramid  

- **IF choice == 7 (Exit):**  
  - Exit program  

**STEP 5:** End  

---
## Output
----------- MENU -----------
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit
----------------------------
Enter your choice: 1
Enter value: 12

----------- MENU -----------
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit
----------------------------
Enter your choice: 1
Enter value: 55
Insert 55 to Left (L) or Right (R) of 12? L

----------- MENU -----------
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit
----------------------------
Enter your choice: 1
Enter value: 66
Insert 66 to Left (L) or Right (R) of 12? R

----------- MENU -----------
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit
----------------------------
Enter your choice: 1
Enter value: 5 
Insert 5 to Left (L) or Right (R) of 12? L
Insert 5 to Left (L) or Right (R) of 55? L

----------- MENU -----------
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit
----------------------------
Enter your choice: 6

Tree Display:
            12
      55          66
    5

----------- MENU -----------
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit
----------------------------
Enter your choice: 2
Inorder Traversal: 5 55 12 66 

----------- MENU -----------
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit
----------------------------
Enter your choice: 3
Preorder Traversal: 12 55 5 66 

----------- MENU -----------
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit
----------------------------
Enter your choice: 4
Number of Leaf Nodes: 2

----------- MENU -----------
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit
----------------------------
Enter your choice: 5
Mirror Image Created.
            12
      66          55
                      5

----------- MENU -----------
1. Insert Node
2. Inorder Traversal (Recursive)
3. Preorder Traversal (Recursive)
4. Count Leaf Nodes
5. Mirror Image of Tree
6. Display Tree
7. Exit
----------------------------
Enter your choice: 7
Exiting...      

---
