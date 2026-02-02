bool checkPossibility(int* nums, int n){
    int count = 0;
    for(int i = 0; i < n - 1; i++){
        if(nums[i] > nums[i + 1]){
            if(++count > 1)
             return false;
            if(i == 0 || nums[i - 1] <= nums[i + 1]) 
             nums[i] = nums[i + 1];
            else
             nums[i + 1] = nums[i];
        }
    }
    return true;
}
