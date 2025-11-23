# **Assignment No: 7 (UNIT 3)**
# **Title: Pizza parlour accepting maximum n orders. Orders are served on an FCFS basis. Order once placed can’t be cancelled. Write C++ program to simulate the system using circular QUEUE.**

---

## **Concepts Used**
```
- Circular Queue (using array)
- Queue operations: Enqueue (place order), Dequeue (serve order), Display orders
- Front and Rear pointer management
- Handling queue overflow and underflow
```

---

## **Pseudocode (Stepwise)**

```
STEP 1: Start

STEP 2: Input the maximum number of pizza orders the parlour can accept (size_sp)

STEP 3: Initialize a circular queue:
        front_sp = 0
        rear_sp = -1
        count_sp = 0
        array of integers order_sp[size_sp]

STEP 4: Display Menu:
        1. Place new order
        2. Serve next order
        3. Display pending orders
        4. Exit

STEP 5: Repeat until choice is 4:
    IF choice == 1 (Place new order):
        IF queue is full (count_sp == size_sp):
            Display "cannot place order, parlour is full"
        ELSE:
            rear_sp = (rear_sp + 1) % size_sp
            order_sp[rear_sp] = order ID
            count_sp++
            Display "Order placed successfully"

    IF choice == 2 (Serve next order):
        IF queue is empty (count_sp == 0):
            Display "no orders to serve"
        ELSE:
            Display order ID at order_sp[front_sp]
            front_sp = (front_sp + 1) % size_sp
            count_sp--

    IF choice == 3 (Display pending orders):
        IF queue is empty:
            Display "no pending orders"
        ELSE:
            Loop from front_sp, count_sp times circularly and display all order IDs

    IF choice == 4:
        Exit

STEP 6: End
```

---


## ** Output**
```
Enter maximum no of pizza orders parlour can accept: 3

1. place new order
   Enter order number (ID): 101
   order 101 placed successfully!

1. place new order
   Enter order number (ID): 102
   order 102 placed successfully!

3. display pending orders
pending Orders:
  order ID: 101
  order ID: 102

2. serve next order
serving order number: 101

3. display pending orders
pending Orders:
  order ID: 102
```

---

