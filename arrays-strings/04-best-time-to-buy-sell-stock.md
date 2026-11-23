## Problem: Best Time to Buy and Sell Stock (Easy)

**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Approach

I used a single pass through the prices. I keep track of the lowest price seen so far, and for each day I check what the profit would be if I sold on that day. The largest of those profits is the answer. This works because the best day to buy for any selling day is the cheapest day before it.

### Complexity

- Time: O(n)
- Space: O(1)

### Notes

The prices-only-fall case ([7, 6, 4, 3, 1]) was the edge case I tested. No sale makes a profit there, so the answer stays 0, which is why best starts at 0 and not at a negative number. A brute force that checks every pair of days would work too, but it takes O(n^2) time, which is too slow for large inputs.