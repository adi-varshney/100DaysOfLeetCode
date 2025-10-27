# Problem 232. Implement Queue using Stacks - Notes

## Problem Understanding

- **Summary:** Build a FIFO queue using only stack operations. Support push, pop, peek, and empty.
- **Input:** A sequence of operations with integer values for pushes.
- **Output:** Return values for pop and peek along with boolean for empty.

## Approach

### Initial Thoughts

- I want true FIFO behavior while only using LIFO tools.
- I can flip order with a helper stack to keep the queue front on top of the main stack.
- This makes pop and peek easy since the current front will sit at the main stack top.

### Approach Taken

- Keep two stacks named `s` and `reverse`.
- For `push(x)` move all items from `s` to `reverse`, push `x` onto `s`, then move everything back from `reverse` to `s` so the newest item ends up at the bottom and the oldest stays on top.
- For `pop()` return `s.top()` then `s.pop()`.
- For `peek()` return `s.top()`.
- For `empty()` check `s.empty()`.

### Complexity:

- **Time:** `O(n)` per push in the worst case, `O(1)` for pop, peek, and empty.
- **Space:** `O(n)` additional space for the stacks.

## Challenges

### Obstacles Faced

- Deciding whether to pay the cost on push or on pop to preserve FIFO.

### Edge Cases

- Popping or peeking when empty should be guarded by the caller in LeetCode tests.

## Alternative Solutions

- Use two stacks called `inStack` and `outStack`.
- Push goes to `inStack` which is `O(1)`.
- Pop and peek pull from `outStack`. If `outStack` is empty, move all items from `inStack` to `outStack` once. This gives amortized `O(1)` for all operations while keeping worst case single transfer when `outStack` is refilled.
  - I think this is technically faster but both solutions get 100%, 0ms Runtime and they both have the same memory efficiency so I didn't bother coding the other(I think you get the idea though).

## Key Takeaways

- Flipping with a helper stack makes the front sit on top which simplifies pop and peek.
- This implementation trades `O(n)` push for constant time removal and access.
- The two stack in and out method is the common optimization with amortized `O(1)` across operations.
