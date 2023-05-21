#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
int less_step;
int X,Y;
char maze[500][500];
int record[500][500]={0};
void go(int x,int y,int step);
bool cango(char ch);
int count=0;
int main(void){

    int times,x,y;
    scanf("%d",&times);
    for(int i=0;i<times;i++)
    {
        less_step=INT_MAX;
        scanf("%d %d",&X,&Y);
        getchar();
        for(int j=0;j<X;j++){
            for(int k=0;k<Y;k++){
                scanf("%c",&maze[j][k]);
                if(maze[j][k]=='S'){
                    x=j;y=k;
                }
            }
            getchar();
        }
        go(x,y,0);
        if(less_step==INT_MAX)
            printf("%d\n",-1);
        else
            printf("%d\n",less_step);
    }
}
void go(int x,int y,int step){

    record[x][y]=1;
    if(step>less_step){
        record[x][y]=0;
        return;
    }
    if(maze[x][y]=='F'){
        if(step<less_step)
            less_step = step;
    }
    else{
        // left
        if((y-1>=0) && cango(maze[x][y-1]) && record[x][y-1]==0)
            go(x,y-1,step+1);
        // up
        if((x-1>=0) && cango(maze[x-1][y])&& record[x-1][y]==0)
            go(x-1,y,step+1);
        // down
        if((x+1<X) && cango(maze[x+1][y])&& record[x+1][y]==0)
            go(x+1,y,step+1);
        // right
        if((y+1<Y) && cango(maze[x][y+1])&& record[x][y+1]==0)
            go(x,y+1,step+1);
    }
    record[x][y]=0;
}
bool cango(char ch){

    if(ch=='$' || ch=='F')
        return true;
    else
        return false;
}