#include <stdio.h>

/* LeetCode 121: Best Time to Buy and Sell Stock (Easy)
   Approach: one pass. Track the lowest price seen so far and the
   best profit if we sold today. */
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int minPrice = prices[0];
    int best = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > best) {
            best = prices[i] - minPrice;
        }
    }
    return best;
}

/* Local test helper: prints PASS or FAIL */
void runTest(const char* name, int* prices, int n, int expected) {
    int result = maxProfit(prices, n);
    if (result == expected)
        printf("%s: PASS -> %d\n", name, result);
    else
        printf("%s: FAIL (got %d, expected %d)\n", name, result, expected);
}

int main(void) {
    int a[] = {7, 1, 5, 3, 6, 4};
    runTest("Test 1 (typical)", a, 6, 5);

    int b[] = {7, 6, 4, 3, 1};
    runTest("Test 2 (edge: prices only fall)", b, 5, 0);

    int c[] = {5};
    runTest("Test 3 (edge: single day)", c, 1, 0);

    return 0;
}