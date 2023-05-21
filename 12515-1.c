#include<stdio.h>
int line[10000001],comfort[10000001]={0};
int main(void){

    int N,X,count=0,i,j;

    scanf("%d %d",&N,&X);
    int ans[N+1];
    for(i=1;i<=N;i++){
        scanf("%d",&line[i]);
        for(j=i-1;j>=1;){
            if(line[j]<line[i]){
                j = j - (comfort[j] +1);
            }
            else
                break;
        }
        comfort[i] = i-j-1;
        if(comfort[i]==X){
            ans[count]=i;
            count++;
        }
    }
    if(count==0){
        printf("ouo");
    }
    else{
        printf("%d",ans[0]);
        for(int i=1;i<count;i++)
            printf(" %d",ans[i]);
    }
    printf("\n");
    return 0;
}