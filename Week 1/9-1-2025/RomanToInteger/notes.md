# Problem 13. Roman to Integer - Notes
## Problem Understanding
- **Summary**: Given a String that contains a Roman Numeral, convert it to an integer.
- **Input**: A single String, that is the Roman Numeral.
- **Output**: An integer, roman numeral in base 10 system.

## Approach
- **Initial Thoughts**: 
    * We could just add integers as we go through the String but we would miss all of the special/'edge' cases(defined below). My solution to this would just be to check the number ahead of the current value, and see if it is greater than the current. If it is, then we know we have found a special case. 
    * Alternatively, we could just manage values in pairs as we iterate, but that seems slightly excessive given we can just do the simpler check that I mentioned in my solution above and edge cases can't overlap.

- **Approach Taken**: Start at beginning of String and progress through the numeral, adding current value UNLESS it is succeeded by a greater value(indicating an edge case, defined below).

## Challenges
- **Obstacles Faced**: Differentiating between edge cases and typical values.
- **Edge Cases**: letters like 4, 9, 40, 90, 400, and 900 require checking the character before/after(depending on implementation) the current character.

## Optimization
- **Time Complexity**: O(n), Looping through entire length of string(n) once
- **Space Complexity**: O(1), O(1) * 7 - immutable map containing mappings from roman numeral to base 10

## Alternative Solutions
- Iterate through String in pairs(slightly slower, unoptimized version of my solution in some sense).
    * Time complexity is O(n).
    * Space complexity is O(1).
- Iterate backwards(this is something that I didn't come up myself but it is faster than my best solution because we don't have to check for hitting the boundary, and checking for edge cases all happens without having to recheck the same index twice)
    * Time complexity is O(n).
    * Space complexity is O(1).

## Key Takeaways
- Sometimes you can avoid boundary checks by reversing iteration by storing previously seen values(removing the need to recheck indexes).

<!-- ## Additional Resources
- N/A -->