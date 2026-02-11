You are given a string s of lowercase English letters and an array widths denoting how many pixels wide each lowercase English letter is.
Specifically, widths[0] is the width of 'a', widths[1] is the width of 'b', and so on.

You are trying to write s across several lines, where each line is no longer than 100 pixels. 
Starting at the beginning of s, write as many letters on the first line such that the total width does not exceed 100 pixels.
Then, from where you stopped in s, continue writing as many letters as you can on the second line. Continue this process until you have written all of s.

#include <stdlib.h>

int* numberOfLines(int* widths,int widthsSize,char* s,int* returnSize){
    int lines=1;
    int currWidth=0;
    for(int i=0;s[i];i++){
        int w=widths[s[i]-'a'];
        if(currWidth+w>100){
            lines++;
            currWidth=w;
        } else {
            currWidth+=w;
        }
    }
    int* res=(int*)malloc(sizeof(int)*2);
    res[0]=lines;
    res[1]=currWidth;
    *returnSize=2;
    return res;
}

