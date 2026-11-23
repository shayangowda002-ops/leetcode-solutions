## Problem: Binary Search (Easy)

**Link:** https://leetcode.com/problems/binary-search/

### Approach

I used the standard binary search on the sorted array: I keep a left and a right boundary, check the middle element, and throw away the half that cannot contain the target. If the middle element equals the target I return its index, and if the boundaries cross I return -1. This is much faster than scanning every element, because each step halves the search range.

### Complexity

- Time: O(log n)
- Space: O(1)

### Notes

The target-missing case (searching for 2 in the sorted array) was the edge case I tested, and it correctly returns -1. I calculate the middle as left + (right - left) / 2 and not (left + right) / 2, because the second form can overflow when both values are large. The loop condition left <= right is important so that a single-element array still gets checked.