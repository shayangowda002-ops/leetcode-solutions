#include <stdio.h>
#include <stdlib.h>

/* LeetCode 1: Two Sum (Easy)
   Approach: brute force - check every pair (i, j). */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    *returnSize = 0;
    return result;
}

/* Local test helper: prints PASS or FAIL */
void runTest(const char* name, int* nums, int n, int target, int e0, int e1) {
    int size;
    int* r = twoSum(nums, n, target, &size);
    if (size == 2 && r[0] == e0 && r[1] == e1)
        printf("%s: PASS -> [%d, %d]\n", name, r[0], r[1]);
    else
        printf("%s: FAIL\n", name);
    free(r);
}

int main(void) {
    int a[] = {2, 7, 11, 15};
    runTest("Test 1 (typical)", a, 4, 9, 0, 1);

    int b[] = {3, 3};
    runTest("Test 2 (edge: duplicates)", b, 2, 6, 0, 1);

    int c[] = {3, 2, 4};
    runTest("Test 3 (answer not at start)", c, 3, 6, 1, 2);

    return 0;
}