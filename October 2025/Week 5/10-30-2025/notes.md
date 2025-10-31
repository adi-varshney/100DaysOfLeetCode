# Problem 17. Letter Combinations of a Phone Number - Notes

## Problem Understanding

- Given a string containing digits from 2-9, generate all possible letter combinations those digits could represent on a phone keypad.
- Each digit maps to specific letters (e.g., 2 → “abc”, 3 → “def”, etc.).
- The task is to return all possible letter combinations in any order.
- If the input is empty, return an empty list.

## Approach

### Initial Thoughts

- This was my first backtracking problem, so I started by trying to understand how recursion explores all possible paths.
- Each digit can produce 3-4 possible letters, forming a branching recursion tree.
- The goal is to build all combinations by choosing one letter from each digit in sequence.
- The recursive idea: add a letter → move to next digit → once complete, backtrack by removing the letter.
- Realized that tracking an `index` was key to knowing which digit we’re currently processing.

### Approach Taken

- Defined a static `vector<string>` for digit-to-letter mappings.
- Wrote a helper function `backtrack` with parameters for the current string (`curr`), current index, and the results vector.
- Base case: when `curr.size()` equals `digits.size()`, push it into the result vector.
- Recursive case: iterate through all letters for the current digit, append each to `curr`, call `backtrack` for the next digit, then remove the last letter using `pop_back()` to undo the step.
- Used `const string& digits` and `const vector<string>& mappings` to avoid unnecessary copying and improve efficiency.

### Complexity:

- **Time:** `O(3^n ... 4^n)`, depending on the number of letters per digit (3 or 4).
- **Space:** `O(n)` for recursion depth plus the total output size `O(k)` (where `k` is the number of combinations).

## Challenges

### Obstacles Faced

- Forgetting to use `pop_back()` caused the string to grow incorrectly.
- Needed to understand the difference between base and recursive cases.
- Learning how to pass parameters by reference was important for efficiency.

<!-- ### Edge Cases -->

## Alternative Solutions

- An iterative BFS-like approach could also work, building up combinations level by level using a queue.
- But recursion with backtracking is much cleaner and easier to follow conceptually.

## Key Takeaways

- My first experience with backtracking taught me how recursion can explore all possible choices while undoing changes after each recursive call.
- Each recursion level corresponds to one digit in the input.
- Proper use of `push_back` and `pop_back` ensures correct combination generation.
- Passing parameters by reference significantly reduces memory usage.
- Backtracking problems often follow a similar pattern, base case, explore choices, recurse, and undo.
