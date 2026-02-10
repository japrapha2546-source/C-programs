Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
  
Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

void sortColors(int* nums, int numsSize) {
    int low=0,mid=0,high=numsSize-1;
    while(mid<=high){
        if(nums[mid]==0){
            int t=nums[low];
            nums[low]=nums[mid];
            nums[mid]=t;
            low++;
            mid++;
        }
        else if(nums[mid]==1)
            mid++;
        else{
            int t=nums[mid];
            nums[mid]=nums[high];
            nums[high]=t;
            high--;
        }
    }
}
