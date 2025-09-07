## Problem Understanding
* **Summary**: Given two *Strings* `needle` and `haystack`, return the index of the **first** occurrence of `needle` in `haystack`, or `-1` if it does not occur.
* **Input**: Two strings, `needle` and `haystack`.
* **Output**: An *integer* — the starting index of the first match (or `-1` if no match).

## Approach
* **Initial Thoughts**:
  * In Java this is straightforward because `String#indexOf(String)` already implements an efficient substring search.
  * If the language did not provide this, the safe linear-time approach is **KMP** (Knuth–Morris–Pratt). Other options include Boyer–Moore/Horspool or the Two-Way algorithm.

* **Approach Taken**:
  * Use `haystack.indexOf(needle)`.
  * This returns the first starting index of `needle` or `-1` if absent.
  * No manual loops or extra memory are needed.

* **Edge Cases Checked**:
  * `needle` longer than `haystack` → `-1`.
  * `needle` equals `haystack` → `0`.
  * Repeated/overlapping patterns (e.g., `haystack="aaaaa", needle="aaa"`) → still returns the first valid start (`0`).
  * (If empty `needle` were allowed, Java would return `0`, but this problem’s constraints keep lengths ≥ 1.)

## Optimization
 - **Time Complexity**: `O(N*M)`, where N = length of needle and M = length of haystack.
 - **Space Complexity**: `O(1)`, the brute force solution doesn't require any data structures.

## Alternative Solutions
* **KMP (Knuth–Morris–Pratt)**: Build an LPS/π table for `needle` and scan once → `O(H + N)` time, `O(N)` space.
* **Boyer–Moore / Horspool**: Often faster in practice on large alphabets; typical `O(H / skip)` average, with preprocessing tables.

## Key Takeaways
* Prefer standard library methods when available and well-optimized (`indexOf` in Java).
* Know **KMP** conceptually for interviews/other languages: preprocess `needle` to avoid rechecking characters, achieving linear time.
* Always consider edge cases: length comparisons, identical strings, and overlapping patterns.
