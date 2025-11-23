## **Assignment No: 9** 

## **Title:  Write a program using Bubble sort algorithm, assign the roll nos. to the students of your class as per their previous years result. i.e. topper will be roll no. 1 and analyse the sorting algorithm pass by pass.**

---

## **Pseudocode**

### **1. Input Phase**
1. Read number of students `n`
2. For each student:
   - Read `name`
   - Read `marks`
   - Set `roll_no = 0`

### **2. Bubble Sort (Descending Order of Marks)**
1. Repeat for each pass:
   - Compare adjacent students
   - If current.marks < next.marks → swap
2. Display marks after every pass

### **3. Roll Number Assignment**
1. For sorted list:
   - roll_no = index + 1

### **4. Final Output**
1. Display Roll No, Name, Marks

---

## **Output**
Enter number of students: 5

Enter name of student 1: Arjun
Enter previous-year marks of Arjun: 76

Enter name of student 2: Meera
Enter previous-year marks of Meera: 89

Enter name of student 3: Rahul
Enter previous-year marks of Rahul: 67

Enter name of student 4: Sana
Enter previous-year marks of Sana: 92

Enter name of student 5: Karan
Enter previous-year marks of Karan: 81

Pass 1:
89 76 92 81 67

Pass 2:
89 92 81 76 67

Pass 3:
92 89 81 76 67

Pass 4:
92 89 81 76 67

Final Roll No Assignment:
Roll No Name Marks

1 Sana 92
2 Meera 89
3 Karan 81
4 Arjun 76
5 Rahul 67
