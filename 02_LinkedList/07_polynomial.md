# Assignment No: 7 (UNIT 2)

## Title
WAP to perform addition o f two polynomials using singly linked list.

## Concepts Used
- Singly Linked List  
- Node representation (coefficient, power)  
- Polynomial addition using linked list traversal  
- Ordered polynomial merging  
- Dynamic memory allocation  
- Display in mathematical and linked-list form  

## Pseudocode

### insert(coefficient, power)
1. Create a new node with given coefficient and power  
2. If list is empty: head = new node  
3. Else  
   - Traverse to the last node  
   - Append new node at the end  

### display()
1. Traverse each node  
2. Print `coefficient x^ power`  
3. If next node exists, print `" + "`  

### add(p1, p2)
1. Create empty result polynomial  
2. Set pointers t1 → p1.head, t2 → p2.head  
3. While both lists exist:  
   - If powers match:  
     - sum = coefficients of both  
     - If sum ≠ 0 insert (sum, power)  
     - Move both t1 and t2  
   - Else if t1.power > t2.power:  
     - Insert t1 term into result  
     - Move t1  
   - Else  
     - Insert t2 term into result  
     - Move t2  
4. Add remaining terms from p1  
5. Add remaining terms from p2  
6. Return result polynomial  

## Output

enter no of terms in 1st polynomial: 3
enter terms coef and power:
5 3
4 2
2 0

enter no of terms in 2ns polynomial: 3
enter terms coef and power:
3 3
-4 2
7 1

polynomial 1: 5x^3 + 4x^2 + 2x^0
[5x^3] -> [4x^2] -> [2x^0] -> NULL

polynomail 2: 3x^3 + -4x^2 + 7x^1
[3x^3] -> [-4x^2] -> [7x^1] -> NULL

sum: 8x^3 + 7x^1 + 2x^0
[8x^3] -> [7x^1] -> [2x^0] -> NULL