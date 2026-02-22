int* runningSum(int* nums,int numsSize,int* returnSize){
    int *arr=(int*)malloc(sizeof(int)*numsSize);
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        arr[i]=sum;
    }
    *returnSize=numsSize;
    return arr;
}