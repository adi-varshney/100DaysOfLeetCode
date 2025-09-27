# Problem 26. Remove Duplicates from Sorted Array - Notes
## Problem Understanding
 - **Summary**: Given a sorted list(least to greatest), remove all duplicate integers/list all unique integers in order and find total # of unique integers.
 - **Input**: An integer array(`int[]`) that contains the sorted list(with duplicates).
 - **Output**: An `integer`, signifying the # of unique integers in the list.

## Approach
 - **Initial Thoughts**:
     * This is a case in which we implement a, fast pointer/slow pointer,  two pointer concept. 
     * To solve this problem, we need to keep track of two things while we iterate:
    1. The index of the current last unique integer in the list(slow pointer)
    2. A pointer that iterates through the entire list, searching for the next unique number.

 - **Approach Taken**:
     * Initialize a variable `currPos = 0` which represents the index of the last unique integer.
     * Iterate through the array with a `pointer` from start to end.
     * Whenever a new unique value (`nums[pointer] > nums[currPos]`) is found:
       - Increment `currPos` by 1.
       - Replace the element at `nums[currPos]` with this unique value.
     * By the end of iteration, all unique numbers will be placed in the first `currPos+1` positions of the array.
     * Return `currPos + 1` as the total count of unique integers.

<!-- ## Challenges
 - **Obstacles Faced**:
 - **Edge Cases**: -->

## Optimization
 - **Time Complexity**: `O(n)`, since we iterate through the list exactly once.
 - **Space Complexity**: `O(1)`, as all operations are performed in-place without using extra memory.

<!-- ## Alternative Solutions
- None that come to mind. -->

## Key Takeaways
 - Learned how to effectively apply the **two-pointer technique** to in-place array problems.
 - Leveraged sorted order to simplify duplicate removal.
 - Gained practice with in-place updates while ensuring correct return values (length of unique section).

<!-- ## Additional Resources
- N/A -->