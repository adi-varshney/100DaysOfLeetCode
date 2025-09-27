# Problem 119. Pascal's Triangle II - Notes

## Problem Understanding
- **Summary:** Return the **rowIndex**-th row of Pascal’s triangle using 0 indexing
- **Input:** An _int_ `rowIndex` which is the row to generate
- **Output:** A _vector\<int\>_ containing that row’s values from left to right

## Approach
### Initial Thoughts
- I only need one row not the whole triangle
- Every inner value equals sum of two numbers above it
- Building rows one by one in place works if I do not overwrite numbers I still need
- Update from left to right would destroy needed values so I should carry the previous left neighbor in a temp
- Each new row ends and begins with 1

### Approach Taken
- Keep a single array `row` initialized to `[1]`
- For each next row index `i` from 1 to `rowIndex`
  - Track a `prev` variable that represents the value from the previous row at position `j-1`
  - Loop `j` from 1 to `row.size()-1`
    - Save `curr = row[j]`
    - Set `row[j] = row[j] + prev`
    - Update `prev = curr`
  - Push back 1 at the end
- This updates in place using O(k) extra memory where k equals row length

### Complexity:
- **Time:** O(k^2) where k equals `rowIndex` because total updates across rows sum to 1+2+…+k
- **Space:** O(k) for the target row stored and O(1) extra aside from the output

<!-- ## Challenges
### Obstacles Faced
- placeholder
### Edge Cases
- placeholder
-->

## Alternative Solutions
- **Zero-padding trick**
  - Compute next row as elementwise sum of `[0]+row` and `row+[0]`
  - Simple to reason about and avoids manual carry
  - **Time:** O(k^2), but still slower than my solution due to extra per-row copying
  - **Space:** O(k)
- **Direct combinatorics**
  - Use `C(n,0)=1` and `C(n,r+1)=C(n,r) * (n−r)/(r+1)` to fill the row by multiplicative update with integers
  - Avoids building intermediate rows and is numerically safe within constraints
  - **Time:** O(k)
  - **Space:** O(k)

## Key Takeaways
- In-place row building works because each inner cell only depends on two neighbors from the previous state
- Direction of updates matters to preserve needed values
- The multiplicative binomial method is fastest for a single row while in-place DP is straightforward and passes constraints
