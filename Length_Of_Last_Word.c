Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int count = 0;
    int i = len - 1;
    while (i >= 0 && s[i] == ' ')
        i--;
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }
    return count;
}
