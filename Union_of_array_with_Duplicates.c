#include <stdlib.h>

int* findUnion(int* a, int n, int* b, int m, int* returnSize) {

    int freq[100001] = {0}, *res, k = 0;

    for (int i = 0; i < n; i++) 
       freq[a[i]] = 1;
    for (int i = 0; i < m; i++) 
       freq[b[i]] = 1;

    for (int i = 0; i <= 100000; i++){
        if (freq[i]) 
           k++;
    }
    res = (int*)malloc(k * sizeof(int));
    *returnSize = k;  
    k = 0;

    for (int i = 0; i <= 100000; i++){
        if (freq[i]) 
          res[k++] = i;
    }
    return res;
}
