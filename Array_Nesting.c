int arrayNesting(int* nums,int n){
    int maxlen=0;
    for(int i=0;i<n;i++){
        int start=i,count=0;
        while(nums[start]!=-1){
            int next=nums[start];
            nums[start]=-1;
            start=next;
            count++;
        }
        if(count>maxlen) maxlen=count;
    }
    return maxlen;
}
