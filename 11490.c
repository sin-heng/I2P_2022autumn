#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Cat{
    char name[31];
    int occupation;
    int age;
} Cat;
void sort(Cat* pt,int n);
int main(void){

    char occupation[8][11]={"elder","nursy","kitty","warrior","apprentice","medicent","deputy","leader"};
    int n,m;
    char occu[11];

    scanf("%d %d",&n,&m);
    Cat* pt = (Cat*)malloc(sizeof(Cat)*n);

    for(int i=0;i<n;i++){
        scanf("%s %s %d",(pt+i)->name,occu,&(pt+i)->age);
        for(int j=0;j<8;j++)
            if(strcmp(occu,occupation[j])==0)
                (pt+i)->occupation = j;
    }
    //for(int i=0;i<n;i++)
    //    printf("%s %d %d\n",(pt+i)->name,(pt+i)->occupation,(pt+i)->age);
    sort(pt,n);
    for(int i=0;i<m;i++)
        printf("%s\n",(pt+i)->name);
    free(pt);
    return 0;
}
void sort(Cat* pt,int n){

    Cat temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((pt+i)->occupation > (pt+j)->occupation){
                temp = *(pt+i);
                *(pt+i) = *(pt+j);
                *(pt+j) = temp;
            }
            else if((pt+i)->occupation == (pt+j)->occupation && (pt+i)->occupation != 4){
                if((pt+i)->age < (pt+j)->age){
                    temp = *(pt+i);
                    *(pt+i) = *(pt+j);
                    *(pt+j) = temp;
                }
                else if((pt+i)->age == (pt+j)->age){
                    if(strcmp((pt+i)->name,(pt+j)->name)==1){
                        temp = *(pt+i);
                        *(pt+i) = *(pt+j);
                        *(pt+j) = temp;
                    }
                }
            }
            else if((pt+i)->occupation == (pt+j)->occupation && (pt+i)->occupation == 4){
                if((pt+i)->age > (pt+j)->age){
                    temp = *(pt+i);
                    *(pt+i) = *(pt+j);
                    *(pt+j) = temp;
                }
                else if((pt+i)->age == (pt+j)->age){
                    if(strcmp((pt+i)->name,(pt+j)->name)==1){
                        temp = *(pt+i);
                        *(pt+i) = *(pt+j);
                        *(pt+j) = temp;
                    }
                }
            }
        }
    }
}