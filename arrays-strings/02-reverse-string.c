#include <stdio.h>
#include <string.h>

/* LeetCode 344: Reverse String (Easy)
   Approach: two pointers swapping from both ends, in place. */
void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;
    while (left < right) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}

/* Local test helper: prints PASS or FAIL */
void runTest(const char* name, const char* input, const char* expected) {
    char buf[100];
    strcpy(buf, input);
    reverseString(buf, (int)strlen(buf));
    if (strcmp(buf, expected) == 0)
        printf("%s: PASS -> \"%s\"\n", name, buf);
    else
        printf("%s: FAIL (got \"%s\")\n", name, buf);
}

int main(void) {
    runTest("Test 1 (typical)", "hello", "olleh");
    runTest("Test 2 (edge: single char)", "A", "A");
    runTest("Test 3 (even length)", "Hannah", "hannaH");
    return 0;
}