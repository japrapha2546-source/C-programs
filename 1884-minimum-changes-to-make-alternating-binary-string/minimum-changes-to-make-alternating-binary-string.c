int minOperations(char* s) {
    int n = strlen(s);
    int flips0 = 0, flips1 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != (i % 2 == 0 ? '0' : '1'))
         flips0++;
        if (s[i] != (i % 2 == 0 ? '1' : '0'))
         flips1++;
    }
    return flips0 < flips1 ? flips0 : flips1;
}