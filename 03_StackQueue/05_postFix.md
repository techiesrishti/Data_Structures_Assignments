# **Assignment No: 5 (UNIT 3)**
# **Title: You are given a postfix expression (also known as Reverse Polish Notation) consisting of single-digit operands and binary operators (+, -, *, /). Your task is to evaluate the expression using stack and return its result.**

---

## **Concepts Used**
```
- Stack data structure (using array)
- Push, Pop, Peek operations
- Postfix expression evaluation
- Character and integer conversion
- Traversing string expressions
```

---

## **Pseudocode**
```
STEP 1: Start

STEP 2: Input a postfix expression `str_sp`

STEP 3: Create a stack `st_sp` of size equal to length of expression

STEP 4: FOR each character `ch_sp` in the expression:
    
    IF ch_sp is a space:
        CONTINUE

    ELSE IF ch_sp is a digit:
        Convert ch_sp to integer and push onto stack

    ELSE (ch_sp is an operator):
        val2_sp = pop from stack
        val1_sp = pop from stack
        Perform operation based on ch_sp:
            '+' -> push (val1_sp + val2_sp)
            '-' -> push (val1_sp - val2_sp)
            '*' -> push (val1_sp * val2_sp)
            '/' -> push (val1_sp / val2_sp)
        If operator is invalid, display error and RETURN -1

STEP 5: After traversing expression, pop the result from stack

STEP 6: Display the result

STEP 7: End
```


---

## **Output**
```
Input:  231*+9-
Output: -4

Input:  82/3-
Output: -1

Input:  57+62-* 
Output: 25
```

---
