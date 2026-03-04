Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

int lengthOfLongestSubstring(char* s) {
    int index[256];
    for(int i=0;i<256;i++){
        index[i]=-1;
    }
    int maxlen=0,start=0;
    for(int i=0;s[i]!='\0';i++){
        unsigned char c=s[i];
        if(index[c]>=start)
          start=index[c]+1;
        index[c]=i;
        int len=i-start+1;
        if(len>maxlen)
             maxlen=len;
    }
    return maxlen;
} 
