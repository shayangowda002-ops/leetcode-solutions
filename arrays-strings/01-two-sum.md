## Problem: Two Sum (Easy)

**Link:** https://leetcode.com/problems/two-sum/

### Approach

I used brute force: for every element at index i, I check each later element at index j to see if the two add up to the target. As soon as a pair matches, I return both indices. This is simple and correct, and it works for duplicates because j always starts after i.

### Complexity

- Time: O(n^2)
- Space: O(1) extra space (only the 2-element result array)

### Notes

The duplicates case ([3, 3] with target 6) was the edge case I tested, and it works because the same element is never used twice. A cleaner approach for next time is a hash map, storing each number's index and looking up (target - current) in one pass, which brings the time down to O(n).