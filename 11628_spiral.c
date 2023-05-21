//NTHU Online Judge
//Yang Mid 11628 Spiral
#include<stdio.h>
char spiral[5000][5000] = {'\0'};
int Index[2]={0,-1};
void func(int x,int y,int z);
int main(void){
    
    int times,circle,count;
    int direc[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    
    scanf("%d",&times);
    for(int i=0;i<times;i++)
    {
        scanf("%d",&circle);
        count =0;
        for(int j=circle;j>0;j--)
        {
            func(direc[count%4][0],direc[count%4][1],j);
            count++;
        }
        
        for(int j=0;j<circle;j++)
        {
            for(int k=0;k<circle;k++)
            {
                if(spiral[j][k]!='#')
                    putchar(' ');
                else
                    putchar(spiral[j][k]);
                spiral[j][k] ='\0';
            }
            printf("\n");
        }
        Index[0] = 0;
        Index[1] = -1;
    }
    return 0;
}
void func(int x,int y,int z){

    for(int i=0;i<z;i++)
    {
        Index[0] +=x;
        Index[1] +=y;
        spiral[Index[0]][Index[1]] = '#';
    }
}