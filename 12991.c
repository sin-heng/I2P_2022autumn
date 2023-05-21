#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/*1 <= N <= 15 石頭
1 <= hi <= 100000 高度
1 <= ci <= 15 顏色號碼*/
int jumped[16]={0},height[16],color[16]; // 紀錄跳躍,紀錄石頭高度,紀錄石頭顏色
int stone,max_jump=0,max_energy=0; // 紀錄石頭數量,最多跳躍數,最多能量
void jump(int start,int end,int index);
bool had_jumped(int n);
void final_process();
int main(void){

    int start,end;

    scanf("%d %d %d",&stone,&start,&end);
    for(int i=1;i<=stone;i++)
        scanf("%d",&height[i]);
    for(int i=1;i<=stone;i++)
        scanf("%d",&color[i]);
    jump(start,end,1);
    printf("%d %d\n",max_energy,max_jump);
    return 0;
}
void jump(int start,int end,int index){

    jumped[index] = start;
    if(start==end)
    {
        final_process();
        for(int i=1;i<=stone;i++)
            printf("%d ",jumped[i]);
        printf("\n");
    }
    else{
        if(!had_jumped(start-1)&&(start-1)>=1)
            jump(start-1,end,index+1);
        for(int i=1;i<=stone;i++)
            if(color[i]==color[start] && !had_jumped(i) && i!=start)
                jump(i,end,index+1);
        if(!had_jumped(start+1)&&(start+1)<=stone)
            jump(start+1,end,index+1);
    }
    jumped[index]=0;
}
bool had_jumped(int n){
    if(jumped[n]!=0)
        return true;
    else    
        return false;
}
void final_process(){
    int jump=0,energy=0;
    for(int i=1;jumped[i+1]!=0;i++){
        jump++;
        energy += abs(height[jumped[i]]-height[jumped[i+1]]);
    }
    if(energy>max_energy)
    {
        max_energy = energy;
        max_jump = jump;
    }
    else if(energy==max_energy && jump>max_jump)
        max_jump = jump;
}