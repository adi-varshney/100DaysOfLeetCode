<!-- Problem 20. Valid Parenthesis notes -->
## Problem Understanding
 - **Summary**: Given a string `s` containing only the characters `(`,`)`,`[`,`]`,`{`,`}`, determine whether it’s valid. A string is valid if every opening bracket is closed by the same type of bracket and in the correct order.
 - **Input**: A Strings(containing series of `(`,`)`,`[`,`]`,`{`,`}`).
 - **Output**: A boolean, `true` if the String is valid, else `false`.

## Approach
- **Initial Thoughts**:

  * I have seen this problem before and that the best solution would be to use a **LIFO** structure(_Stack_ most likely) to track openings. When a closing bracket appears, it must match the most recent unmatched opening, otherwise the string is invalid.

 - **Approach Taken**: In this scenario, I think its best to iterate over the String `s`, and push all the opening braces, `(`, `{`, and `[`, to stack. When we meet a closing brace, `)`, `}`, or `]`, we check if the last open brace was the same type. If so, then we pop the open brace off the stack and continue, but if not, then we return `false` immediately. Also created a helper function to determine if we find mismatched delimiters(_edit: turns out according to LeetCode, this uses more memory although I'm not sure how accurate that is_). If we reach the end of the string and the stack still contains some opening braces, then we know we must be missing appropriate delimiters and that the given String is invalid, thus we return `false`. Otherwise, if the stack is empty we return `true`.

## Challenges
 - **Obstacles Faced**: Didn't consider the possibility that the stack could be empty mid loop during calculation. It was a small issue, and quickly resolved with one if statement.
 - **Edge Cases**: Empty stack when checking for pairs. For example the following test case is where an issue arose: `')('`

## Optimization
 - **Time Complexity**: O(N), where N = number of characters in the given String because we simply iterate through the entire string once.
 - **Space Complexity**: O(N), since we create a stack keeping track of opening delimiters.

<!-- ## Alternative Solutions
- None that come to mind. -->

## Key Takeaways
 - This is a classic stack problem: It's also my first actual implementation/use case of a stack in a problem, although I have seen such problems before.
 - Additionally this was my _first time_ programming in C++ so had to navigate extra memory usage by using aliases.
    * In C++, references (`&`) avoid copies; `const` documents “read-only.”

<!-- ## Additional Resources
- N/A -->
