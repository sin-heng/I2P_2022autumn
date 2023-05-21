#include<stdio.h>
int fabo(int n);
int main(void){

    for(int i=0;i<10;i++){
        printf("%d: %d\n",i,fabo(i));
    }
    return 0;
}
int fabo(int n){
    if(n==0)
        return 1;
    else if(n==1)
        return 1;
    else{
        return fabo(n-1)+fabo(n-2);
    }
}