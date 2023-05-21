#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
char str[1000];
int record[1000][1000]={INT_MAX};
int Times,length;
int check_palin(int l,int r);
int main(void){

    scanf("%d %d",&length,&Times);
    getchar();
    for(int i=0;i<length;i++)
        scanf("%c",&str[i]);
    printf("%d",check_palin(0,length-1));
    /*
    if(check_palin(0,length-1)<=Times)
        printf("Yes\n");
    else
        printf("No\n");
    */
    return 0;
}
int check_palin(int l,int r){
    if(l>=r){
        return 0;
    }
    if(record[l][r]!=INT_MAX)
        return record[l][r];
    else{
        if(str[l]==str[r]){
            record[l][r] = check_palin(l+1,r-1);
            return record[l][r];
        }
        else if(str[l]!=str[r]){
            record[l][r] = min(check_palin(l+1,r)+1,check_palin(l,r-1)+1);
            return record[l][r];
        }
    }
}