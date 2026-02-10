Example 1:

Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
Example 2:

Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).

int wiggleMaxLength(int* nums,int numsSize){
    if(numsSize<2) return numsSize;

    int prevDiff=nums[1]-nums[0];
    int count=prevDiff!=0?2:1;

    for(int i=2;i<numsSize;i++){
        int diff=nums[i]-nums[i-1];
        if((diff>0 && prevDiff<=0) || (diff<0 && prevDiff>=0)){
            count++;
            prevDiff=diff;
        }
    }
    return count;
}
