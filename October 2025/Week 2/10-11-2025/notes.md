<!-- Problem 219. Contains Duplicate II - Notes -->

# Problem 219. Contains Duplicate II - Notes

## Problem Understanding
- **Summary:** Check whether there exist two indices `i` and `j` with `nums[i] == nums[j]` and `|i - j| <= k`
- **Input:** Integer array `nums`, integer `k`
- **Output:** `true` if such a pair exists and `false` otherwise

## Approach
### Initial Thoughts
- Maintain a sliding window of the last `k` elements to enforce the distance rule implicitly
- Use a hash set to test membership in average `O(1)` time
- Handle trivial cases where no valid pair can exist or where only adjacency matters

### Approach Taken
- Return `false` when `nums.size() == 1` since no pair exists
- Return `false` when `k == 0` since distance cannot be at least one
- When `k == 1` scan once and check adjacent equality for an early and simple pass
- Otherwise iterate with an `unordered_set<int> window` that stores at most `k` recent values
- If `nums[i]` is already in `window` return `true` because a previous equal value lies within distance `k`
- Insert `nums[i]` into `window` and erase `nums[i - k]` once the window grows beyond size `k`

### Complexity:
- **Time:** `O(n)`
- **Space:** `O(min(n, k))`

## Challenges

### Edge Cases
- `k == 0` yields `false`
- `nums.size() == 1` yields `false`
- `k >= nums.size()` reduces to checking if any duplicate exists which the window set naturally handles
- Negative and large values are fine because hashing supports all integers

## Optimization
- The sliding window approach already subsumes the `k == 1` case so the special branch can be removed without changing complexity
- An `unordered_map<int, int>` storing the last seen index can reduce stored items when many values repeat while still checking distance on the fly

## Alternative Solutions
- Use `unordered_map<int, int>` from value to most recent index and for each `i` check if the value was seen and `i - last_index <= k` then update the index
- Sorting by value then scanning is not suitable because original indices are needed to compute distances

## Key Takeaways
- Sliding window plus a set is a clean pattern for constraints of the form `|i - j| <= k`
- Capping the window size at `k` enforces the distance limit without explicit difference checks
- Early exits for `k == 0` and length `1` clarify intent while the main loop remains linear
