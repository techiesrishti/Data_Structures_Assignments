# **Assignment No: 6 (UNIT 3)**
# **Title: Write a program to keep track of patients as they checked into a medical clinic, assigning patients to doctors on a first-come, first-served basis.**

---

## **Concepts Used**
```
- Circular Queue (using array)
- Queue operations: Enqueue, Dequeue, Display
- Front and Rear pointer handling
- Handling queue overflow and underflow
```

---

## **Pseudocode**
```
STEP 1: Start

STEP 2: Input the maximum number of patients the queue can hold (size_sp)

STEP 3: Initialize a circular queue:
        front_sp = 0
        rear_sp = -1
        count_sp = 0
        array of strings arr_sp[size_sp]

STEP 4: Display Menu:
        1. Check-in new patient
        2. Assign next patient to doctor
        3. Display waiting patients
        4. Exit

STEP 5: Repeat until choice is 4:
    IF choice == 1 (Check-in):
        IF queue is full (count_sp == size_sp):
            Display "queue overflow"
        ELSE:
            rear_sp = (rear_sp + 1) % size_sp
            arr_sp[rear_sp] = patient name
            count_sp++

    IF choice == 2 (Assign next patient):
        IF queue is empty (count_sp == 0):
            Display "queue underflow"
        ELSE:
            Display patient at arr_sp[front_sp]
            front_sp = (front_sp + 1) % size_sp
            count_sp--

    IF choice == 3 (Display waiting patients):
        IF queue is empty:
            Display "No patients waiting"
        ELSE:
            Loop from front_sp, count_sp times, circularly, and display patient names

    IF choice == 4:
        Exit

STEP 6: End
```

---

## **Output**
```
Enter maximum no of patients queue can hold: 3

1. check-in new patient
   Enter patient name: harry
   Patient harry has been checked in.

1. check-in new patient
   Enter patient name: meera
   Patient meera has been checked in.

3. display waiting patients
Patients waiting in queue:
  harry
  meera

2. assign next patient to doctor
Doctor is now seeing patient: harry

3. display waiting patients
Patients waiting in queue:
  meera
```
