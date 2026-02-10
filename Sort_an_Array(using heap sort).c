Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), 
while the positions of other numbers are changed (for example, 1 and 5).

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.

#include <stdlib.h>

void heapify(int*nums,int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && nums[l]>nums[largest]) largest=l;
    if(r<n && nums[r]>nums[largest]) largest=r;

    if(largest!=i){
        int t=nums[i];
        nums[i]=nums[largest];
        nums[largest]=t;
        heapify(nums,n,largest);
    }
}

int* sortArray(int*nums,int numsSize,int*returnSize){
    for(int i=numsSize/2-1;i>=0;i--) heapify(nums,numsSize,i);

    for(int i=numsSize-1;i>=0;i--){
        int t=nums[0];
        nums[0]=nums[i];
        nums[i]=t;
        heapify(nums,i,0);
    }

    *returnSize=numsSize;
    return nums;
}
