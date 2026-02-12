Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int maxVowels(char*s,int k){
    int n=strlen(s);
    int count=0;
    int maxCount=0;
    for(int i=0;i<k&&i<n;i++){
        if(isVowel(s[i]))
            count++;
    }
    maxCount=count;
    for(int i=k;i<n;i++){
        if(isVowel(s[i-k]))
            count--;
        if(isVowel(s[i]))
            count++;
        if(count>maxCount)
            maxCount=count;
    }
    return maxCount;
}
