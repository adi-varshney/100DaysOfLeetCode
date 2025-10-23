# Problem 6. Zigzag Conversion - Notes

## Problem Understanding

- **Summary:** Convert string `s` by writing it in a zigzag across `numRows`, then read row by row to form the result.
- **Input:** `s` as a string, `numRows` as an integer.
- **Output:** The zigzag-read string.
- **Observations:** Movement alternates down then up-diagonal. A full cycle length is `2*(numRows-1)`.

## Approach

### Initial Thoughts

- I think simulating rows is most straightforward.
- I realize direction flips only at row `0` and row `numRows-1`.
- I’m considering per-row buffers to keep appends cheap and the final join linear.
- I think guarding `numRows == 1` or `numRows >= |s|` avoids edge headaches.

### Approach Taken

- Maintain `row` and a direction flag.
- For each character, place into `rows[row]`, flip direction at the edges, then move the row pointer.
- Implementation variants match my code:
  - **Solution 1:** `vector<vector<char>>` for per-row chars, then concatenate.
  - **Solution 2 (best):** `vector<string>` for per-row strings, then join directly.

### Complexity:

- **Time:** `O(n)` where `n = |s|`.
- **Space:** `O(n)` for row buffers.

## Challenges

- **Obstacles Faced**
  - Updating `row` before placing led to out-of-bounds on top or bottom edges.
  - Flipping direction after moving caused skipped rows and mis-ordering.
  - Accidentally pushing pointers into `vector<vector<char>>` instead of objects.
- **Edge Cases**
  - `numRows == 1` no conversion needed.
  - `numRows >= |s|` each char stays on its own row.
  - Very short strings behave like identity.

## Optimization

- Prefer `vector<string>` over `vector<vector<char>>` to avoid inner loops when joining.
- Reserve capacity for the answer with `ans.reserve(s.size())`.
- Initialize rows with size: `vector<string> rows(numRows)` to skip push-backs for rows.
- Use an integer direction `dir` set to `+1` or `-1` to simplify flag logic.

## Alternative Solutions

- **Cycle-index method**
  - Use `cycle = 2*(numRows-1)` and pick indices row by row.
  - For middle rows also read the diagonal index `i + cycle - 2*row` when in range.
  - Eliminates state, same `O(n)` time and `O(1)` extra beyond the output.
- **Math plus append**
  - Precompute positions per row using arithmetic and append directly to the answer without intermediate row buffers.

## Key Takeaways

- Place then decide direction then move to avoid off-by-one bugs.
- Flip only at rows `0` and `numRows-1`.
- Early-return for trivial row counts keeps logic clean.
- Per-row strings plus one final join make the code simple and fast.
