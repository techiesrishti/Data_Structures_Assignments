# **Assignment No.: 10**

## **Title:**  
Write a program to arrange the list of employees as per the average of their height and weight using **Merge Sort** and **Selection Sort**.  
Analyse their time complexities and conclude which algorithm takes less time to sort the list.

---

## **Pseudocode**

### **1. Input Employee Details**
1. Read number of employees `n`
2. For each employee:
   - Read `name`
   - Read `height`
   - Read `weight`
   - Compute `avg = (height + weight) / 2`

---

### **2. Selection Sort (Ascending by avg)**
1. Repeat for each index `i`:
   - Assume `minIndex = i`
   - For each `j > i`, if `arr[j].avg < arr[minIndex].avg`, update `minIndex`
   - Swap employee at `i` with employee at `minIndex`

---

### **3. Merge Sort (Ascending by avg)**

#### **MergeSort Procedure**
1. If `lb < ub`:
   - Find `mid = (lb + ub) / 2`
   - Recursively sort left half
   - Recursively sort right half
   - Call merge function

#### **Merge Procedure**
1. Compare elements of two halves
2. Copy smaller `avg` to temporary array
3. Copy remaining elements
4. Transfer merged result back to original array

---

### **4. Display Function**
1. Print Name, Height, Weight, Average for each employee

---

### **5. Complexity Analysis**
- Selection Sort → **O(n²)**
- Merge Sort → **O(n log n)**
- Merge Sort is more efficient for large datasets.

---

## **Output**
Enter number of employees: 5

Enter details of employee 1:
Name: Riya
Height: 160
Weight: 52

Enter details of employee 2:
Name: Arjun
Height: 175
Weight: 68

Enter details of employee 3:
Name: Meera
Height: 158
Weight: 60

Enter details of employee 4:
Name: Karan
Height: 170
Weight: 75

Enter details of employee 5:
Name: Sana
Height: 165
Weight: 55

Employees sorted by Selection Sort:

Name Height Weight Average

Meera 158 60 109
Riya 160 52 106
Sana 165 55 110
Arjun 175 68 121.5
Karan 170 75 122.5

Employees sorted by Merge Sort:

Name Height Weight Average

Meera 158 60 109
Riya 160 52 106
Sana 165 55 110
Arjun 175 68 121.5
Karan 170 75 122.5

--- Complexity Analysis ---
Selection Sort: O(n²)
Merge Sort: O(n log n)
Merge Sort is more efficient for larger datasets.

