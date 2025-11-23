# Assignment No: 1 (UNIT 3) 
# Title: WAP to build a simple stock price tracker that keeps a history of daily stock prices entered by the user. To allow users to go back and view or remove the most recent price, implement a stack using a linked list to store these integer prices.
Implement the following operations:
1.	record(price) – Add a new stock price (an integer) to the stack.
2.	remove() – Remove and return the most recent price (top of the stack).
3.	latest() – Return the most recent stock price without removing it.
4.	isEmpty() – Check if there are no prices recorded.


---

## **Concepts Used**
- Structures  
- Linked List  
- Stack (LIFO) operations  
- Dynamic Memory Allocation  
- Menu-driven Programming  

---

## **Pseudocode**

```
STEP 1: Start

STEP 2: Define a structure NODE with:
        - data (integer)
        - next (pointer to NODE)

STEP 3: Define a class StockPriceStack with:
        - top pointer (initially NULL)

STEP 4: Define function isEmpty():
        IF top == NULL
            RETURN true
        ELSE
            RETURN false

STEP 5: Define function record(price):
        5.1 Create newNode with given price
        5.2 Set newNode.next = top
        5.3 Update top = newNode
        5.4 Print "recorded price"

STEP 6: Define function remove():
        6.1 IF stack is empty
                Print "no prices to remove"
                RETURN
        6.2 temp = top
        6.3 removedPrice = temp.data
        6.4 Update top = top.next
        6.5 Delete temp
        6.6 Print removed price

STEP 7: Define function latest():
        7.1 IF stack is empty
                Print "no prices recorded yet"
                RETURN
        7.2 Print top.data

STEP 8: Define function display():
        8.1 IF stack is empty
                Print "no prices recorded yet"
                RETURN
        8.2 temp = top
        8.3 WHILE temp != NULL
                Print temp.data
                Move temp = temp.next

STEP 9: In MAIN:
        9.1 Create object sp of StockPriceStack
        9.2 Repeat menu until user chooses exit (choice = 6):
                - Display menu
                - Read choice
                - IF choice is:
                    1 → record new price
                    2 → remove latest price
                    3 → show latest price
                    4 → check if empty
                    5 → display all prices
                    6 → EXIT
                    otherwise → Print invalid choice

STEP 10: End
```


## ** Output**

```
-------Stock Price Tracker---------

1. record new price
2. remove latest price
3. view latest price
4. check if empty list
5. display all prices
6. exit
enter your choice: 1
enter stock price to record: 500
recorded price : 500

enter your choice: 1
enter stock price to record: 540
recorded price : 540

enter your choice: 5
price history : 540 500

enter your choice: 3
latest recorded price : 540

enter your choice: 2
the most recent price has been removed: 540

enter your choice: 5
price history : 500

enter your choice: 6
exiting...

All prices removed successfully.
```
