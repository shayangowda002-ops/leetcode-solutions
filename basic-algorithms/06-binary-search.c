#include <stdio.h>

/* LeetCode 704: Binary Search (Easy)
   Approach: repeatedly halve the sorted array. Compare the middle
   element with the target and discard the half that cannot contain it. */
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

/* Local test helper: prints PASS or FAIL */
void runTest(const char* name, int* nums, int n, int target, int expected) {
    int result = search(nums, n, target);
    if (result == expected)
        printf("%s: PASS -> %d\n", name, result);
    else
        printf("%s: FAIL (got %d, expected %d)\n", name, result, expected);
}

int main(void) {
    int a[] = {-1, 0, 3, 5, 9, 12};
    runTest("Test 1 (typical: target found)", a, 6, 9, 4);
    runTest("Test 2 (edge: target missing)", a, 6, 2, -1);

    int b[] = {5};
    runTest("Test 3 (edge: single element)", b, 1, 5, 0);

    return 0;
}