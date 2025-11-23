# **Assignment No: 9 (UNIT 3)**
# **Title: Write a program to implement multiple queues i.e. two queues using array and perform following operations on it. A. Add Queue, B. Delete from Queue, C. Display Queue**

---

## Concepts used 
- Queue implementation using arrays
- Separate front and rear pointers for each queue
- Queue operations: Enqueue, Dequeue, Display
- Handling overflow and underflow
---

## PseudoCode

STEP 1: Start

STEP 2: Input size of each queue (size_sp)

STEP 3: Initialize two queues:
        queue1_sp[size_sp], queue2_sp[size_sp]
        front1_sp = rear1_sp = -1
        front2_sp = rear2_sp = -1

STEP 4: Display Menu:
        1. Add to Queue
        2. Delete from Queue
        3. Display Queue
        4. Exit

STEP 5: Repeat until choice is 4:
    IF choice == 1 (Add to Queue):
        Input queue number (qno_sp) and value (val_sp)
        IF queue number == 1:
            IF rear1_sp == size_sp - 1:
                Display "queue 1 overflow"
            ELSE:
                IF front1_sp == -1 then front1_sp = 0
                rear1_sp++
                queue1_sp[rear1_sp] = val_sp
                Display "value inserted into queue 1"
        ELSE IF queue number == 2:
            IF rear2_sp == size_sp - 1:
                Display "queue 2 overflow"
            ELSE:
                IF front2_sp == -1 then front2_sp = 0
                rear2_sp++
                queue2_sp[rear2_sp] = val_sp
                Display "value inserted into queue 2"
        ELSE:
            Display "invalid queue number"

    IF choice == 2 (Delete from Queue):
        Input queue number (qno_sp)
        IF queue number == 1:
            IF front1_sp == -1 or front1_sp > rear1_sp:
                Display "queue 1 underflow"
            ELSE:
                Display "deleted value: queue1_sp[front1_sp]"
                front1_sp++
        ELSE IF queue number == 2:
            IF front2_sp == -1 or front2_sp > rear2_sp:
                Display "queue 2 underflow"
            ELSE:
                Display "deleted value: queue2_sp[front2_sp]"
                front2_sp++
        ELSE:
            Display "invalid queue number"

    IF choice == 3 (Display Queue):
        Display all elements from front1_sp to rear1_sp
        Display all elements from front2_sp to rear2_sp

    IF choice == 4:
        Exit

STEP 6: End

---
## Output

Enter size of each queue: 3

1. Add to Queue
   Queue number: 1
   Value: 10
   Output: inserted 10 into Queue 1

1. Add to Queue
   Queue number: 2
   Value: 20
   Output: inserted 20 into Queue 2

3. Display Queue
   Output:
     queue 1 elements: 10
     queue 2 elements: 20

2. Delete from Queue
   Queue number: 1
   Output: deleted 10 from Queue 1

3. Display Queue
   Output:
     queue 1 is empty.
     queue 2 elements: 20

---