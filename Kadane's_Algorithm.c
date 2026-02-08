int maxSubarraySum(int arr[], int n) {
    int maxSoFar = arr[0], maxEndingHere = arr[0];
    for(int i = 1; i < n; i++){
        maxEndingHere = (maxEndingHere < 0 ? arr[i] : maxEndingHere + arr[i]);
        if(maxEndingHere > maxSoFar)
          maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}
