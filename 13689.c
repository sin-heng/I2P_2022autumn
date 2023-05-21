#include<stdio.h>
void carpet(int n);
int index_x=0,index_y=0;
int power(int n);
int num=1;
char Carpet[4096][4096]={'\0'};
void print_up_left(int n);
void print_right_down(int n);
void print(char ch,int times);
int main(void){
    
    int x;
    scanf("%d",&x);
    num = power(x+1);
    carpet(x);
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
            printf("%c",Carpet[i][j]);
        printf("\n");
    }
    printf("%d %d",index_x,index_y);
    return 0;
}
void carpet(int n){
    if(n==1){
        // line1
        Carpet[index_x][index_y]='.';
        index_y++;
        print('#',2);
        index_y++;
        Carpet[index_x][index_y]='.';
        // get to position
        index_y-=3;index_x+=1;

        // line2
        print('#',4);
        // get to position
        index_y-=3;index_x+=1;

        // line3
        for(int i=0;i<4;i++,index_y++)
            Carpet[index_x][index_y]='#';
        // get to position
        index_y-=3;index_x+=1;

        // line4
        Carpet[index_x][index_y]='.';
        index_y++;
        print('#',2);
        index_y++;
        Carpet[index_x][index_y]='.';
        // get to position
    }
    else if(n%2==0){
        carpet(n-1);
        index_y++;
        index_x = index_x - power(n) +1;
        carpet(n-1);
        index_x++;
        index_y = index_y - power(n+1) +1;
        carpet(n-1);
        index_y++;
        index_x = index_x - power(n) +1;
        carpet(n-1);
    }
    else if(n%2==1){
        print_up_left(n);
        carpet(n-1);
        print_right_down(n);
    }
}
void print_up_left(int n){
    // index_x=0,index_y=0
    // up
    for(int i=0;i<num/8;i++,index_x++)
    {
        print('.',num/4);
        print('#',num/8);
        print('.',num/4);
        print('#',num/8);
        print('.',num/4);
    }
    index_x++;
    for(int i=0;i<num/8;i++,index_x++)
    {
        print('.',num/4);
        print('#',num/2);
        print('.',num/4);
    }
    // get to position
    index_x++;
    index_y=index_y - num +1;
    // left
    for(int i=0;i<num/8;i++,index_x++)
        print('#',num/4);
    index_x++;
    for(int i=0;i<num/4;i++,index_x++)
    {
        print('#',num/8);
        print('.',num/8);
    }
    index_x++;
    for(int i=0;i<num/8;i++,index_x++)
        print('#',num/4);
    // get to position
    index_y++;
    index_x = index_x - num/2 +1;
}
void print_right_down(int n){

    for(int i=0;i<num/8;i++,index_x++)
    {
        for(int j=0;j<num/4;j++,index_y++)
            Carpet[index_x][index_y]='#';
    }
    index_x++;
    for(int i=0;i<num/4;i++,index_x++)
    {
        for(int j=0;j<num/8;j++,index_y++)
            Carpet[index_x][index_y]='.';
        for(int j=0;j<num/8;j++,index_y++)
            Carpet[index_x][index_y]='#';
    }
    index_x++;
    for(int i=0;i<num/8;i++,index_x++)
    {
        for(int j=0;j<num/4;j++,index_y++)
            Carpet[index_x][index_y]='#';
    }

}
void print(char ch,int times){
    
    for(int i=0;i<times;i++,index_y++)
        Carpet[index_x][index_y]=ch;
    index_y -- ;
}
int power(int n){
    int num=1;
    for(int i=0;i<n;i++)
        num*=2;
    return num;
}