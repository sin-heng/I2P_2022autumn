#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char name[21];
    int current,max;
} P;
void hp_full(P* pt,P* pt1,P* pt2,int n);
void current_hp();
void max_hp();
int index1=0,index2=0;
int main(void){

    int n;
    scanf("%d",&n);
    getchar();

    P* pt = (P*)malloc(sizeof(P)*n);
    P* pt1 = (P*)malloc(sizeof(P)*n);
    P* pt2 = (P*)malloc(sizeof(P)*n);
    for(int i=0;i<n;i++)
        scanf("%s %d %d",(pt+i)->name,&(pt+i)->current,&(pt+i)->max);
    hp_full(pt,pt1,pt2,n);
    current_hp(pt1,index1);
    max_hp(pt1,index1);
    max_hp(pt2,index2);
    printf("-----------------");
    for(int i=0;i<index1;i++)
        printf("%s %d %d\n",(pt1+i)->name,(pt1+i)->current,(pt1+i)->max);
    for(int i=0;i<index2;i++)
        printf("%s %d %d\n",(pt2+i)->name,(pt2+i)->current,(pt2+i)->max);
    return 0;
}
void hp_full(P* pt,P* pt1,P* pt2,int n){
    for(int i=0;i<n;i++){
        if((pt+i)->current < (pt+i)->max){
            *(pt1+index1) = *(pt+i);
            index1++;
        }
        else{
            *(pt2+index2) = *(pt+i);
            index2++;
        }
    }
}
void current_hp(P* pt,int n){
    int min;
    P temp;
    for(int i=0;i<n;i++){
        min=(pt+i)->current;
        for(int j=i+1;j<n;j++){
            if((pt+j)->current<min){
                temp = *(pt+j);
                *(pt+j) = *(pt+i);
                *(pt+i) = temp;
            }
        }
    }
}
void max_hp(P* pt,int n){
    int min;
    P temp;
    for(int i=0;i<n;i++){
        min=(pt+i)->max;
        for(int j=i+1;j<n;j++){
            if((pt+j)->max<min && (pt+j)->current == (pt+i)->current){
                temp = *(pt+j);
                *(pt+j) = *(pt+i);
                *(pt+i) = temp;
            }
        }
    }
}