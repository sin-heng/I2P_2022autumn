#include<stdio.h>
int di[1000][2];
int Index=0;
int Count(int index);
int main(void){

    int n,k,index=0;
    char ch;
    char temp[8]={0};

    scanf("%d %d",&n,&k);
    while(ch=getchar()){
        if(ch=='|'){
            di[Index][0]=Count(index);
            Index+=1;
            index=0;
        }
        else{
            temp[index]=ch;
            index+=1;
        }
    }
    
}
int Count(int index){

}