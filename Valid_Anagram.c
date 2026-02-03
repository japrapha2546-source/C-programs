#define SIZE 256
bool isAnagram(char* s, char* t) {
    int count[SIZE] = {0};

    for(int i = 0; s[i] != '\0'; i++)
     count[tolower(s[i])]++;
    for(int i = 0; t[i] != '\0'; i++) 
     count[tolower(t[i])]--;

    for(int i = 0; i < SIZE; i++) {
        if(count[i] != 0) 
          return false;
    }
    return true;
}
