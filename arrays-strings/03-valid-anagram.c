#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* LeetCode 242: Valid Anagram (Easy)
   Approach: count letter frequencies. Add 1 for each letter of s,
   subtract 1 for each letter of t; it is an anagram if all counts are 0. */
bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) return false;
    int count[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

/* Local test helper: prints PASS or FAIL */
void runTest(const char* name, char* s, char* t, bool expected) {
    bool result = isAnagram(s, t);
    if (result == expected)
        printf("%s: PASS -> %s\n", name, result ? "true" : "false");
    else
        printf("%s: FAIL\n", name);
}

int main(void) {
    runTest("Test 1 (typical: anagram)", "anagram", "nagaram", true);
    runTest("Test 2 (not an anagram)", "rat", "car", false);
    runTest("Test 3 (edge: different lengths)", "ab", "a", false);
    return 0;
}