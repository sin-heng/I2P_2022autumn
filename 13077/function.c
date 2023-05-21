#include<stdio.h>
#include"function.h"
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 1000

int cmp(const Node* a, const Node* b ){
    if( a->score > b->score ) return -1;
    if( a->score < b->score ) return 1;
    int sc = strcmp(a->name, b->name);
    if( sc > 0 ) return 1;
    if( sc < 0) return -1;
    return 0;
}
/*
int cmp(const void* A, const void* B ){
    Node* a = (Node*)A;
    Node* b = (Node*)B;

    if( a->score > b->score ) return -1;
    if( a->score < b->score ) return 1;
    int sc = strcmp(a->name, b->name);
    if( sc > 0 ) return 1;
    if( sc < 0) return -1;
    return 0;
}
*/
void Insert( Node** Table, int N, int score, char* name ){

    assert(N<MAX_SIZE);
    Table[N] = (Node*)malloc(sizeof(Node));

    Table[N]->score = score;
    Table[N]->name = (char*)malloc(sizeof(char)*(strlen(name)+1));

    strcpy(Table[N]->name,name);
    for(int i=N-1;i>=0;i--){
        if(cmp(Table[i],Table[i+1])==1){
                Node* temp = Table[i];
                Table[i] = Table[i+1];
                Table[i+1] = temp;
            }
    }
}   
void Delete( Node** Table, int N, char* name ){

    for(int i=0;i<N;i++){
        if(strcmp(Table[i]->name,name)==0){
            free(Table[i]->name);
            free(Table[i]);
            for(int j=i;j<N-1;j++)
                Table[j] = Table[j+1];     
            Table[N-1] = NULL;         
            return;
        }
    }
}
int* Top( Node** Table, int N, int x){

    assert(x<=N);
    int* top = (int*)malloc(sizeof(int)*x);
    /*
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++)
            if(cmp(Table[i],Table[j])==1){
                    Node* temp = Table[i];
                    Table[i] = Table[j];
                    Table[j] = temp;
                }
    }
    */
    //qsort(*Table,N,sizeof(Table[0]),cmp);
    for(int i=0;i<x;i++)
        top[i]=i;
    return top;
}