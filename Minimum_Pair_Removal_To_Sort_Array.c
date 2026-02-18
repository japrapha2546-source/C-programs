Example 1:
Input: nums = [5,2,3,1]
Output: 2
  
Explanation:
The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Example 2:
Input: nums = [1,2,2]
Output: 0

Explanation:
The array nums is already sorted.

#include <stdlib.h>
int isNonDecreasing(int* nums, int size) {
    for (int i = 1; i < size; i++) {
        if (nums[i] < nums[i - 1])
            return 0;
    }
    return 1;
}
int minimumPairRemoval(int* nums, int numsSize) {
    int operations = 0;
    while (!isNonDecreasing(nums, numsSize)) {
        int minSum = nums[0] + nums[1];
        int idx = 0;
        for (int i = 1; i < numsSize - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (sum < minSum) {
                minSum = sum;
                idx = i;
            }
        }
        nums[idx] = nums[idx] + nums[idx + 1];
        for (int i = idx + 1; i < numsSize - 1; i++) {
            nums[i] = nums[i + 1];
        }
        numsSize--;
        operations++;
    }
    return operations;
}
