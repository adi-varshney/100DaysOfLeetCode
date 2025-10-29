# Problem 15. 3Sum - Notes

## Problem Understanding

- **Summary:** Find all unique triplets `(a, b, c)` in an integer array such that their sum equals 0 (`a + b + c = 0`).
- **Input:** A vector of integers `nums` where `3 <= nums.length <= 3000` and `-10⁵ <= nums[i] <= 10⁵`.
- **Output:** A vector of triplets where each triplet is a combination of three numbers from `nums` that sum to zero, with no duplicate triplets.

- **Key Points:**
  - Order of numbers in the triplet doesn’t matter.
  - The same element cannot be reused by index (i != j != k).
  - Triplets must be unique and sorted for consistent comparison.

## Approach

### Initial Thoughts

- The brute-force method would check all combinations of three numbers, `O(n³)`, too slow for `n = 3000`.
- Sorting allows using **binary search** or the **two-pointer** method to reduce complexity.
- Duplicate triplets must be avoided, sorting helps with that by grouping identical elements together.
- Binary search gives `O(n² log n)` but can be improved to `O(n²)` using two pointers.

### Approach Taken

#### 1. Binary Search (`O(n² log n)`)

- **Steps:**
  - Sort the array.
  - Iterate through pairs `(i, j)` and binary search for the third value `k` such that `nums[i] + nums[j] + nums[k] = 0`.
  - Use a `set<array<int,3>>` to store unique triplets automatically.
- **Pros:** Easy to implement and clear logic.
- **Cons:** Slightly slower due to `log n` factor and set overhead.

#### 2. Two-Pointer (`O(n²)`)

- **Steps:**
  - Sort the array.
  - For each element `nums[i]` (the fixed value `a`):
    - Skip duplicates for `a`.
    - Use two pointers (`left`, `right`) to find pairs `(b, c)` such that `a + b + c = 0`.
    - Move pointers inward based on sum comparison.
    - Skip duplicates for both `b` and `c`.
  - Stop early if `nums[i] > 0` (since remaining numbers are positive).
- **Pros:** More efficient and clean; avoids binary search.
- **Cons:** Slightly more careful duplicate handling needed.

### Complexity:

- **Time:**
  - Binary search version: `O(n² log n)`
  - Two-pointer version: `O(n²)`
- **Space:**
  - Binary search: `O(k)` for storing unique triplets in a set.
  - Two-pointer: `O(1)` extra (excluding output).

## Challenges

### Obstacles Faced

- Handling duplicates across multiple layers (especially for `i`, `left`, and `right`).
- Making sure the binary search doesn’t reuse the same index.
- Transitioning from `O(n² log n)` to `O(n²)` with pointer logic.

### Edge Cases

- Arrays with all zeros `[0,0,0,0]` → Only one triplet `[0,0,0]`.
- No valid triplets, e.g., `[0,1,1]`.
- Large positive/negative numbers.

## Alternative Solutions

- **Hashset-based two-sum per iteration:**
  - Similar to 3Sum but uses hashset for complement checking (O(n²) average, but more space).
- **Brute Force:**
  - Check all triplets, `O(n³)`, not feasible for large inputs.

## Key Takeaways

- Sorting the array is crucial for both duplicate handling and efficient searching.
- The two-pointer technique simplifies 3Sum to an intuitive and efficient pattern.
- `O(n²)` is optimal for this problem; all faster solutions rely on variants of the same idea.
- Using a `set` simplifies uniqueness but adds overhead, pointer-based duplicate skipping is cleaner.
