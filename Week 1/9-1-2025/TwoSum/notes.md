## Problem Understanding
- **Summary**: Given an array and a target, find the (only) two values in the array that sum to target
- **Input**: An array of integers and a target, which is the sum we need to get to.  
- **Output**: The positions of the two integers that add up to the target.

## Approach
- **Initial Thoughts**: Since there is only one pair of numbers that satisfy the requirements, we just need to find which number has a complement in the array such that: num + complement(of that num) = target

- **Approach Taken**: HashSet to store 'visited' or 'seen' numbers to track if we have seen a certain numbers complement(complement = target - curr num) yet. Efficient due to its time complexity.

<!-- ## Approach 2
- **Initial Thoughts**: 
- **Approach Taken**: 
- **Why This Approach**:  -->

<!-- ## Challenges
- **Obstacles Faced**: 
- **Edge Cases**: None -->

## Optimization
- **Time Complexity**: O(n), O(1) * n
- **Space Complexity**: O(n), one (hash)set with size of n

## Alternative Solutions
- Brute forcing over all values(this is what I initially did)
    * Time complexity is O(n<sup>2</sup>)
    * Space complexity is O(1).
- Sorting and using two pointers(did think of this but kept looking for more efficient method time complexity wise).
    * Time complexity is O(n), O(log(n) + n)
    * Space Complexity is O(1)

## Key Takeaways
- HashSets may be applicable to a problem if it involves finding two related values.

<!-- ## Additional Resources
- N/A -->