int pivotIndex(int* nums, int numsSize) {
    int s=0,l=0;
    for(int i=0;i<numsSize;i++){
        s+=nums[i];
    }
    for(int i=0;i<numsSize;i++){
        int r=s-l-nums[i];

        if(r==l)
          return i;
        l+=nums[i];
    }
    return -1;
}