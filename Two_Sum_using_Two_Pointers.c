Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

int* twoSum(int* numbers,int numbersSize,int target,int* returnSize){
    int* res=(int*)malloc(2*sizeof(int));
    *returnSize=2;
    int l=0,r=numbersSize-1;
    while(l<r){
        int sum=numbers[l]+numbers[r];
        if(sum==target){
            res[0]=l+1;
            res[1]=r+1;
            return res;
        } else if(sum<target) 
           l++;
        else 
           r--;
    }
    return NULL;
}
