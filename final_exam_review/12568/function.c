#include "function.h"
#include <stdlib.h>
void Push(Node** ptr_head, int x){
    Node* nd = (Node*)malloc(sizeof(Node));
    nd->data = x;
    nd->next = *ptr_head;
    *ptr_head = nd;
}
void Pop(Node** ptr_head){
    if(*ptr_head==NULL)
        return;
    Node* nd = (*ptr_head)->next;
    free(*ptr_head);
    *ptr_head = nd;
}
void Reverse_List(Node** ptr_head){
    if(*ptr_head==NULL || (*ptr_head)->next == NULL) // Problem 1
        return;
    Node* Last,*Next;

    Last = *ptr_head; //Last --1
    *ptr_head = (*ptr_head)->next; // ptr_head --2
    Next = (*ptr_head)->next; // Next --3
    Last->next = NULL; // 1 ->NULL
    (*ptr_head)->next = Last; // 2 ->1

    while(Next!=NULL){
        Last = *ptr_head; // Last --2 // Last --3
        *ptr_head = Next; // ptr_head --3 // ptr_head --4
        Next = (*ptr_head)->next; // Next --4 // Next --NULL
        (*ptr_head)->next = Last; // 3 ->2 // 4 ->3
    }
}
// 1->2->3->4