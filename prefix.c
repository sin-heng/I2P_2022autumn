#include<stdio.h>
#include<ctype.h>
int prefix(void);
int main(void){
    printf("%d\n",prefix());
    return 0;
}
int prefix(void){
    
    char ch;
    int num1,num2,ans;

    while(isspace(ch=getchar()))
    {
        continue;
    }
    if(ch=='+')
    {
        num1 = prefix();
        num2 = prefix();
        ans = num1+num2;
    }
    else if(ch=='-')
    {
        num1 = prefix();
        num2 = prefix();
        ans = num1-num2;
    }
    else if(ch=='*')
    {
        num1 = prefix();
        num2 = prefix();
        ans = num1*num2;
    }
    else if(isdigit(ch))
    {
        // for one digit number
        return (int)(ch)-48;
        // for two digits number
        ungetc(ch,stdin);
        scanf("%d",&ans);
    }
    return ans;
}