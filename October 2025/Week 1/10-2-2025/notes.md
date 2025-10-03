# Problem 168. Excel Sheet Column Title - Notes

## Problem Understanding
- **Summary:** convert a positive integer to its Excel column title where A maps to 1 and Z maps to 26 and after Z comes AA then AB and so on like a 26-based system that is 1-indexed  
- **Input:** integer columnNumber positive  
- **Output:** string title consisting of uppercase A-Z characters  
<!-- - **Constraints:** 1 <= columnNumber <= 2^31 - 1 -->

## Approach

### Initial Thoughts
- Looks like base conversion but digits run from 1 to 26 rather than 0 to 25  
- When remainder is 0 the character should be Z and the number should borrow one from the next place  
- Repeatedly peel off the last letter using modulo and division then build the string in reverse  

### Approach Taken
- While columnNumber > 0 compute columnNumber % 26  
- If remainder == 0 append Z then decrement columnNumber by 1 before dividing by 26  
- Else map remainder r to char '@' + r because '@' is just before 'A' in ASCII  
- Prepend each computed char to the answer then divide columnNumber by 26 and continue  
- Return the built string  

### Complexity:
- **Time:** `O(log_26(n))`  
- **Space:** `O(1)` aside from output  

<!--
## Challenges
### Obstacles Faced
- • 
### Edge Cases
- • 
-->

## Alternative Solutions
- Decrement-then-convert pattern perform columnNumber-- at loop start then take r = columnNumber % 26 map r to 'A' + r and divide columnNumber by 26 simple and avoids special case for Z then reverse the built characters  
- Recursive version apply the same logic columnTitle(n) = columnTitle((n-1)/26) + char('A' + (n-1)%26) neat but uses call stack

## Key Takeaways
- Treat the system as base 26 with digits 1..26 not 0..25  
- Handle multiples of 26 with Z and a borrow or use the decrement-then-convert trick to simplify  
- Mapping tip use '@' + r for r in 1..26 or use 'A' + ((n-1)%26) after a decrement
