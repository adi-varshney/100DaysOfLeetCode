<!-- Problem 118. Pascal's Triangle notes -->

# Problem 118. Pascal's Triangle notes

## Problem Understanding
- **Summary:** Return the first **numRows** of Pascal’s triangle
- **Input:** An _int_ `numRows`, between 1…30, the number of rows to generate
- **Output:** A _vector\<vector\<int\>\>_ list of lists where each inner list is a row from 1 to `numRows`

## Approach

### Initial Thoughts
- Recognized the rule borders are `1` and each interior value equals the sum of the two above it
- Easiest plan build each row left to right using the previous row
- Be careful with off by one when indexing the previous row
- Handle tiny cases `numRows == 1` and `numRows == 2`
- Plan start with `[1]` then for each next row push `1` add adjacent pairs from the previous row end with `1`

### Approach Taken
- Initialize triangle `t` with `[1]` and return early when `numRows == 1`
- For each size `i` from `2` to `numRows` create the next row with `createRow(t, i)`
- Begin each row with `1`
- Let `prev = t[i-2]` then for `j` from `0` to `prev.size() - 2` push `prev[j] + prev[j+1]`
- End each row with `1`
- Append the row to `t` and return `t` after the loop

### Complexity:
- **Time:** O(n^2) where `n = numRows` total elements approximately `n(n+1)/2`
- **Space:** O(n^2) for the returned triangle

<!-- ## Challenges
if none, then comment out the entire challenges section whwich includes obstacles faced and edge cases(so use \<!-- --\>)
### Obstacles Faced
- if none, then leave commented out(so use \<!-- --\>)

### Edge Cases
-if none, then leave commented out(so use \<!-- --\>) -->

## Alternative Solutions
1) **In place growing single row update from back**
    - Keep one vector `row` starting as `[1]` and grow it each level
    - Do `row.push_back(1)` then for `j` from `row.size() - 2` down to `1` set `row[j] += row[j-1]`
    - Push a copy of `row` into the result each level
    - **Time:** O(n^2)
    - **Space:** O(n) extra beyond the output

2) **Binomial coefficient formula per row**
    - For row `r` zero indexed compute entries iteratively
    - Start `c = 1` then for `k` from `0` to `r` push `c` and update `c = c * (r - k) / (k + 1)` using integer math
    - **Time:** O(n^2)
    - **Space:** O(1) extra per row or O(n) if you keep a temp row

3) **Zero padding trick**
    - Let `prev` be the last row create `left = [0] + prev` and `right = prev + [0]`
    - New row equals elementwise `left[i] + right[i]`
    - **Time:** O(n^2)
    - **Space:** O(n) extra for the padded copies

## Key Takeaways
- Borders are always `1` and interior equals the sum of the two above
- Building rows from the previous row is simple and matches the definition
- Common errors/issues include off by one indices and tiny `numRows` cases
- Multiple O(n^2) solutions exist and the back update variant uses only O(n) extra space
