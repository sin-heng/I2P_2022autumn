// Question in C Premeier plus ch9-4
#include<stdio.h>
double hor_mean(double x,double y);
int main(void){

    printf("hor_mean:%.2f\n",hor_mean(0.2,0.3));
    printf("normal:%.2f\n",(2/(5 + 10/3)));
    return 0;
}
double hor_mean(double x,double y){
    return (2*x*y)/x*y;
}