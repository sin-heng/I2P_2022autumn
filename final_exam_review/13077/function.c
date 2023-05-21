#include<stdlib.h>
#include<string.h>
#include"function.h"
#include<assert.h>
#define MAX_SIZE 1000

int cmp(const Node* a,const Node* b){
    if(a->score < b->score) return 1;
    else if(a->score > b->score)    return -1;
    else if(a->score == b->score){ // problem 3
        int i = strcmp(a->name,b->name);
        if(i<0) return -1;
        else if(i>0) return 1;
        else return 0;
    }
}
void Insert( Node** Table, int N, int score, char* name ){

    assert(N<MAX_SIZE);
    Table[N] = (Node*)malloc(sizeof(Node));
    Table[N]->score = score;
    Table[N]->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(Table[N]->name,name);
    
    for(int i=N-1;i>=0;i--){ // problem 1
        if(cmp(Table[i],Table[i+1])==1){
            Node* ntmp = Table[i];
            Table[i] = Table[i+1];
            Table[i+1] = ntmp;
        }
        else break;
    }
}
void Delete( Node** Table, int N, char* name ){

    for(int i=0;i<N;i++){
        if(strcmp(Table[i]->name,name)==0){
            free(Table[i]->name);
            free(Table[i]);
            for(int j=i;j<N-1;j++)
                Table[j] = Table[j+1];
            Table[N-1] = NULL; // problem 2
            return;
        }   
    }
}
int* Top( Node** Table, int N, int x){

    assert(x<=N);
    int* indx = (int*)malloc(sizeof(int)*x);
    for(int i=0;i<x;i++)    indx[i] = i;
    return indx;
}