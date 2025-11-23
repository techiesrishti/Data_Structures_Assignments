# **Assignment No: 8 (UNIT 3)**
# **Title: Write a program that maintains a queue of passengers waiting to see a ticket agent. The program user should be able to insert a new passenger at the rear of the queue, Display the passenger at the front of the Queue, or remove the passenger at the front of the queue. The program will display the number of passengers left in the queue just before it terminates.**

---

## **Concepts Used**
```
- Circular Queue (array implementation)
- Queue operations: Enqueue (insert passenger), Dequeue (serve/remove passenger), Display
- Front and Rear pointer management
- Handling queue overflow and underflow
```

---

## **Pseudocode **

```
STEP 1: Start

STEP 2: Input maximum number of passengers that can wait (size_sp)

STEP 3: Initialize a circular queue:
        front_sp = 0
        rear_sp = -1
        count_sp = 0
        array of strings queue_sp[size_sp]

STEP 4: Display Menu:
        1. Insert new passenger
        2. Show passenger at front
        3. Remove passenger from front
        4. Display all waiting passengers
        5. Exit

STEP 5: Repeat until choice is 5:
    IF choice == 1 (Insert new passenger):
        IF queue is full (count_sp == size_sp):
            Display "queue is full"
        ELSE:
            rear_sp = (rear_sp + 1) % size_sp
            queue_sp[rear_sp] = passenger name
            count_sp++
            Display "passenger added to queue"

    IF choice == 2 (Show passenger at front):
        IF queue is empty (count_sp == 0):
            Display "queue is empty"
        ELSE:
            Display passenger at queue_sp[front_sp]

    IF choice == 3 (Remove passenger from front):
        IF queue is empty (count_sp == 0):
            Display "queue is empty"
        ELSE:
            Display passenger at queue_sp[front_sp] removed
            front_sp = (front_sp + 1) % size_sp
            count_sp--

    IF choice == 4 (Display all waiting passengers):
        IF queue is empty:
            Display "no passengers waiting"
        ELSE:
            Loop from front_sp, count_sp times circularly and display all passengers

    IF choice == 5:
        Display total passengers left
        Exit

STEP 6: End
```

---

## ** Output**
```
Enter max no of passengers that can wait: 3

1. Insert new passenger
   Enter passenger name: meera
   passenger 'meera' added to the queue.

1. Insert new passenger
   Enter passenger name: manav
   passenger 'manav' added to the queue.

2. Show passenger at front
   passenger at front of queue: meera

3. Remove passenger from front
   passenger 'meera' has been served and removed from the queue.

4. Display all waiting passengers
   current passengers in queue:
     manav
```

---



