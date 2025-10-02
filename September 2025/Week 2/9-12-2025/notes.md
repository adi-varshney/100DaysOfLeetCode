# Problem 83. Remove Duplicates from Sorted List - Notes
## Problem Understanding
 - **Summary**: Given the `head` of a *sorted* singly linked list, delete duplicates so each value appears once, and return the list **still sorted**.
 - **Input**: `head` → first node of a singly linked list where node values are in non-decreasing order.
 - **Output**: The same list with all consecutive duplicates removed (i.e., each unique value appears exactly once).

## Approach
 - **Initial Thoughts**:
     * Looking at this problem, right off the bat I think that this could be an efficient use case for a `HashSet` (*to track what I've seen and snip nodes when I see a repeat*). That’s usually the first thing that comes to mind whenever I hear "duplicates."
     * But after finishing the set version and testing, I realized that there was actually a faster solution... (oops :/).
     * If it’s sorted, dupes are adjacent, so I don’t need global memory at all.
     * I originally thought both would be basically O(n) so the sorted-ness wouldn’t change “speed.” That’s true asymptotically for time, but the sorted trick gives me O(1) extra space and, contrary to my beliefs, actually does make the code slightly faster because it reduces number of total operations used in HashSet.add().

 - **Approach Taken**:
   - **In-place single pass w/o HashSet(preferred)**
     - Use `it` as an iterator, setting `it = head`.
     - `while (it != null && it.next != null)`:

       - If `it.val == it.next.val`, bypass duplicate via `it.next = it.next.next` (don’t advance yet).

       - Else, advance `it = it.next`.

       - Return `head`.

   - **My first pass (works but unnecessary memory and like *slightly* slower)**

     - Keep `seen` set; walk with `prev`/`it`. If `it.val` in `seen`, unlink it; else add and advance.

     - Correct, but ignores the sorted property and uses extra memory.

<!-- ## Challenges
 - **Obstacles Faced**:
 - **Edge Cases**: -->

## Optimization
 - **Time Complexity**: Both approaches are `O(N)` (one pass, but hash ops are *amortized* O(1), meaning it is constant time but still takes more operations than just a single check, and overtime build up).
 - **Space Complexity**: set approach `O(N)` extra; in-place `O(1)` extra (wayy better).

<!-- ## Alternative Solutions
- None that come to mind. -->

## Key Takeaways
 - My first move was a `HashSet`, which worked, but I realized later that the sorted part basically makes it unnecessary. Kinda a reminder to actually use the hints in the setup instead of brute-forcing.

 - I usually think about time first, but here I noticed space and code simplicity can also matter/make a difference. both end up `O(N)` time, but constant space feels cleaner.

 - Sorted data often just means "check neighbors."

 - Doing two versions back-to-back also helped me that recognizing patterns like that is something I should carry into other stuff (arrays, strings, etc.).

<!-- ## Additional Resources
- N/A -->