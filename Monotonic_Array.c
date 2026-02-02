#include <stdbool.h>

bool isMonotonic(int* nums,int n){
    bool inc=true,dec=true;
    for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1])
          dec=false;
        if(nums[i]<nums[i-1]) 
          inc=false;
    }
    return inc||dec;
}
