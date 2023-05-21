#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char recur(int n, long long int k);
long long int len[100];
char f0[2001],f1[2001];
int main(void){

    int T,n;
    long long int k;

    scanf("%d",&T);
    while(T--){
        scanf("%s %s",f0,f1);
        scanf("%d %lld",&n,&k);

        len[0] = strlen(f0);
        len[1] = strlen(f1);

        for(int i=2;i<100;i++)
            len[i] = len[i-1] + len[i-2];
        char ans = recur(n,k);
        printf("%c\n",ans);
    }
    
    return 0;
}
char recur(int n, long long int k){

    if(n==0) return f0[k];
    else if(n==1) return f1[k];
    else{
        if(k<len[n-2]) recur(n-2,k);
        else if(len[n-2]<=k) recur(n-1,k-len[n-2]);
    }
}