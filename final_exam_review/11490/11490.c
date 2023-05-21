#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1. elder2. nursy3. kitty4. warrior5. apprentice6. medicent7. deputy8. leader
typedef struct cat{
    int age;
    char name[31];
    int occu;
} Cat;
char occupation[8][11] = {"elder","nursy","kitty","warrior","apprentice","medicent","deputy","leader"};
int cmp(const void* A,const void*B);
int main(void){

    int N,M;
    char occu[11];

    while(~scanf("%d %d",&N,&M)){
        Cat* cat = (Cat*)malloc(sizeof(Cat)*N);
        for(int i=0;i<N;i++){
            scanf("%s %s %d",(cat[i].name),occu,&(cat[i].age));
            for(int j=0;j<8;j++){
                if(strcmp(occu,occupation[j])==0){
                    cat[i].occu = j;
                    break;
                }
            }
        }
        qsort(cat,N,sizeof(Cat),cmp);
        for(int i=0;i<N && i<M;i++)
            printf("%s\n",cat[i].name);
        free(cat);
    }
    return 0;
}
int cmp(const void* A,const void*B){
    
    Cat a = *(Cat*)A;
    Cat b = *(Cat*)B;

    if(a.occu > b.occu) return 1;
    else if(a.occu < b.occu) return -1;
    else if(a.occu == b.occu &&  a.occu== 4){
        if(a.age > b.age) return 1;
        else if(a.age < b.age) return -1;
        else if(a.age == b.age) return strcmp(a.name,b.name);
    }
    else if(a.occu == b.occu){
        if(a.age > b.age) return -1;
        else if(a.age < b.age) return 1;
        else if(a.age == b.age) return strcmp(a.name,b.name);
    }
}