Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
  
Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            int temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1)
         return i + 1;
    }
    return numsSize + 1;
}
