#include<stdio.h>
int line[10000001],comfort[10000001];
void Comfort(int index1,int index2);
int main(void){

    int N,X,flag=1;

    scanf("%d %d",&N,&X);
    for(int i=0;i<N;i++){
        scanf("%d",&line[i]);
        if(i>0){
            Comfort(i,i-1);
            if(comfort[i]==X){
                printf("%d ",i+1);
                flag=0;
            }
        }
    }
    if(flag)
        printf("ouo\n");
    else
        printf("\n");
    return 0;
}
void Comfort(int index1,int index2){

    if(index2<0)
        return;

    //if(line[index1]==line[index2]){
      //  comfort[index1]=comfort[index2];
        //printf("%d: equal case\n",index1);
    //}
    if(line[index1]<=line[index2]){
        return;
        //printf("%d: smaller case\n",index1);
    }
    else if(line[index1]>line[index2]){
        comfort[index1]+=comfort[index2]+1;
        //printf("%d: recursion case\n",index1);
        if(index1-comfort[index2]-2 == index2)
            return;
        else
            Comfort(index1,index1-comfort[index2]-2);
    }
}