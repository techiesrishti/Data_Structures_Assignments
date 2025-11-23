# Assignment No: 8

## **Title:**  Write a program to input marks of n students Sort the marks in ascending order using the Quick Sort algorithm without using built-in library functions and analyse the sorting algorithm pass by pass. Find the minimum and maximum marks using Divide and Conquer (recursively).

---

## **Pseudocode**

### **1. Quick Sort**
**Step 1:** Choose the first element as pivot  
**Step 2:** Set start pointer = lb + 1  
**Step 3:** Set end pointer = ub  
**Step 4:** Move start forward while arr[start] ≤ pivot  
**Step 5:** Move end backward while arr[end] > pivot  
**Step 6:** If start < end → swap elements  
**Step 7:** When pointers cross → swap pivot with arr[end]  
**Step 8:** Recursively sort left and right partitions  

---

### **2. Partition Function**
**Step 1:** Initialize pivot = arr[lb]  
**Step 2:** Loop until start ≥ end  
**Step 3:** Adjust pointers (start++, end--)  
**Step 4:** Swap elements when necessary  
**Step 5:** Place pivot in final correct position  
**Step 6:** Return pivot index  

---

### **3. Min–Max Divide and Conquer**
**Step 1:** If lb == ub → min = max = arr[lb]  
**Step 2:** If two elements → directly compare  
**Step 3:** Split array into 2 halves  
**Step 4:** Recursively compute (min1, max1) and (min2, max2)  
**Step 5:** Final result:  
- **min = minimum of both mins**  
- **max = maximum of both maxes**  

---

## **Sample Output**

```
Enter number of students: 6
Enter marks of student 1: 45
Enter marks of student 2: 89
Enter marks of student 3: 12
Enter marks of student 4: 67
Enter marks of student 5: 90
Enter marks of student 6: 33

original array
45 89 12 67 90 33

Pass 1---- pivot 45 is placed at 2
Swaps:2    12 33 45 67 90 89

Pass 2---- pivot 12 is placed at 0
Swaps:0    12 33 45 67 90 89

Pass 3---- pivot 33 is placed at 1
Swaps:0    12 33 45 67 90 89

Pass 4---- pivot 45 is placed at 2
Swaps:0    12 33 45 67 90 89

Pass 5---- pivot 67 is placed at 5
Swaps:1    12 33 45 67 89 90

Pass 6---- pivot 89 is placed at 4
Swaps:1    12 33 45 67 89 90


sorted marks in ascending order
12 33 45 67 89 90

total swaps performed: 4
min marks 12
max marks 90
```

