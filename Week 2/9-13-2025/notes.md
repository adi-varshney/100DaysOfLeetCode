# Problem 70. Climbing Stairs - Notes
## Problem Understanding

- **Summary**: Given an _integer_ `n`, return the number of distinct ways to climb to the top when each move can be `1` or `2` steps.
- **Input**: An _integer_, n (`1 <= n <= 45`).
- **Output**: An _integer_, the count of unique step sequences to reach step n.

## Approach

- **Initial Thoughts**:

  - Well given that you can either take _1 step_ or _2 steps_, the first process that came to my mind was: _how to get to any step,_ `n`.
    - In this case, either I start from `n-1` (take a `+1` step) or from `n-2` (take a `+2` steps).
  - So `uniqueWays(n) = uniqueWays(n-1) + uniqueWays(n-2)`.
  - I first built it bottom-up from the smalls(set base cases): `n=1`, `n=2`, (and I tossed in `n=3` as a convenience).
  - Only later did I realize this is literally the Fibonacci pattern (shifted): `1, 2, 3, 5, 8, ...`. Didn’t name it that at first, but yeah, same recurrence.

- **Approach Taken**:
  - I used a `HashMap<Integer, Integer>` to store computed counts.
  - Base: `steps[1]=1`, `steps[2]=2`, `steps[3]=3`.
  - Iterate from `i=4` to `n`: `steps[i] = steps[i-1] + steps[i-2]`.
  - Return `steps[n]`.

<!-- - **Edge Cases Checked**:
  - -->

## Optimization

- **Time Complexity**: `O(N)`, looping once(and checking `uniqueWays(n-1)` and `uniqueWays(n-2)`) for every step up till step `n`.
- **Space Complexity**: `O(N)`, just space for the map.

## Alternative Solutions

- Only _slight_ optimization (mostly space complexity wise) you could make is that instead of using a HashMap, to store _Key-Value pairs_ for the unique number of ways to get to a certain step, you could you use a _fixed window_, keeping track of only `uniqueWays(n-1)` and `uniqueWays(n-2)` to calculate `uniqueWays(n)`. This would improve space complexity to `O(1)`.

## Key Takeaways

- First real **dynamic programming**(honestly, I didn't even realize my code fit the dynamic programming structure) rep for me.

  - Spot the recurrence + base cases, then decide tabulation (bottom-up) vs memoization (top-down). I went tabulation here.

- When a state splits into a couple smaller _subproblems_ that don’t overlap in order, try a recurrence and build up.

- If a recurrence only depends on a fixed window (here `n-1`/`n-2`), I should default to constant `O(1)` space.

- Recognizing patterns (Fibonacci here) can help a lot (checking base cases and expected growth).

- Early returns for tiny `n` (or in other words, base cases) keep loops simple and reduces potential for bugs.
