<!-- Problem 88. Merge Sorted Array notes -->

## Problem Understanding

- **Summary**: Merge two **sorted** arrays `nums1` (size `m + n`, last `n` are 0 placeholders) and `nums2` (size `n`) into `nums1` in **non-decreasing** order.
- **Input**: Two int arrays: `nums1`, m valid elements and `nums2`, n elements.
- **Output**: In-place merge inside `nums1`.

## Approach

- **Initial Thoughts**:

  - At first, I just thought "ok, classic merge problem like merge sort, just use two pointers from the front and write into `nums1`."
  - But then I realized `nums1` doesn’t have clean extra space in the middle, the valid elements are right there at the start, so if I try to insert `nums2`’s elements in front, I’d end up overwriting stuff in `nums1` before I’ve even compared it.
  - I was kinda stuck here for a while, because I kept thinking about how to shift elements forward every time (which would be super messy and `O(n^2)` if I did it naively).
  - Eventually I realized the trick. Since, `nums1` already has empty slots at the **end**, so why not build the result from the back? That way, I don’t overwrite any "good" elements in `nums1` before I’ve used them.
  - Once I flipped my thinking to start from the **end** and go backwards, the whole problem became straightforward. I just had to compare the largest remaining elements and drop them in the back slot.

- **Approach Taken**:
  - I set up three pointers:
    - `i1 = m - 1` → the index of the last valid element in `nums1`.
    - `i2 = n - 1` → the index of the last element in `nums2`.
    - `i = m + n - 1` → the index of the last position in `nums1` where we’ll be writing.
  - Starting from the end, I compare `nums1[i1]` and `nums2[i2]`. Whichever one is larger goes into `nums1[i]`.
  - After placing the larger element, I move that pointer (`i1` or `i2`) one step left, and also move `i` left.
  - If one of the arrays runs out of elements:
    - If `i1 < 0`, just copy the remaining elements from `nums2` into `nums1`.
    - If `i2 < 0`, the remaining elements in `nums1` are already in place, so I can stop.
  - This way, every step fills in the next “largest” element from the back, ensuring no overwriting of unprocessed data.

## Challenges

- **Obstacles Faced**: My first thought, which was "merge forward," risks overwriting `nums1`’s valid elements before they’re compared. Writing from the end avoids that entire headache.
<!-- - **Edge Cases**: None -->

## Complexity

- **Time**: `O(M + N)`, every element is written exactly once(thus add `M` elements of `nums1` and `N` elements of `nums2`).
- **Space**: `O(1)`, all in place, just pointers.

<!-- ## Alternative Solutions

- none -->

## Key Takeaways

- When merging in place and the target buffer is the first array, think right-to-left to avoid overwrites.

- For array problems(especially sorting) in general, sometimes starting from the end makes things easier and cleaner than starting at the front.

- Two-pointer patterns aren’t just for forward scans; reversing direction can make in-place operations easy/simpler.

- Always handle "one array exhausted" paths explicitly, it simplifies the main compare step.

<!-- ## Additional Resources
- N/A -->
