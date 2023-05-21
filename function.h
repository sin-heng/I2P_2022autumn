#ifndef FUNCTION_H
#define FUNCTION_H

#include<ctype.h>
#include<stdio.h>
#include "function.h"
int number[1000];
int Count(int num,int sign);
int Pow(int y);
int solver(int **ptr, int *sum, char *s){
    int num=0,sign=1,count=0;
    for(int i=0;s[i]!='\0';i++){
        if(isdigit(s[i])){
            number[num]=(int)s[i]-48;
            num++;
            if(!isdigit(s[i+1])){
                *ptr[count] = Count(num,sign);
                *sum += *ptr[count];
                sign=1;
                num=0;
                count++;
            }
        }
        else if(s[i]=='-'){
            if(isdigit(s[i+1]))
                sign=-1;
        }
    }
    return count;
}
int Count(int num,int sign){
    int sum=0;
    for(int i=0;i<num;i++){
        sum += (number[i]*Pow(num-i-1));
    }
    sum*=sign;
    return sum;
}
int Pow(int y){
    int num=1;
    for(int i=0;i<y;i++)
        num*=10;
    return num;
}
#endif

