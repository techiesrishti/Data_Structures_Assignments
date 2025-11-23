# Assignment No: 2
## TITLE: Write a program to construct and verify a magic square of order 'n' (for both even & odd) such that all rows, columns, and diagonals sum to the same value.

## Aim
To implement a program that generates a Magic Square of order n × n using different algorithms based on whether n is odd, doubly even, or singly even, and then verify its correctness.

---

## Concepts Used
1. Odd Order Magic Square 
2. Doubly Even Magic Square (n % 4 == 0)
3. Singly Even Magic Square (n = 4k + 2)
4. Magic Constant Verification
5. 2D Vector Matrix Representation

---

## Pseudocode

### 1. Display Magic Square
Step 1: Loop i_sp from 0 to n_sp  
Step 2: Loop j_sp from 0 to n_sp  
Step 3: Print m_sp[i_sp][j_sp] with proper spacing  
Step 4: Print newline  

---

### 2. Generate Odd Magic Square (Siamese Method)
Step 1: Initialize all cells of matrix to 0  
Step 2: Set i_sp = 0, j_sp = n_sp / 2  
Step 3: For num_sp = 1 to n_sp*n_sp  
            Place num_sp at m_sp[i_sp][j_sp]  
            newI = (i_sp - 1 + n_sp) % n_sp  
            newJ = (j_sp + 1) % n_sp  
            If m_sp[newI][newJ] is filled  
                i_sp = (i_sp + 1) % n_sp  
            Else  
                i_sp = newI  
                j_sp = newJ  

---

### 3. Generate Doubly Even Magic Square (n % 4 == 0)
Step 1: Fill matrix with numbers from 1 to n_sp*n_sp  
Step 2: For all i_sp, j_sp  
            If (i_sp % 4 < 2 AND j_sp % 4 < 2)  
               OR (i_sp % 4 >= 2 AND j_sp % 4 >= 2)  
               Replace m_sp[i_sp][j_sp] = total + 1 - m_sp[i_sp][j_sp]  

---

### 4. Generate Singly Even Magic Square (n = 4k + 2)
Step 1: half_sp = n_sp / 2  
Step 2: subSize_sp = half_sp * half_sp  
Step 3: Generate A_sp = Odd magic square of size half_sp  
Step 4: Form 4 sub-squares:  
        Top-left      → A  
        Bottom-left   → A + 2*subSize  
        Top-right     → A + 3*subSize  
        Bottom-right  → A + subSize  
Step 5: Swap columns based on algorithm rule k_sp = (n_sp - 2) / 4  

---

### 5. Verify Magic Square
Step 1: Compute magic_sp = n_sp * (n_sp*n_sp + 1) / 2  
Step 2: Check sum of each row  
Step 3: Check sum of each column  
Step 4: Check both diagonals  
Step 5: If all sums equal magic_sp → Valid Magic Square  

---

## Sample Output
Enter order n of Magic Square: 5  

Magic Square of order 5:

   17   24    1    8   15  
   23    5    7   14   16  
    4    6   13   20   22  
   10   12   19   21    3  
   11   18   25    2    9  

Magic Constant = 65  
Result: Magic Square is valid  



