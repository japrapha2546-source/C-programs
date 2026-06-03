#include <stdio.h>

int linearSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
    int n,target;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&target);

    int result=linearSearch(arr,n,target);

    if(result!=-1)
        printf("%d",result);
    else
        printf("-1");

    return 0;
}

