bool isPalindrome(char* s) {
    int l=0;
    int r=strlen(s)-1;
    while(l<r){
        if(!isalnum(s[l])){
            l++;
            continue;
        }
        if(!isalnum(s[r])){
            r--;
            continue;
        }
        if(tolower(s[l])!=tolower(s[r]))
            return false;
        l++;
        r--;
    }
    return true;
}
