//NTHU Online Judge
//Yang HW8 12459 Sierpinski Carpet
#include<stdio.h>
long long count(long long n);
int main(void){
    
    long long num;
    scanf("%lld",&num);
    long long sum = count(num);
    printf("%lld\n",sum);
    return 0;
}
long long count(long long n)
{
    if(n==0)    
        return 0;
    else if(n==1)
        return 1;
    else{
        return (count(n-1)-count(n-2))*9 + count(n-2);
    }
}