Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* count = calloc(numsSize + 1, sizeof(int));
    int* result = malloc(2 * sizeof(int));

    int dup = 0, missing = 0;

    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    for (int i = 1; i <= numsSize; i++) {
        if (count[i] == 2) {
            dup = i;
        } else if (count[i] == 0) {
            missing = i;
        }
    }

    result[0] = dup;
    result[1] = missing;

    *returnSize = 2;
    free(count);
    return result;
}
