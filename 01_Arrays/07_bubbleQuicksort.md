# Assignment No: 7 

## **Title:**  WAP to implement Bubble sort and Quick Sort on a 1D array of Student structure (contains student_name, student_roll_no, total_marks), with key as student_roll_no. And count the number of swap performed by each method.

---

## **Pseudocode**

### **1. Bubble Sort**
1. Repeat for i = 0 to n-2  
2.   Repeat for j = 0 to n-2-i  
3.     If arr[j].roll > arr[j+1].roll  
4.       Swap arr[j] and arr[j+1]  
5. Count total swaps  

---

### **2. Quick Sort**
1. Select first element as pivot  
2. Move start forward until value > pivot  
3. Move end backward until value ≤ pivot  
4. If start < end → swap  
5. Place pivot in correct position  
6. Recursively sort left and right sides  
7. Count swaps  


---

## **Output**

```
Enter number of students: 3

Enter details of student 1:
Roll No: 12
Name: Raj
Total Marks: 88

Enter details of student 2:
Roll No: 5
Name: Meera
Total Marks: 91

Enter details of student 3:
Roll No: 20
Name: John
Total Marks: 76


Bubble Sort
-----------------------------------
Roll No   Name    Marks
5         Meera   91
12        Raj     88
20        John    76
No. of swaps (Bubble Sort): 1


Quick Sort
-----------------------------------
Roll No   Name    Marks
5         Meera   91
12        Raj     88
20        John    76
No. of swaps (Quick Sort): 2
```


