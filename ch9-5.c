// Question in C Premeier plus ch9-5
#include<stdio.h>
void large_of(double* x,double* y);
int main(void){

    double x=12.4,y=3.23;
    large_of(&x,&y);
    printf("x: %.2f, y: %f\n",x,y);
    return 0;
}
void large_of(double* x,double* y){
    int max = (*x>*y)?*x:*y;
    *x = max;*y = max;
}