## Problem Understanding
- **Summary**: Given a list of Strings(words), find the longest common sequence of letters at the beginning of each word(I'll refer to it longest common prefix as LCP from now on). 
- **Input**: A list of Strings(words).
- **Output**: A String, the shortest prefix shared by all words(return "" if none).

## Approach
- **Initial Thoughts**: 
    * My first thought is that I could find the LCP of two words, then I can keep a running LCP and use a loop to check the LCP(currLCP, next word word) and do that till the end of the list.
    * Alternatively, another thought that came to mind was going through the each letter of every single letter all at once and store the LCP till at least one word doesn't have the same prefix as others.
    * Going back to my first approach, I think sorting the list by increasing length or words might help make that process faster(although im not sure about this) - nvm, it actually does NOT make it faster, in fact it makes it slower :/
    * Another thought is since there will be a certain index that will be the difference between the valid LCP and an invalid LCP, this indicates a monotonic condition. This means that I may be able to implement binary search to more efficiently search for the LCP given that the current one doesn't satisfy all words.

- **Approach Taken**: Keep a running prefix, and for each next word, compute LCP(currLCP, word) using binary search on the prefix length with a helper prefixMatches(a, b, len) that compares characters directly(as opposed to using String.substring() which allocates more memory).

<!-- ## Challenges
- **Obstacles Faced**: 
- **Edge Cases**:  -->

## Optimization
- **Time Complexity**: O(N*M), where N = number of Strings/words, M = length of the shortest string. Each LCP(a, b) call compares O(M) character, and we do this N times comparing each and every word in the given array. 
- **Space Complexity**: O(1), only a few pointers/indices; no extra data structures.

## Alternative Solutions
- Checking each index for every single word(checking each column), before checking next column/index(essentially a vertical scan).
    * Time complexity is O(N*M).
    * Space complexity is O(1).
- For two words, check characters from beginning until mismatch is found; keep shrinking the running prefix(pairwise horizontal scan).
    * Time complexity is O(N*M).
    * Space complexity is O(1).

## Key Takeaways
- This is my first example of a non-integer binary search use case. In this case, the monotonic function is based upon the premise of a valid/invalid prefix shared by 2 words.

<!-- ## Additional Resources
- N/A -->