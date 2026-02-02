#include <stdlib.h>
int* beautifulArrayHelper(int n, int* returnSize) {
    if (n == 1) {
        int* arr = (int*)malloc(sizeof(int));
        arr[0] = 1;
        *returnSize = 1;
        return arr;
    }
    int leftSize, rightSize;
    int* left = beautifulArrayHelper((n + 1) / 2, &leftSize);
    int* right = beautifulArrayHelper(n / 2, &rightSize);

    int* res = (int*)malloc(sizeof(int) * (leftSize + rightSize));
    int k = 0;
    for (int i = 0; i < leftSize; i++)
     res[k++] = 2 * left[i] - 1;
    for (int i = 0; i < rightSize; i++)
     res[k++] = 2 * right[i];

    *returnSize = leftSize + rightSize;
    free(left);
    free(right);
    return res;
}
int* beautifulArray(int n, int* returnSize) {
    return beautifulArrayHelper(n, returnSize);
}
