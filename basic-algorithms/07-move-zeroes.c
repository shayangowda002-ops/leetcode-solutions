#include <stdio.h>

/* LeetCode 283: Move Zeroes (Easy)
   Approach: two pointers. 'write' marks where the next non-zero value
   goes; every non-zero element is swapped forward into that spot. */
void moveZeroes(int* nums, int numsSize) {
    int write = 0;
    for (int read = 0; read < numsSize; read++) {
        if (nums[read] != 0) {
            int tmp = nums[write];
            nums[write] = nums[read];
            nums[read] = tmp;
            write++;
        }
    }
}

/* Local test helper: runs the function, compares with expected array */
void runTest(const char* name, int* nums, int n, int* expected) {
    moveZeroes(nums, n);
    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] != expected[i]) ok = 0;
    }
    printf("%s: %s -> [", name, ok ? "PASS" : "FAIL");
    for (int i = 0; i < n; i++) {
        printf("%d%s", nums[i], i < n - 1 ? ", " : "");
    }
    printf("]\n");
}

int main(void) {
    int a[] = {0, 1, 0, 3, 12};
    int ea[] = {1, 3, 12, 0, 0};
    runTest("Test 1 (typical)", a, 5, ea);

    int b[] = {0};
    int eb[] = {0};
    runTest("Test 2 (edge: single zero)", b, 1, eb);

    int c[] = {1, 2, 3};
    int ec[] = {1, 2, 3};
    runTest("Test 3 (edge: no zeroes)", c, 3, ec);

    return 0;
}