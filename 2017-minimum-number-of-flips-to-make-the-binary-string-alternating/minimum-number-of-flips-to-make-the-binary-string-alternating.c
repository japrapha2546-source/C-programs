int minFlips(char* s) {
    int n = strlen(s);
    int minFlips = n;

    char t[2*n + 1];
    strcpy(t, s);
    strcat(t, s);

    int flipsPattern0 = 0, flipsPattern1 = 0;

    for (int i = 0; i < 2 * n; i++) {
        char expected0 = (i % 2 == 0) ? '0' : '1';
        char expected1 = (i % 2 == 0) ? '1' : '0';

        if (t[i] != expected0)
         flipsPattern0++;
        if (t[i] != expected1)
         flipsPattern1++;

        if (i >= n) {
            char leftExpected0 = ((i - n) % 2 == 0) ? '0' : '1';
            char leftExpected1 = ((i - n) % 2 == 0) ? '1' : '0';

            if (t[i - n] != leftExpected0)
             flipsPattern0--;
            if (t[i - n] != leftExpected1)
             flipsPattern1--;
        }

        if (i >= n - 1) {
            if (flipsPattern0 < minFlips)
             minFlips = flipsPattern0;
            if (flipsPattern1 < minFlips)
             minFlips = flipsPattern1;
        }
    }
    return minFlips;
}