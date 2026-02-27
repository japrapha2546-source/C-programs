Example 1:
Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements)

int compare(const void *a,const void *b){
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums,int numsSize){
    qsort(nums,numsSize,sizeof(int),compare);
    int sum=0;
    for(int i=0;i<numsSize;i+=2)
        sum+=nums[i];
    return sum;
}
