// Question in C Premeier plus ch9-3
#include<stdio.h>
void print(char ch,int times,int lines);
void test();
int main(void){

    test();
    return 0;
}
void print(char ch,int times,int lines){
    for(int i=0;i<lines;i++)
    {
        for (int j = 0; j < times; j++)
        {
            printf("%c",ch);
        }
        printf("\n");
    }
}
void test(){
    
    char ch = 'a';int times =10;int lines = 3;
    print(ch,times,lines);
    ch = 'c';times =4;lines = 2;
    print(ch,times,lines);
    ch = 'z';times =15;lines = 1;
    print(ch,times,lines);
}