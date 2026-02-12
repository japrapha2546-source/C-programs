Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000

double findMaxAverage(int* nums, int numsSize, int k) {
    double sum=0.0;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    double max=sum;
    for(int i=k;i<numsSize;i++){
        sum=sum-nums[i-k]+nums[i];
        if(sum>max)
           max=sum;
    }
    double t=max/k;
    return t;
}
