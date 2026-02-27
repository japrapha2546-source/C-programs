Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for(int i=0;i<numsSize;i++){
        int index=abs(nums[i])-1;
        if(nums[index]>0)
          nums[index]=-nums[index];
    }
    int* res=(int*)malloc(numsSize*sizeof(int));
    int c=0;
    for(int i=0;i<numsSize;i++){
      if(nums[i]>0)
        res[c++]=i+1;
    }
*returnSize=c;
return res;
}
