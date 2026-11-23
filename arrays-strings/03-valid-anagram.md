## Problem: Valid Anagram (Easy)

**Link:** https://leetcode.com/problems/valid-anagram/

### Approach

I used a frequency count with an array of 26 integers, one per letter. For each position I add 1 for the letter in s and subtract 1 for the letter in t, so if the strings are anagrams every count ends at 0. I check the lengths first, because strings of different lengths can never be anagrams.

### Complexity

- Time: O(n)
- Space: O(1), since the count array is always 26 integers

### Notes

The different-lengths case ("ab" and "a") was the edge case I tested, and the early length check handles it before the loop can read past the end of t. This solution assumes lowercase English letters only. If the input could contain Unicode or uppercase, I would use a hash map or a larger count array instead.