#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* LeetCode 14: Longest Common Prefix (Easy)
   Approach: vertical scanning. Compare the same column across all
   strings and stop at the first mismatch or the end of any string. */
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }
    int len = (int)strlen(strs[0]);
    int prefixLen = 0;
    for (int col = 0; col < len; col++) {
        char c = strs[0][col];
        for (int row = 1; row < strsSize; row++) {
            if (strs[row][col] == '\0' || strs[row][col] != c) {
                char* res = (char*)malloc(prefixLen + 1);
                strncpy(res, strs[0], prefixLen);
                res[prefixLen] = '\0';
                return res;
            }
        }
        prefixLen++;
    }
    char* res = (char*)malloc(prefixLen + 1);
    strncpy(res, strs[0], prefixLen);
    res[prefixLen] = '\0';
    return res;
}

/* Local test helper: prints PASS or FAIL */
void runTest(const char* name, char** strs, int n, const char* expected) {
    char* result = longestCommonPrefix(strs, n);
    if (strcmp(result, expected) == 0)
        printf("%s: PASS -> \"%s\"\n", name, result);
    else
        printf("%s: FAIL (got \"%s\")\n", name, result);
    free(result);
}

int main(void) {
    char* a[] = {"flower", "flow", "flight"};
    runTest("Test 1 (typical)", a, 3, "fl");

    char* b[] = {"dog", "racecar", "car"};
    runTest("Test 2 (edge: no common prefix)", b, 3, "");

    char* c[] = {"alone"};
    runTest("Test 3 (edge: single string)", c, 1, "alone");

    return 0;
}