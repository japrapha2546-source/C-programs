#include <stdlib.h>

int findMaxLength(int* nums,int numsSize){
    int n=numsSize;
    int *map=(int*)malloc(sizeof(int)*(2*n+1));
    for(int i=0;i<2*n+1;i++) map[i]=-2;
    map[n]=-1; 
    int maxlen=0,sum=0;
    for(int i=0;i<n;i++){
        sum += (nums[i]==0?-1:1);
        if(map[sum+n]!=-2){
            int len=i-map[sum+n];
            if(len>maxlen) 
               maxlen=len;
            }else{
              map[sum+n]=i;
        }
    }
    free(map);
    return maxlen;
}
