# Assignment No: 6 (UNIT 2)

## Title
Write a C++ program to implement a Set using a Generalized Linked List (GLL).     For example:
 Let S = { p, q, {r, s, t, {}, {u, v}, w, x, {y, z}, a1, b1} }
Store this structure using a Generalized Linked List and display the elements in correct set notation format.

## Concepts Used
- Generalized Linked List (GLL)
- Recursive Data Structures
- Linked List Node Representation
- Dynamic Memory Allocation
- Recursion for Display and Creation
- Use of flag-based nodes (atom / sublist)

## Pseudocode

### createNode(value)
1. Allocate memory for new node
2. Set flag = 0
3. Set data = value
4. Set down = NULL
5. Set next = NULL
6. Return node

### createSubList(subHead)
1. Allocate memory for new node
2. Set flag = 1
3. Set down = subHead
4. Set next = NULL
5. Return node

### createGLL()
1. Initialize head = NULL, tail = NULL
2. Read n = number of elements in the set
3. For each element:
   - Ask atom/sublist
   - If atom:
     - Read value
     - Create atom node using createNode
   - Else:
     - Recursively call createGLL
     - Wrap it using createSubList
   - If head == NULL:
     - head = newNode
   - Else:
     - tail.next = newNode
   - Update tail = newNode
4. Return head

### display(head)
1. Print "{"
2. Traverse list:
   - If flag == 0 → print atom
   - Else → recursively call display on down-pointer
   - If more elements exist → print ","
3. Print "}"

## Output
create gll in set form:
enter no of elements in the set: 3

element 1: atom/sublist [0/1]: 0
enter atom val: A

element 2: atom/sublist [0/1]: 1
creating a sublist...
enter no of elements in the set: 2

element 1: atom/sublist [0/1]: 0
enter atom val: B

element 2: atom/sublist [0/1]: 0
enter atom val: C

element 3: atom/sublist [0/1]: 0
enter atom val: D

set representation:
{ A, { B, C }, D }

