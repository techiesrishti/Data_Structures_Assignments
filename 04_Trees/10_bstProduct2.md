# Assignment No.: 10 (UNIT 4)  
# Title: Write a program to implement deletion operations in the product inventory system using a search tree. Each product must store the following information: Unique Product Code, Product Name, Price, Quantity in Stock, Date Received, Expiration Date. Implement the following operations:
1.	Delete a product using its unique product code.

2.	Delete all expired products based on the current date.


---

## **Concepts Used**
- Binary Search Tree (BST)  
- Dynamic memory allocation  
- Recursive tree traversal (Inorder)  
- Deletion in BST  
- Handling expired products using date comparison  
- Object-oriented programming in C++ (Classes & Objects)  

---

## **Pseudocode **

### **Insert Product**
1. If the tree is empty, create a new node as root.  
2. Compare product name with current node:  
   - If smaller → move to left subtree  
   - If larger → move to right subtree  
   - If equal → reject duplicate  
3. Repeat recursively until insertion point found.  

### **Delete Product by Code**
1. Search for the node with the given product code.  
2. If not found → exit.  
3. If found:  
   - Node has no child → delete node.  
   - Node has one child → replace node with child.  
   - Node has two children → replace with inorder successor, then delete successor.  

### **Delete All Expired Products**
1. Traverse the tree recursively (postorder).  
2. For each node, check expiry using current date.  
3. If expired, delete node using **Delete Product by Code** function.  

### **Display Inventory (Inorder)**
1. Traverse the tree in inorder: left → root → right  
2. Print product details.  

---

## Output

---------- MENU ----------
1. Insert Product
2. Delete Product by Code
3. Delete All Expired Products
4. Show Inventory (Inorder)
5. Exit
Enter choice: 1
Enter Code: P001
Enter Name: Milk
Enter Price: 50
Enter Quantity: 10
Enter Date Received (YYYY-MM-DD): 2025-11-20
Enter Expiry Date (YYYY-MM-DD): 2025-11-22

Enter choice: 1
Enter Code: P002
Enter Name: Bread
Enter Price: 30
Enter Quantity: 20
Enter Date Received (YYYY-MM-DD): 2025-11-19
Enter Expiry Date (YYYY-MM-DD): 2025-11-23

Enter choice: 4

Code: P002
Name: Bread
Price: 30
Quantity: 20
Received: 2025-11-19
Expiry: 2025-11-23
------------------------------
Code: P001
Name: Milk
Price: 50
Quantity: 10
Received: 2025-11-20
Expiry: 2025-11-22
------------------------------

Enter choice: 3
Deleting expired: Milk
All expired products removed.

Enter choice: 4

Code: P002
Name: Bread
Price: 30
Quantity: 20
Received: 2025-11-19
Expiry: 2025-11-23
------------------------------

---
