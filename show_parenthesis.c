// ((((1+2)*3+4)*5+6)*7+8)*9+10
#include<stdio.h>
int show_parenthesis(int n);
int main(void){
    int n;
    n = show_parenthesis(10);
    printf(" = %d\n",n);
    n = show_parenthesis(11);
    printf(" = %d\n",n);
    return 0;
}
int show_parenthesis(int n){
    if(n == 1){
        printf("1");
        return 1;
    }
    else{
        int ans =0;
        if(n%2==1)
        {
            printf("(");
            ans = show_parenthesis(n-1);
            printf(")*%d",n);
            return n*ans;
        }
        else{
            ans = show_parenthesis(n-1);
            printf(" + %d",n);
            return n+ans;
        }
    }
}