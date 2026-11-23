## Problem: Reverse String (Easy)

**Link:** https://leetcode.com/problems/reverse-string/

### Approach

I used the two-pointer technique: one pointer starts at the first character and the other at the last, and I swap them and move both pointers inward until they meet. This reverses the string in place without needing a second array.

### Complexity

- Time: O(n)
- Space: O(1)

### Notes

The single-character string was the edge case I tested: the pointers meet immediately, so nothing changes, which is correct. For odd lengths, the middle character stays where it is, and the loop condition left < right handles that without extra code.