## Problem: Move Zeroes (Easy)

**Link:** https://leetcode.com/problems/move-zeroes/

### Approach

I used two pointers: a read pointer that scans the whole array, and a write pointer that marks where the next non-zero value should go. Every time the read pointer finds a non-zero element, I swap it into the write position and move the write pointer forward. This keeps the non-zero elements in their original order and pushes all the zeroes to the end, in place.

### Complexity

- Time: O(n)
- Space: O(1)

### Notes

The single-zero array ([0]) and the array with no zeroes ([1, 2, 3]) were the edge cases I tested. In the second case the swap just swaps each element with itself, which is harmless. A cleaner version could skip the swap when read equals write, to avoid unnecessary writes. The problem is a good reminder that moving things in place usually needs two pointers.