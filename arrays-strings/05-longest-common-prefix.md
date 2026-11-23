## Problem: Longest Common Prefix (Easy)

**Link:** https://leetcode.com/problems/longest-common-prefix/

### Approach

I used vertical scanning: I take the first string as the reference and compare each of its characters, column by column, against the same position in every other string. As soon as one string ends or a character differs, I stop and copy the prefix found so far into a new string. This avoids building and re-checking many partial prefixes.

### Complexity

- Time: O(S), where S is the total number of characters across all strings
- Space: O(1) extra, apart from the result string that is returned

### Notes

The no-common-prefix case (["dog", "racecar", "car"]) was the edge case I tested, and it correctly returns an empty string. The check for the end of a string ('\0') before comparing characters matters because it stops the loop from reading past a shorter string. In C the returned string must be allocated with malloc, since a local array would be gone once the function returns.