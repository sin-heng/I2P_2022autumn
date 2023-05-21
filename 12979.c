#include<stdio.h>
#include<stdbool.h>
void Sum(int index,int sum);
int num,target;
int numli[20];
bool find=false;
int main(void){

    scanf("%d %d",&num,&target);
    for(int i=0;i<num;i++)
        scanf("%d",&numli[i]);
    Sum(0,0);
    if(find)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
void Sum(int index,int sum){

    if(sum==target){
        find=true;
        return;
    }
    if(index==num)
        return;
    Sum(index+1,sum);
    Sum(index+1,sum+numli[index]);
}