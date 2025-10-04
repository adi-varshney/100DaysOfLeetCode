# Problem 171. Excel Sheet Column Number - Notes

## Problem Understanding
- **Summary:** convert an Excel-style column title to its number using base-26 where A maps to 1 and Z maps to 26
- **Input:** `string` column title containing uppercase letters A to Z
- **Output:** `int` representing the column number
<!-- - **Constraints:** none explicitly stated on time or space -->

## Approach
### Initial Thoughts
- treat the title as base-26 with digits A to Z valued 1 to 26  
- compute positional weight from left to right like decimal conversion but with base 26  
- subtract `'@'` which is one less than `'A'` to get 1 to 26 cleanly  

### Approach Taken
- iterate i from 0 to n-1  
- for each character multiply 26 raised to the power of position weight and multiply by its value `(columnTitle[i] - '@')` then add to answer  
- return the accumulated sum

### Complexity:
- **Time:** `O(n)` where n is the length of the title
- **Space:** `O(1)`

<!--
## Challenges
### Obstacles Faced
-  

### Edge Cases
-  
-->

## Alternative Solutions
- iterative accumulate without `pow` left to right  
  - maintain `ans` then for each character set `ans = ans * 26 + (ch - '@')`  
  - avoids floating point `pow` and rounding risk and stays integer only  
- right to left accumulation  
  - track a running `place = 1` then add `(value * place)` and update `place *= 26` each step

## Key Takeaways
- map A to 1 not 0 then treat as base-26  
- multiplying running total by 26 then adding value is clean and avoids floating math  
- subtraction with `'@'` is a simple way to get values 1 to 26
