## Problem: Valid Parentheses (Easy)

**Link:** https://leetcode.com/problems/valid-parentheses/

### Approach

I used a stack. Every opening bracket is pushed onto the stack, and every closing bracket must match the bracket on top of the stack, which I then pop. The string is valid only if no mismatch happens and the stack is empty at the end. A stack fits because the most recently opened bracket must always be the first one closed.

### Complexity

- Time: O(n)
- Space: O(n) for the stack in the worst case, such as a string of only opening brackets

### Notes

I tested three failing edge cases: wrong order ("(]"), a lone closing bracket (")"), and an unclosed opening bracket ("(("). The lone closing bracket needs the check that the stack is not empty before popping, and the unclosed case is only caught by the final check that the stack is empty. In C there is no built-in stack, so I used a char array with a top index and freed it on every return path.