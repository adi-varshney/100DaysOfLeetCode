## Problem Understanding
- **Summary**: Given an integer, check whether it is a palindrome(integer doesn't change when it's digits are reversed)
- **Input**: A single integer.
- **Output**: True if the integer is a palindrome, False otherwise(A boolean value).

## Approach
- **Initial Thoughts**: 
    * Normally I've seen this problem except the given is a string not an integer. In this case, we could either convert int to string(O(log(n)) in and of itself) or get individual digits using math(int division and mod(%) properties) and implement two pointers. 
    * Another thing to important note is that any negative number can't be a palindrome which eliminates a lot of test cases. 
    * Also, (even though I didn't figure this out until looking at the editorial) a palindrome integer can't end with 0 because an integer can't begin with 0 which also eliminates a lot of possibilities.

- **Approach Taken**: Use two pointer to compare pairs of letters starting at the outer most letters(on each end) moving inward till the middle(# of digits/2) is reached.

<!-- ## Challenges
- **Obstacles Faced**: 
- **Edge Cases**: None -->

## Optimization
- **Time Complexity**: O(n), O(n/2) where is n is # of digits
- **Space Complexity**: O(1)

## Alternative Solutions
- Splitting word into 2 halves, then check if halves are equal
    * Time complexity is O(n) - O(n) = O(n/2) = O(*length of integer(n)*)/2
    * Space complexity is O(1).

## Key Takeaways
- This one is mostly math(if we ideally don't want to convert to String), but a key note is that two pointer can be especially helpful if you need to check pairs of certain digits or strings.

<!-- ## Additional Resources
- N/A -->