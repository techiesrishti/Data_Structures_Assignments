# Assignment No 6
## TITLE : In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Tech. students. Assume that all these students are on ground for a function. We need to identify a student of S.Y. div. (X) whose name is "XYZ" and roll no. is "17". Apply appropriate Searching method to identify the required student.

**Student Search Operation**
1. Accept student records  
2. Check each record sequentially  
3. Compare with target student details  
4. If match found - Display position  
5. If "stop" entered - Terminate search  

---

## Pseudocode

### 1. Input Student Records
Step 1: Initialize count = 1  
Step 2: Loop infinitely  
  Prompt user to enter student details  
  Read name_sp  

Step 3: If name_sp == "stop"  
  Print "Stopped. No record found"  
  Exit loop  

Step 4: Read div_sp, rollNo_sp, year_sp  

---

### 2. Compare With Target Student
Step 1: If  
  name_sp == "XYZ"  
  AND div_sp == "X"  
  AND rollNo_sp == 17  
  AND year_sp == "SY"  
  - Print "Student found at count"  
  - Exit loop  

Step 2: Else print "No record found"  

---

### 3. Continue Searching
Step 1: Increment count  
Step 2: Repeat loop  

---

## Algorithm

### Step 1: Start  
### Step 2: Initialize target student details:  
- Name = "XYZ"  
- Division = "X"  
- Roll No = 17  
- Year = "SY"  

### Step 3: Read user-input student data  
### Step 4: If user enters "stop" → Stop search  
### Step 5: Compare entered data with target  
### Step 6: If all fields match → Student found  
### Step 7: If not → Continue searching  
### Step 8: Repeat until found or user stops  
### Step 9: Stop  

---

## Output 

**Input:**  
ABC X 21 SY  
No record found  

**Input:**  
PQR Y 10 SY  
No record found  

**Input:**  
XYZ X 17 SY  
Student found at 3  

---

