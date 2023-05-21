//Tower of Hanoi with steps
#include<stdio.h>
void hanoi(int n, char start, char temp, char end);
int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
void hanoi(int n, char start, char temp, char end){

    if(n>=1){
        hanoi(n-1,start,end,temp);
        printf("move disk %d from rod %c to rod %c\n",n,start,end);
        hanoi(n-1,temp,start,end);
    }
}