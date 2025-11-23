# **Assignment No: 3 (UNIT 3)**
# **Title: Write a program to implement multiple stack i.e more than two stack using array and perform following operations on it. A. Push B. Pop C. Stack Overflow D. Stack Underflow E. Display**

---

## **Concepts Used**
```
- Arrays
- Multiple stacks in a single array
- Stack operations: push, pop, isEmpty, isFull
- Index partitioning for multiple stacks
- Dynamic memory allocation in C++
```

---

## **Pseudocode**
```
STEP 1: Start

STEP 2: Input number of stacks `k` and total array size `n`

STEP 3: Create array `arr` of size n
        Create array `top` of size k
        Create arrays `startIndex` and `endIndex` of size k

STEP 4: Partition array for each stack:
        base = n / k
        rem = n % k
        idx = 0
        FOR i = 0 to k-1:
            sz = base + (i < rem ? 1 : 0)
            startIndex[i] = idx
            endIndex[i] = idx + sz - 1
            top[i] = startIndex[i] - 1
            idx = idx + sz

STEP 5: Define function isFull(stackNum):
        RETURN true if top[stackNum] == endIndex[stackNum]
        ELSE RETURN false

STEP 6: Define function isEmpty(stackNum):
        RETURN true if top[stackNum] < startIndex[stackNum]
        ELSE RETURN false

STEP 7: Define function push(item, stackNum):
        IF stackNum invalid OR stack full:
            Display error
            RETURN
        top[stackNum] = top[stackNum] + 1
        arr[top[stackNum]] = item
        Display pushed item

STEP 8: Define function pop(stackNum):
        IF stackNum invalid OR stack empty:
            Display error
            RETURN
        val = arr[top[stackNum]]
        top[stackNum] = top[stackNum] - 1
        Display popped value

STEP 9: Define function displayAll():
        FOR each stack i:
            IF stack has no allocated space:
                Display message
            ELSE IF stack empty:
                Display empty
            ELSE:
                Print elements from top[i] down to startIndex[i]

STEP 10: In main():
        LOOP until user exits:
            Display menu:
                1. PUSH
                2. POP
                3. DISPLAY
                4. EXIT
            Input choice
            Perform corresponding operation using push/pop/displayAll

STEP 11: End
```
---

## ** Output**
```
Enter number of stacks: 3
Enter total array size: 10

[Debug] Partitions (start..end) for each stack:
 Stack 1: 0 .. 3
 Stack 2: 4 .. 6
 Stack 3: 7 .. 9

---------MENU----------
1. PUSH
2. POP
3. DISPLAY
4. EXIT
Enter your choice: 1
Enter stack number (1-3): 1
Enter value to push: 10
Pushed 10 into stack 1

Enter your choice: 3
Stack 1: 10
Stack 2 is empty.
Stack 3 is empty.
```
