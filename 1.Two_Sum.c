int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
     for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                int* k=(int*)malloc(2*sizeof(int));
                k[0]=i;
                k[1]=j;
                *returnSize=2;
                return k;
            }
        }
     } 
    *returnSize=0;
    return NULL;
}
