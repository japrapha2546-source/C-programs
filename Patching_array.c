int minPatches(int* nums,int numsSize,int n){
    long miss=1;
    int i=0,patches=0;
    while(miss<=n){
        if(i<numsSize && nums[i]<=miss){
            miss+=nums[i];
            i++;
        }else{
            miss+=miss;
            patches++;
        }
    }
    return patches;
}
