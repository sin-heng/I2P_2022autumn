#include<stdio.h>
#include<stdbool.h>
int Index=0,N,M;
int teleport[1000000][2]={0},maze2[1000][1000]={0};
char maze[1000][1000]={'\0'};
void recur(int x,int y);
bool can_go(int x,int y);
void renew(void);
int main(void){

    int T;

    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&N,&M);
        getchar();
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                scanf("%c",&maze[j][k]);
                if(maze[j][k]=='T'){
                    teleport[Index][0]=j;teleport[Index][1]=k;
                    Index+=1;
                }
            }
            getchar();
        }
        recur(0,0);
        for(int j=0;j<Index;j++)
            recur(teleport[j][0],teleport[j][1]);
        if(maze2[N-1][M-1]==1)
            printf("Yes\n");
        else
            printf("No\n");
        renew();
    }
    return 0;
}
void recur(int x,int y){

    //record
    maze2[x][y]=1;
    //up
    if( 0<=(x-1) && can_go(x-1,y))
        recur(x-1,y);
    //down
    if( (x+1)<N && can_go(x+1,y))
        recur(x+1,y);
    //left
    if( 0<=(y-1) && can_go(x,y-1))
        recur(x,y-1);
    //right
    if( (y+1)<M && can_go(x,y+1))
        recur(x,y+1);
}
bool can_go(int x,int y){

    if(maze2[x][y]==1)
        return 0;
    else if (maze2[x][y]==0 && maze[x][y]=='#')
        return 0;
    else
        return 1;
}
void renew(void){

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            maze2[i][j]=0;
    }
    for(int i=0;i<Index;i++){
        teleport[i][0]=0;
        teleport[i][1]=0;
    }
}