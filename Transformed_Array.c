#include <stdlib.h>
int* constructTransformedArray(int* nums, int n, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    for(int i = 0; i < n; i++){
        if(nums[i] == 0){
            res[i] = 0;
            continue;
        }
        int steps = nums[i];
        int idx = (i + steps) % n;
        if(idx < 0) idx += n;
        res[i] = nums[idx];
    }
    return res;
}
