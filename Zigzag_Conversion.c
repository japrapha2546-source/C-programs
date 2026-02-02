#include <stdlib.h>
#include <string.h>
char* convert(char* s, int numRows){
    int len = strlen(s);
    if(numRows == 1 || numRows >= len)
     return strdup(s);
    char* res = malloc(len + 1);
    int idx = 0;
    for(int r = 0; r < numRows; r++){
        int step1 = (numRows - r - 1) * 2;
        int step2 = r * 2;
        int i = r;
        int toggle = 1;
        while(i < len){
            res[idx++] = s[i];
            if(step1 == 0) 
             i += step2;
            else if(step2 == 0)
             i += step1;
            else 
             i += toggle ? step1 : step2;
            toggle = !toggle;
        }
    }
    res[idx] = '\0';
    return res;
}
