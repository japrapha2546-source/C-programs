Example 1:
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
  
Example 2:
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

#include <stdlib.h>
typedef struct {
    int val;
    int row;
    int col;
} Node;
int cmp(const void* a,const void* b){
    Node* n1=(Node*)a;
    Node* n2=(Node*)b;
    return n1->val - n2->val;
}
int* smallestRange(int** nums,int numsSize,int* numsColSize,int* returnSize){
    int* idx=(int*)calloc(numsSize,sizeof(int));
    int maxVal=-100000, minVal;
    for(int i=0;i<numsSize;i++){
        if(nums[i][0]>maxVal) maxVal=nums[i][0];
    }
    int start=-100000, end=100000;
    while(1){
        minVal=100001;
        int minRow=-1;
        for(int i=0;i<numsSize;i++){
            if(idx[i]<numsColSize[i] && nums[i][idx[i]]<minVal){
                minVal=nums[i][idx[i]];
                minRow=i;
            }
        }
        if(minRow==-1) break;
        if(maxVal - minVal < end - start || (maxVal - minVal == end - start && minVal < start)){
            start=minVal;
            end=maxVal;
        }
        idx[minRow]++;
        if(idx[minRow]==numsColSize[minRow]) break;
        if(nums[minRow][idx[minRow]]>maxVal) maxVal=nums[minRow][idx[minRow]];
    }
    free(idx);
    int* res=(int*)malloc(sizeof(int)*2);
    res[0]=start;
    res[1]=end;
    *returnSize=2;
    return res;
}
