# Assignment No 4
## TITLE : Develop a program to identify and efficiently store a sparse matrix using compact representation and perform basic operations like display and simple transpose.

**Sparse Matrix Operations**
1. Accept a matrix  
2. Convert matrix into sparse triplet form  
3. Display original matrix  
4. Display sparse triplet  
5. Compute and display simple transpose  

---

## Pseudocode

### 1. Input Matrix
Step 1: Read m_sp (rows) and n_sp (columns)  
Step 2: Create 2D vector A_sp of size m_sp × n_sp  
Step 3: For each i_sp in rows  
  For each j_sp in columns  
   Input A_sp[i_sp][j_sp]

---

### 2. Convert to Sparse Triplet Form
Step 1: Initialize empty list sparse_sp  
Step 2: For each i_sp in rows  
  For each j_sp in columns  
   If A_sp[i_sp][j_sp] ≠ 0  
    Add triplet {i_sp, j_sp, A_sp[i_sp][j_sp]} to sparse_sp

---

### 3. Print Original Matrix
Step 1: For each row i_sp  
  For each column j_sp  
   Print A_sp[i_sp][j_sp]

---

### 4. Print Sparse Triplet
Step 1: For each triplet t_sp in sparse_sp  
  Print t_sp.row_sp, t_sp.col_sp, t_sp.val_sp

---

### 5. Simple Transpose of Sparse Matrix
Step 1: For each triplet t_sp in sparse_sp  
  Print t_sp.col_sp, t_sp.row_sp, t_sp.val_sp

---

## Algorithm

### Step 1: Start  
### Step 2: Read matrix dimensions m_sp and n_sp  
### Step 3: Read matrix elements into A_sp  
### Step 4: Create sparse triplet list sparse_sp by storing non-zero elements  
### Step 5: Print original matrix  
### Step 6: Print sparse triplet representation  
### Step 7: Print transpose by swapping row_sp ↔ col_sp for each entry  
### Step 8: Stop  

---

## Output Format (Example)

**Original Matrix:**  
1 0 3  
0 5 0  
6 0 0  

**Sparse Matrix (Triplet Form):**  
0 0 1  
0 2 3  
1 1 5  
2 0 6  

**Transpose of Sparse Matrix:**  
0 0 1  
2 0 3  
1 1 5  
0 2 6  

---
