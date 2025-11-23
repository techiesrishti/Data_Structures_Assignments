# **Assignment No: 4 (UNIT 3)**
# **Title: You are given a string containing only parentheses characters: '(', ')', '{', '}', '[', and ']'. Your task is to check whether the parentheses are balanced or not. A string is considered balanced if: 1.	Every opening bracket has a corresponding closing bracket of the same type 2.	Brackets are closed in the correct order**

---

## **Concepts Used**
```
- Stack data structure (using linked list)
- Push, Pop, Peek operations
- Matching parentheses
- String traversal
- Conditional statements
```

---

## **Pseudocode**
```
STEP 1: Start

STEP 2: Input string `bracket` containing parentheses

STEP 3: Create an empty stack `s`

STEP 4: FOR each character `ch` in `bracket`:

    IF ch is an opening bracket '(' or '{' or '[':
        push ch onto stack s

    ELSE IF ch is a closing bracket ')' or '}' or ']':
        IF stack s is empty:
            RETURN false (unbalanced)
        ELSE:
            top = pop from stack s
            IF top and ch do not match as a pair:
                RETURN false (unbalanced)

STEP 5: After traversal, IF stack s is empty:
            RETURN true (balanced)
        ELSE:
            RETURN false (unbalanced)

STEP 6: Display result to user

STEP 7: End
```


---

## ** Output**
```
Input:  {[()()]}
Output: Parentheses are balanced

Input:  {[(])}
Output: Parentheses are not balanced!

Input:  ((()))
Output: Parentheses are balanced

Input:  (() 
Output: Parentheses are not balanced!
```

---

