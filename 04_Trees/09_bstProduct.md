# **Assignment No: 9**
### **Title:** Write a program to implement a product inventory management system for a shop using a search tree data structure. Each product must store the following information: Unique Product Code, Product Name, Price, Quantity in Stock, Date Received, Expiration Date. Implement the following operations:
1.	Insert a product into the tree ( organized by product name).
2.	Display all items in the inventory using inorder traversal.
3.	List expired items in prefix (preorder) order of their names.


---

## Concepts Used
- Binary Search Tree (BST) to store product records.
- Product structure:
  - `productCode_sp` → Unique product code
  - `productName_sp` → Product name (BST key)
  - `price_sp` → Price of product
  - `quantity_sp` → Quantity in stock
  - `dateReceived_sp` → Date product was received
  - `expiryDate_sp` → Expiry date
- BST Operations:
  - Insert Product
  - Display Inventory (Inorder → Sorted by Name)
  - Show Expired Products (Preorder)
  - Display BST horizontally
- Checking expiration using system date comparison.

---

## Pseudocode

**STEP 1:** Start

**STEP 2:** Initialize BST:  
root_sp = NULL


**STEP 3:** Display Menu:
1. Insert Product
2. Display Inventory (Inorder)
3. Show Expired Products (Preorder)
4. Display Product Tree
5. Exit

**STEP 4:** Repeat until choice == 5:
- **Insert Product**:
  - Input product details
  - Insert into BST using `productName_sp` as key:
    - If name < node->productName → go left
    - Else → go right
- **Display Inventory (Inorder)**:
  - Recursively traverse BST inorder
  - Print product details in sorted order by name
- **Show Expired Products (Preorder)**:
  - Traverse BST preorder
  - Compare expiry date with current date
  - Print only expired products
- **Display Product Tree**:
  - Compute tree height
  - Print tree level by level with spacing for horizontal visualization

**STEP 5:** End

---

## Output
------------ MENU ----------------
1. Insert Product
2. Display Inventory (Inorder)
3. Show Expired Products (Preorder)
4. Display Product Tree
5. Exit
----------------------------------
Enter choice: 1
Code: P001
Name: Milk
Price: 50
Qty: 10
Received (YYYY-MM-DD): 2025-11-20
Expiry (YYYY-MM-DD): 2025-11-25

------------ MENU ----------------
Enter choice: 1
Code: P002
Name: Bread
Price: 30
Qty: 20
Received (YYYY-MM-DD): 2025-11-22
Expiry (YYYY-MM-DD): 2025-11-23

------------ MENU ----------------
Enter choice: 1
Code: P003
Name: Eggs
Price: 10
Qty: 30
Received (YYYY-MM-DD): 2025-11-21
Expiry (YYYY-MM-DD): 2025-11-28

------------ MENU ----------------
Enter choice: 2

----- Inventory (Sorted by Name) -----

Product Code: P002
Product Name: Bread
Price: 30
Quantity: 20
Received: 2025-11-22
Expiry: 2025-11-23
-----------------------------
Product Code: P001
Product Name: Milk
Price: 50
Quantity: 10
Received: 2025-11-20
Expiry: 2025-11-25
-----------------------------
Product Code: P003
Product Name: Eggs
Price: 10
Quantity: 30
Received: 2025-11-21
Expiry: 2025-11-28
-----------------------------

------------ MENU ----------------
Enter choice: 3

----- Expired Products (Preorder) -----
Expired: Bread | Code: P002 | Expiry: 2025-11-23

------------ MENU ----------------
Enter choice: 4

----- Product Tree (Horizontal View) -----

         Milk

  Bread             Eggs

------------ MENU ----------------
Enter choice: 5
Exiting...

---
