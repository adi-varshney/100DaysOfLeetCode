# Problem 136. Single Number - Notes

## Problem Understanding
- **Summary:** Every value appears exactly twice except one value return the unique number
- **Input:** A _vector\<int\>_ `nums` with length 1…3e4 and values in -3e4…3e4
- **Output:** The single _int_ that does not have a duplicate
- **Key Constraints:** Must use linear time and constant extra space

## Approach
### Initial Thoughts
- My first instinct was sorting and then scanning in pairs, which is straightforward(was my first solution), but sorting has a O(N*logN) runtime which doesn't satisfy the constraint the problem gives us
- After that though I got a little stuck so needed to look at the hint which was about XOR and bitwise operators
- Then I realize XOR is promising because `a ^ a = 0` and `a ^ 0 = a`
- I am considering that XOR is associative and commutative so fold order does not matter
- I think bitwise operations avoid overflow concerns since they work on bits not sums

### Approach Taken
- Keep a running accumulator `ans = 0`
- For each number do `ans ^= num`
- Pairs cancel to zero and only the single number survives
- Return `ans`

### Complexity:
- **Time:** `O(n)`
- **Space:** `O(1)`

<!--
## Challenges
### Obstacles Faced
- 
### Edge Cases
- 
-->

## Alternative Solutions
- **Sort then scan(my original solution)**
  - Sort array and compare in steps of two until a mismatch is found
  - **Time:** `O(n log n)`
  - **Space:** `O(1)` or `O(n)` depending on sort
- **Hash set toggle**
  - Insert unseen value and erase when seen again leaving one element at the end
  - **Time:** `O(n)` average
  - **Space:** `O(n)`
- **Sum trick**
  - Compute `2 * sum(unique)` minus `sum(all)` which equals the single number
  - **Time:** `O(n)`
  - **Space:** `O(n)` to track unique values

## Key Takeaways
- Sorting is a safe fallback but not always optimal if linear time is required  
- XOR is perfect for problems where pairs cancel out and only one element should remain  
- Bitwise operators are worth considering when:
  - dealing with integers  
  - the problem involves toggling, pairing, or cancellation  
  - you need constant space and a simple fold across elements  
- Even if not obvious at first, bitwise tricks can be the cleanest solution for integer-based problems
