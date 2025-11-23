# **Assignment No: 2 (UNIT 3)**
# **Title: Convert given infix expression Eg. a-b*c-d/e+f into postfix form using stack and show the operations step by step.**

---

## **Concepts Used**
```
- Stack (LIFO)
- Linked List
- Operator precedence & associativity
- Expression evaluation rules
- Character handling
```

---

## **Pseudocode**
```
STEP 1: Start

STEP 2: Define structure NODE containing:
        - data (character)
        - next (pointer to NODE)

STEP 3: Define class STACK with:
        - top pointer initialized to NULL

STEP 4: Define function isEmpty():
        IF top == NULL
            RETURN true
        ELSE
            RETURN false

STEP 5: Define push(c):
        Create new node
        Set newNode.next = top
        Update top = newNode

STEP 6: Define pop():
        IF stack is empty
            RETURN null character
        Store top->data in a variable
        Move top to top->next
        Delete old top
        RETURN stored character

STEP 7: Define peek():
        IF stack empty RETURN null character
        ELSE return top->data

STEP 8: Define priority(c):
        Return precedence:
            '^' → 3
            '*' or '/' → 2
            '+' or '-' → 1
            otherwise → -1

STEP 9: Define infixToPostfix(infix):
        Create empty stack `s`
        Create empty string postfix

        FOR each character c in infix:
            IF c is space:
                CONTINUE

            IF c is alphanumeric:
                Append c to postfix

            ELSE IF c is '(':
                Push to stack

            ELSE IF c is ')':
                WHILE top is not '(':
                    pop and append to postfix
                pop '(' from stack

            ELSE (operator):
                WHILE stack not empty AND priority(c) <= priority(peek()):
                    pop and append to postfix
                push(c)

        WHILE stack not empty:
            pop and append to postfix
        
        RETURN postfix

STEP 10: In main():
        Read infix expression
        Call infixToPostfix()
        Display result

STEP 11: End
```


## ** Output**
```
enter infix exp: a-b*c-d/e+f

symbol    stack               postfix
-----------------------------------------------------------
a                             a
-         -                   a
b         -                   ab
*         -*                  ab
c         -*                  abc
-         -                   abc*-
d         -                   abc*-d
/         -/                  abc*-d
e         -/                  abc*-de
+         +                   abc*-de/-
f         +                   abc*-de/-f
                              abc*-de/-f+

Final Postfix Ans: abc*-de/-f+
```
