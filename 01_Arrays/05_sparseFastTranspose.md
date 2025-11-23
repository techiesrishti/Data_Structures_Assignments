# Assignment No 5 
## TITLE : Develop a program to compute the fast transpose of a sparse matrix using its compact (triplet) representation efficiently.

**Sparse Matrix Operations**
1. Accept a matrix  
2. Convert matrix into sparse triplet form  
3. Display original matrix  
4. Display sparse triplet  
5. Perform **Fast Transpose**  

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
    Push triplet {i_sp, j_sp, A_sp[i_sp][j_sp]}

---

### 3. Print Original Matrix  
Step 1: For each row i_sp  
  For each column j_sp  
   Print A_sp[i_sp][j_sp]

---

### 4. Print Sparse Triplet  
Step 1: For each triplet t_sp  
  Print t_sp.row_sp, t_sp.col_sp, t_sp.val_sp

---

## Fast Transpose Algorithm (Using Count + Index Arrays)

### Idea  
Fast transpose improves efficiency by:  
* Counting number of elements in each column  
* Computing starting indices  
* Placing each element directly in its correct position  

---

## Pseudocode: Fast Transpose

Step 1: Create arrays colCount[n_sp] and index[n_sp] initialized to 0  

Step 2: For each triplet t_sp in sparse_sp  
  colCount[t_sp.col_sp]++  

Step 3: index[0] = 0  
Step 4: For i from 1 to n_sp−1  
  index[i] = index[i−1] + colCount[i−1]  

Step 5: Create trans_sp array of same size as sparse_sp  

Step 6: For each triplet t_sp in sparse_sp  
  pos = index[t_sp.col_sp]  
  Place {t_sp.col_sp, t_sp.row_sp, t_sp.val_sp} at trans_sp[pos]  
  index[t_sp.col_sp]++  

Step 7: Print trans_sp  

---

## Algorithm

### Step 1: Start  
### Step 2: Read matrix dimensions  
### Step 3: Read matrix elements  
### Step 4: Convert to sparse triplet form  
### Step 5: Print original matrix  
### Step 6: Print triplet form  
### Step 7: Perform fast transpose using:  
- Column count  
- Starting index  
- Direct placement  
### Step 8: Print fast transposed sparse matrix  
### Step 9: Stop  

---

## Output Format (Example)

**Original Matrix:**  
1 0 3  
0 5 0  
6 0 0  

**Sparse Matrix Triplet Form:**  
0 0 1  
0 2 3  
1 1 5  
2 0 6  

**Fast Transpose Output:**  
0 0 1  
2 0 3  
1 1 5  
0 2 6  

---

