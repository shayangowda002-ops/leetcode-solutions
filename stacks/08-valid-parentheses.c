#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/* LeetCode 20: Valid Parentheses (Easy)
   Approach: use a stack. Push every opening bracket; on a closing
   bracket, the top of the stack must be its matching opening bracket. */
bool isValid(char* s) {
    int n = (int)strlen(s);
    char* stack = (char*)malloc(n + 1);
    int top = -1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top < 0) { free(stack); return false; }
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }
    bool valid = (top == -1);
    free(stack);
    return valid;
}

/* Local test helper: prints PASS or FAIL */
void runTest(const char* name, char* s, bool expected) {
    bool result = isValid(s);
    if (result == expected)
        printf("%s: PASS -> %s\n", name, result ? "true" : "false");
    else
        printf("%s: FAIL\n", name);
}

int main(void) {
    runTest("Test 1 (typical: valid mix)", "()[]{}", true);
    runTest("Test 2 (edge: wrong order)", "(]", false);
    runTest("Test 3 (edge: only a closing bracket)", ")", false);
    runTest("Test 4 (edge: unclosed opening bracket)", "((", false);
    return 0;
}