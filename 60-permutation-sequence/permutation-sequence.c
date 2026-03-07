char* getPermutation(int n,int k){
    int factorial[10]={1};
    for(int i=1;i<=n;i++)
        factorial[i]=factorial[i-1]*i;

    int* nums=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        nums[i]=i+1;

    k--;
    char* result=(char*)malloc((n+1)*sizeof(char));
    int pos=0;

    for(int i=n;i>=1;i--){
        int index=k/factorial[i-1];
        result[pos++]=nums[index]+'0';

        for(int j=index;j<i-1;j++)
            nums[j]=nums[j+1];

        k%=factorial[i-1];
    }

    result[pos]='\0';
    free(nums);
    return result;
}