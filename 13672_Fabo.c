//NTHU Online Judge
//Yang HW7 13672 Fibonacci's soup     
#include<stdio.h>
long long f(long long n);
long long g(long long n);
int a,b,c,d;
int main(){

    int n;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&n);
    printf("%lld %lld\n",f(n),g(n));
    return 0;
}
long long f(long long n){
    if(n==0)
        return a;
    else if(n==1)
        return b;
    else
    {
        if(n%2==0)
            return f(n-1)+g(n/2);
        else 
            return f(n-1) + g(n-2);
    }
}
long long g(long long n){
    if(n==0)
        return c;
    else if(n==1)
        return d;
    else
    {
        if(n%3==0)
            return g(n-1)+f(n/3);
        else 
            return g(n-1) + f(n-2);
    }
}