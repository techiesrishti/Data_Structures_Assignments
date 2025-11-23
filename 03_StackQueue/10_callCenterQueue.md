# **Assignment No: 10 (UNIT 3)**
# **Title: In a call center, customer calls are handled on a first-come, first-served basis. Implement a queue system using Linked list where:	Each customer call is enqueued as it arrives. Customer service agents dequeue calls to assist customers. If there are no calls, the system waits.**

---

## Concepts used 
- Queue implementation using singly linked list
- Each node stores customer name
- Operations: Enqueue (new call), Dequeue (assign call to agent), Display waiting calls
- Handles empty queue conditions

---

## PseudoCode

STEP 1: Start

STEP 2: Initialize empty queue:
        front_sp = NULL
        rear_sp = NULL

STEP 3: Display Menu:
        1. New Call Arrived -> Enqueue
        2. Assign Call to Agent -> Dequeue
        3. Show Waiting Calls
        4. Exit

STEP 4: Repeat until choice == 4:

    IF choice == 1 (Enqueue):
        Input customer name (name_sp)
        Create new node newNode_sp with customerName_sp = name_sp
        newNode_sp->next_sp = NULL
        IF rear_sp == NULL:
            front_sp = rear_sp = newNode_sp
        ELSE:
            rear_sp->next_sp = newNode_sp
            rear_sp = newNode_sp
        Display "call from <name_sp> added to the queue"

    IF choice == 2 (Dequeue):
        IF front_sp == NULL:
            Display "No calls in queue. System is waiting..."
        ELSE:
            temp_sp = front_sp
            Display "call from <front_sp->customerName_sp> is being attended by an agent"
            front_sp = front_sp->next_sp
            IF front_sp == NULL:
                rear_sp = NULL
            Delete temp_sp

    IF choice == 3 (Display):
        IF front_sp == NULL:
            Display "No calls in queue"
        ELSE:
            temp_sp = front_sp
            Display "Calls waiting in queue:"
            WHILE temp_sp != NULL:
                Display temp_sp->customerName_sp
                temp_sp = temp_sp->next_sp

    IF choice == 4 (Exit):
        Exit program

STEP 5: End


---
## Output
------ CALL CENTER MENU ------
1. New Call Arrived -> Enqueue
2. Assign Call to Agent -> Dequeue
3. Show Waiting Calls
4. Exit
-------------------------------
Enter your choice: 1
Enter customer name: manav
call from manav added to the queue.

Enter your choice: 1
Enter customer name: mansi
call from mansi added to the queue.

Enter your choice: 1
Enter customer name: sambhav
call from sambhav added to the queue.

Enter your choice: 3
Calls waiting in queue:
 manav
 mansi
 sambhav

Enter your choice: 2
call from manav is being attended by an agent.

Enter your choice: 3
Calls waiting in queue:
 mansi
 sambhav

Enter your choice: 2
call from mansi is being attended by an agent.

Enter your choice: 2
call from sambhav is being attended by an agent.

Enter your choice: 2
No calls in queue. System is waiting...

Enter your choice: 3
No calls in queue

Enter your choice: 4
Exiting system...

---