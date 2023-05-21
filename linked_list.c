#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int n;
    struct Node* next;
} Node;
int main(void){

    Node head;
    Node* pt1,* pt2;
    int i=1;

    head.n=0;
    head.next = (Node*)malloc(sizeof(Node));
    pt1 = head.next;
    while(i<10){
        pt1->n = i;
        pt1->next = (Node*)malloc(sizeof(Node));
        pt1 = pt1->next;
        i++;
    }
    pt1->n = i;
    pt1->next = NULL;

    printf("Node %d: %d\n",0,head.n);
    i=1;
    pt1 = head.next;
    while(pt1->next!=NULL){
        printf("Node %d: %d, next: %p\n",i,pt1->n,pt1->next);
        pt1 = pt1->next;
        i++;
    }
    printf("Node %d: %d, next: %p\n",i,pt1->n,pt1->next);

    pt1 = head.next;
    i=1;
    while(pt1->next!=NULL){
        pt2 = pt1;
        pt1 = pt1->next;
        free(pt2);
        printf("free node %d\n",i);
        i++;
    }
    free(pt2);
    printf("free node %d\n",i);
    return 0;
}