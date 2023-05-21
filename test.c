#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum Direction{
    RIGHT,LEFT,UP,DOWN
} Direction;
void func(Direction next);
int main(void){

    Direction next = RIGHT;
    printf("%d\n",next);
    func(UP);
    return 0;
}
void func(Direction next){
    Direction hi = next;
    printf("%d\n",hi);
}