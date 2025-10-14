# Problem 225. Implement Stack using Queues - Notes

## Problem Understanding
- **Summary:** Implement a LIFO stack using only queue operations (`push`, `pop`, `front`, `size`, `empty`).  
- **Input:** Sequence of stack operations like `push(x)`, `pop()`, `top()`, and `empty()`.  
- **Output:** Return correct results for each operation as a normal stack would.

## Approach
### Initial Thoughts
- Queue operations expose elements in FIFO order, while stacks need LIFO behavior.  
- The challenge is to reverse the order so that the most recently pushed element becomes accessible first.  
- Two valid patterns:
  - **Rotate on `push`** -> expensive `push`, cheap `pop/top`.
  - **Rotate on `pop/top`** -> cheap `push`, expensive `pop/top`.  
- Key trick: Move the first `size - 1` elements to the back so the newest element reaches the front.

### Approach Taken
- **Solution 1 - O(n) pop/top, O(1) push:**  
  - Simply enqueue the new element.  
  - When popping or peeking, rotate `size - 1` elements to bring the last inserted item to the front.  
  - `top()` re-adds the item to preserve queue contents.  
  - **Time:** `push O(1)`, `pop O(n)`, `top O(n)`  
  - **Space:** `O(1)` auxiliary.

- **Solution 2 - O(n) push, O(1) pop/top:**  
  - After inserting, rotate the queue immediately so the new element is always at the front.  
  - Now `pop` and `top` can directly operate in `O(1)`.  
  - **Time:** `push O(n)`, `pop O(1)`, `top O(1)`  
  - **Space:** `O(1)` auxiliary.  

### Complexity:
- **Time:**  
  - Solution 1 -> `push O(1)`, `pop O(n)`, `top O(n)`  
  - Solution 2 -> `push O(n)`, `pop O(1)`, `top O(1)`  
- **Space:** `O(1)` for both since rotation only reuses the same queue.

## Challenges
### Obstacles Faced
- Forgetting to reinsert the front element in `top()` after rotation (to preserve order).  
- Ensuring correct rotation loop (`n = q.size() - 1`) without off-by-one errors.  

## Alternative Solutions
- Two-queue method -> dequeue all except last into a secondary queue, swap afterward.  
    - Not optimal but might be easier to reason about for beginners(i guess it depends on the person).

## Key Takeaways
- Rotating `size - 1` elements enables stack-like LIFO access in a FIFO structure.  
- Both push-heavy and pop-heavy optimizations are valid, balancing operation cost trade-offs.  
- Only standard queue operations (`push`, `pop`, `front`, `empty`) are used, maintaining full compliance.
