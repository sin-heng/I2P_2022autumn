//NTHU Online Judge
//Yang Mid 12441 Palindrome   
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int main(void){

    char str[100001];
    int j,k;
    bool is_parin = true;

    while(scanf("%s",str)!=EOF)
    {
        is_parin=true;
        for(j=0,k=strlen(str)-1;j<=k;j++,k--)
            if(str[j]!=str[k])
            {
                is_parin = false;
                break;
            }
        if(is_parin)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}