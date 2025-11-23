# Assignment No: 3 
## TITLE: Implement matrix multiplication and analyse its performance using row-major vs column-major order access patterns to understand how memory layout affects cache performance.

---

## Aim  
To dynamically allocate matrices, perform matrix multiplication using **Row-Major** and **Column-Major** traversal techniques, measure computation time, and compare their efficiency.

---

## Concepts Used  
1. Dynamic Memory Allocation using `new`  
2. Matrix Representation using Double Pointers  
3. Random Matrix Generation  
4. Row-Major Traversal  
5. Column-Major Traversal  
6. Time Measurement using `clock()`  
7. Freeing Dynamic Memory  

---

## Pseudocode  

### 1. Allocate Matrix Dynamically  
Step 1: Create array of row pointers  
Step 2: For each row, allocate column array  
Step 3: Return pointer to matrix  

---

### 2. Free Matrix Memory  
Step 1: Loop through rows  
Step 2: Delete each row  
Step 3: Delete matrix pointer  

---

### 3. Print Matrix  
Step 1: Loop through each row  
Step 2: Loop through each column  
Step 3: Print values with spacing  

---

### 4. Row-Major Multiplication  
Step 1: For each row i of A  
Step 2: For each column index k  
            temp = A[i][k]  
Step 3: For each column j of B  
            C[i][j] += temp * B[k][j]  

---

### 5. Column-Major Multiplication  
Step 1: For each column j of B  
Step 2: For each index k  
            temp = B[k][j]  
Step 3: For each row i of A  
            C[i][j] += A[i][k] * temp  

---

### 6. Main Program  
Step 1: Input matrix dimensions  
Step 2: Allocate A, B, C matrices  
Step 3: Fill A and B with random values  
Step 4: Display matrices  
Step 5: Ask user for choice (Row-major / Column-major)  
Step 6: Perform multiplication  
Step 7: Measure execution time  
Step 8: Display result matrix  
Step 9: Free all dynamic memory  

---

## Sample Output  
Enter number of rows and columns of Matrix A: 3 3  
Enter number of columns of Matrix B: 3  

Matrix A (3 x 3):  
1 4 2  
0 3 5  
7 2 6  

Matrix B (3 x 3):  
3 5 7  
1 8 4  
2 9 6  

Choose order for multiplication:  
1. Row-major order  
2. Column-major order  
1  

Resultant Matrix (3 x 3):  
11 55 33  
13 69 47  
27 101 83  

Time taken: 0.000021 seconds  



