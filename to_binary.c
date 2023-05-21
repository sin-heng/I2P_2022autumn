#include<stdio.h>
void binary(unsigned long n);
int main(void){
    
    int num;
    printf("Enter an integer ( q to quit ): ");
    while(scanf("%lu",&num))
    {
        printf("Binary equivalence: ");
        binary(num);
        printf("\nEnter an integer ( q to quit ): ");
    }
    printf("Bye.");
    return 0;
}
void binary(unsigned long n){
    int r = n%2;
    if(n>=2)
        binary(n/2);
    printf("%d",r);
}