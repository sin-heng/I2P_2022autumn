#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Cat{
    char name[31];
    int occupation;
    int age;
} Cat;
int cmp(const void *a, const void *b){
    Cat A = *(Cat *)a;
    Cat B = *(Cat *)b;
    if(A.occupation==B.occupation){
        if(A.age>B.age) return A.occupation==5?1:-1;
        else if(A.age<B.age) return A.occupation==5?-1:1;
        else if(A.age==B.age) return strcmp(A.name,B.name);
    }
    else if(A.occupation<B.occupation) return -1;
    else if(A.occupation>B.occupation) return 1;
}
int sort(const void* a, const void* b);
int main(void){

    char occupation[8][11]={"elder","nursy","kitty","warrior","apprentice","medicent","deputy","leader"};
    int n,m;
    char occu[11];

    while(~scanf("%d %d",&n,&m)){
        Cat* pt = (Cat*)malloc(sizeof(Cat)*n);

        for(int i=0;i<n;i++){
            scanf("%s %s %d",(pt+i)->name,occu,&(pt+i)->age);
            for(int j=0;j<8;j++)
                if(strcmp(occu,occupation[j])==0)
                    (pt+i)->occupation = j+1;
        }
        qsort(pt,n,sizeof(Cat),sort);
        for(int i=0;i<m && i<n;i++)
            printf("%s\n",(pt+i)->name);
        free(pt);
    }
    return 0;
}
int sort(const void* a, const void* b){
    Cat A = *(Cat*)a;
    Cat B = *(Cat*)b;

    if(A.occupation == B.occupation){
        if(A.age>B.age)
            return A.occupation==5?1:-1;//younger have higher prority
        else if(A.age < B.age)
            return A.occupation==5?-1:1;
        else
            return strcmp(A.name,B.name);//1 means A.name > B.name --> change
    } 
    else if(A.occupation < B.occupation)
        return -1;
    else if(A.occupation > B.occupation)
        return 1;
}