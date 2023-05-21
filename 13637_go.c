//NTHU Online Judge
//Yang Mid 13637 Easy Gomoku Validator    
#include<stdio.h>
int check(char player,int di);
void winner(char player,int round);
char board[16][16];
int direc[8][2]={{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
int x,y;
int main(void){

    int round=1,num;
    char player;

    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d %d",&x,&y);
        if(round%2==1)
            player='B';
        else 
            player= 'W';
        board[x][y] = player;
        for(int j=0;j<8;j+=2)
        {
            if(check(player,j)>=5)
            {
                winner(player,round);
                return 0;
            }
        }
        round++;
    }
    printf("There's no winner.\n");
    return 0;
}
int check(char player,int di){
    int count=-1;
    for(int i=x,j=y;(i>0&&i<16)&&(j>0&&j<16);i+=direc[di][0],j+=direc[di][1])
    {
        if(board[i][j]==player)
            count++;
        else 
            break;
    }
    for(int i=x,j=y;(i>0&&i<16)&&(j>0&&j<16);i+=direc[di+1][0],j+=direc[di+1][1])
    {
        if(board[i][j]==player)
            count++;
        else 
            break;
    }
    return count;
}
void winner(char player,int round){
    if(player=='B')
        printf("LSC wins at the %dth step.\n",round);
    else 
        printf("TSC wins at the %dth step.\n",round);
}