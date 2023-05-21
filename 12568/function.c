#include<stdio.h>
#include<stdlib.h>
#include"function.h"

void Push(Node** ptr_head, int x){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = x;
    head->next = *ptr_head;
    *ptr_head = head;
    //print("%p\n",*ptr_head);
}
void Pop(Node** ptr_head){
    if((*ptr_head)==NULL)
        return;
    Node* next = (*ptr_head)->next;
    free(*ptr_head);
    *ptr_head = next;
}
void Reverse_List(Node** ptr_head){
    if((*ptr_head)==NULL || (*ptr_head)->next==NULL)
        return;

    Node* Prev,*Next;
    
    //number one
    Prev = *ptr_head;//one become prev
    *ptr_head = Prev->next;//two become head
    Next = (*ptr_head)->next;//three become Next

    Prev->next = NULL;//one point to null

    (*ptr_head)->next = Prev;//two point to one

    while(1){
        //printf("while loop\n");
        if(Next==NULL)
            break;
        //renew prev head next
        Prev = *ptr_head;//two become prev
        *ptr_head = Next;
        Next = (*ptr_head)->next;//four become Next

        //head point to prev
        (*ptr_head)->next = Prev;
    }
}