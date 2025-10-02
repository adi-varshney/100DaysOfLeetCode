# Problem 125. Valid Palindrome - Notes

## Problem Understanding
- **Summary:** Determine if a string reads the same forward and backward after converting to lowercase and removing all non-alphanumeric(non-letter/non-digit values, i.e. ':' and other symbols) characters
- **Input:** A _string_ `s` of printable ASCII characters with length 1…2e5
- **Output:** A _bool_ `true` if `s` is a palindrome under the rules and `false` otherwise
- **Key details:** Only letters and digits count toward the palindrome check

## Approach

### Initial Thoughts
- This problem seems like a simple two pointers problem(or you could create a recursive method?). 
- Creating pointers on both ends will let us compare matching characters while skipping anything that is not a letter or digit
- Lowercasing comparisons prevents case from affecting equality
- We should aim for one pass with constant extra space due to large input sizes
- Using standard library helpers like `std::isalnum` and `std::tolower` improves clarity though we must cast to `unsigned char` for safety(C++)

### Approach Taken
- Maintain `leftPtr` at start and `rightPtr` at end
- While `leftPtr < rightPtr`
  - Convert `s[leftPtr]` and `s[rightPtr]` to lowercase
  - If `left` is not alphanumeric then advance `leftPtr`
  - Else if `right` is not alphanumeric then decrement `rightPtr`
  - Else compare characters and return `false` on mismatch then move both pointers inward
- Return `true` after the loop if no mismatches were found
- Notes on robustness
  - `std::tolower` and `std::isalnum` should be called with `unsigned char` casts to avoid undefined behavior on platforms where `char` is signed
  - Calling `tolower` only after confirming the character is alphabetic is a small micro improvement though not required for correctness here due to ASCII constraint

### Complexity:
- **Time:** O(n) single pass over the string
- **Space:** O(1) extra space

<!-- ## Challenges
### Obstacles Faced
- 
### Edge Cases
-  -->

## Alternative Solutions
- **Clean then check**
  - Build a filtered lowercase string with only alphanumeric characters then check palindrome with two pointers
  - **Time:** O(n)
  - **Space:** O(n) for the filtered copy
- **Use `std::isalnum` and pointer skipping helper**
  - Write a small helper that advances a pointer to the next alphanumeric then compare lowercase values
  - Improves readability while keeping logic identical to two pointers
  - **Time:** O(n)
  - **Space:** O(1)
- **Regex or remove_if cleanup**
  - Use `std::remove_if` to erase non-alphanumerics then `std::transform` to lowercase and compare
  - **Time:** O(n)
  - **Space:** O(1) if done in place on the string though still touches all characters

## Key Takeaways
- Filtering on the fly with two pointers yields optimal O(n) time and O(1) space
- Cast to `unsigned char` when using ctype functions to avoid undefined behavior
- Early exits on mismatch keep runtime tight in non-palindrome cases
