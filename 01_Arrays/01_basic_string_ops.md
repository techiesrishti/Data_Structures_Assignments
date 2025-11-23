# Assignment No. 1
## TITLE: Implement basic string operations such as length calculation, copy, reverse, and concatenation using character single dimensional arrays without using built-in string library functions

## Basic String Operations using Character Array
1. Length of a string
2. Copy a string
3. Reverse a string
4. Concatenate two strings

## Pseudocode

### 1. Calculate Length of String
Step 1: Initialize len_sp = 0  
Step 2: Repeat until str_sp[len_sp] != '\0'  
            len_sp++  
Step 3: Return len_sp  

---

### 2. Copy a String
Step 1: Initialize i_sp = 0  
Step 2: Repeat until src_sp[i_sp] != '\0'  
            dest_sp[i_sp] = src_sp[i_sp]  
            i_sp++  
Step 3: Set dest_sp[i_sp] = '\0'  

---

### 3. Reverse a String
Step 1: Find length of string → len_sp  
Step 2: Set start_sp = 0 and end_sp = len_sp - 1  
Step 3: Repeat while start_sp < end_sp  
            temp_sp = str_sp[start_sp]  
            str_sp[start_sp] = str_sp[end_sp]  
            str_sp[end_sp] = temp_sp  
            start_sp++  
            end_sp--  

---

### 4. Concatenate Two Strings
Step 1: Compute length of first string → len3_sp  
Step 2: Initialize i_sp = 0  
Step 3: Repeat until str2_sp[i_sp] != '\0'  
            str1_sp[len3_sp + i_sp] = str2_sp[i_sp]  
            i_sp++  
Step 4: Set str1_sp[len3_sp + i_sp] = '\0'  

---

## Sample Output (Example)
Enter 1st string: hello  
Enter 2nd string: world  

Length of 1st string: 5  
Length of 2nd string: 5  

Copy of 1st string: hello  

Reverse of 1st string: olleh  
Reverse of 2nd string: dlrow  

Concatenated strings: ollehdlrow
