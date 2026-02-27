Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
  
Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

int pivotIndex(int* nums, int numsSize) {
    int s=0;
    for(int i=0;i<numsSize;i++){
        s+=nums[i];
    }
    int left=0;
    for(int i=0;i<numsSize;i++){
        if(left== s-left-nums[i])
            return i;
        left+=nums[i];
        }
        return -1;
}
