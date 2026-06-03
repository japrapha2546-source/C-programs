#include <stdio.h>
#include <string.h>

int main(){
    char s[100],stack[100];
    int top=-1,i;
    printf("Enter expression: ");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            stack[++top]=s[i];
        }
        else if(s[i]==')'||s[i]=='}'||s[i]==']'){
            if(top==-1){
                printf("Not Balanced");
                return 0;
            }

            char t=stack[top--];

            if((s[i]==')'&&t!='(')||
               (s[i]=='}'&&t!='{')||
               (s[i]==']'&&t!='[')){
                printf("Not Balanced");
                return 0;
            }
        }
    }
    if(top==-1)
        printf("Balanced");
    else
        printf("Not Balanced");

    return 0;
}
