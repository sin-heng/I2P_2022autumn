//NTHU Online Judge
//Yang HW7 11194 Stairs Climbing   
#include<stdio.h>
int climb(int n);
int main(void){

    int lines,num,ans;
    scanf("%d",&lines);
    for(int i=0;i<lines;i++)
    {
        scanf("%d",&num);
        ans = climb(num);
        printf("%d\n",ans);
    }
}
int climb(int n){
    
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else{
        int ans = climb(n-1) + climb(n-2);
        return ans;
    }
    
}