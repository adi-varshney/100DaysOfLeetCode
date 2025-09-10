<!-- Problem 35. Search Insert Position notes -->
## Problem Understanding

- **Summary**: Given a *sorted* array(`nums`) of distinct integers(`int[]`) and a `target` value, return the index if the `target` is found. If not, return the index where it would be if it were inserted in order(hypothetically, pushing all indices after that index one position forward). Solution must be O(log n)
- **Input**: An *array of integers*(`nums`) and a `target`, which is the value that we need to find in `nums`.
- **Output**: An *integer*, the starting index of the first match (or `-1` if no match).

## Approach

- **Initial Thoughts**:
  - The first thing that comes to mind to me, is that the time complexity restriction to `O(log n)` implies binary search would be a very efficient algorithm to use here.
  - Using a half-open interval *(noninclusive)* **(low, high]** *(inclusive)* avoids off-by-one mistakes(initialize `low = 0`, `high = nums.length`). Keep looping `while (low < high)`.
  - Compute `mid` with `low + (high - low) / 2` to avoid potential overflow.
  - Compare `nums[mid]` with `target` and shrink the search window in half accordingly.

- **Approach Taken**:
  - Maintain that the answer (the first position `>= target`) always lies in the window **(low, high]**.
  - Steps:
    - `low = 0`, `high = n` (note high starts one past the last index).
    - While `low < high`:
      1. `mid = low + (high - low) / 2`
      2. If `nums[mid] == target`, return `mid` (exact hit).
      3. If `nums[mid] > target`, set `high = mid` (the answer could be `mid`, so keep it).
      4. Else (`nums[mid] < target`), set `low = mid + 1` (answer must be after `mid`).
    - When the loop ends, `low == high` and both point to the insertion index. `return low`(or `high`).

- **Edge Cases Checked**:
  - Initialize high = n (one past the last index) — not n - 1.
    - This uses the **(low, high]** window so *if target is greater than every value/last value in the sorted array*(in other words, `if (target > nums[nums.length-1])`), the loop ends with `low = n` and you correctly return `n` (insert at the end, outside current index bounds).
  - If `nums[mid] > target` then set `high = mid` (not `mid + 1`)
    - This is because even when the index being checked is greater than the `target`, the desired output could still be that index as long as the every index before that is less than the `target`(essentially we are preserving `mid` as a **possible point of insertion**).
  - Conversely, If `nums[mid] < target` then set `low = mid + 1`, as mid cannot be the answer anymore(the `target` value must be _found_ or _placed_ some point **AFTER** `mid`).

## Optimization

- **Time Complexity**: `O(log n)`, where N = length of needle and M = length of haystack.
- **Space Complexity**: `O(1)`, binary search doesn't require any data structures so we just make use of variables in constant space.

<!-- ## Alternative Solutions
 - none that come to mind for me -->

## Key Takeaways

- When and how to check edge cases on binary search implementations.
  - Half-open intervals **(low, high]** make binary search boundaries cleaner.
  - Maintain that your answer always remains inside your window.
  - Returning `low` after the loop is the standard way to get the insertion index (lower bound).
