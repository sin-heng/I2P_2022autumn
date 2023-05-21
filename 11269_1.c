#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 500
char content[MAX_SIZE];
char input[MAX_SIZE];
typedef struct Node{
    char ch;
    struct Node* next;
    struct Node* last;
} Node;
int main()
{
    /* your code here */
    //分別記住四種字串的長度
    int len_back = strlen("/backspace");
    int len_left = strlen("/left");
    int len_right = strlen("/right");
    int len_new = strlen("/newline");

    fgets(input,MAX_SIZE,stdin);

    Node head = {input[0],(Node*)malloc(sizeof(Node)),NULL};
    Node* cursor = &head;//用來記住content的位置，充當游標的角色
    Node* temp,*last,*next;
    
    cursor = cursor->next;
    cursor->last = &head;

    int length = strlen(input);

    for(int i=1;i<length;i++){
        if(input[i]=='\n')
            continue;
        if(input[i]=='/'){
            if(input[i+1]=='b'){//backspace
                i+=len_back-1;//跳過'/backspace'的長度，但因為之後會i++，所以要-1
                if(cursor->last!=NULL)//確保content的游標沒超越左邊界
                    cursor = cursor->last;
                last = cursor->last;
                next = cursor->next;
                last->next = next;
                next->last = last;
                free(cursor);
            }
            else if(input[i+1]=='l'){//left
                i+=len_left-1;//跳過'/last'的長度
                if(cursor->last!=NULL)
                    cursor=cursor->last;
            }
            else if(input[i+1]=='n'){//newline
                i+=len_new-1;//跳過'/newline'的長度
                cursor->ch = '\n';
                cursor->next = (Node*)malloc(sizeof(Node));
                temp = cursor;
                cursor = cursor->next;
                cursor->next = NULL;
                cursor->last = temp;
            }
            else if(input[i+1]=='r'){//right
                i+=len_right-1;//跳過'/right'的長度
                if(cursor->next!=NULL)
                    cursor = cursor->next;
            }
        }
        else{
            if(cursor->next==NULL){
                cursor->ch = input[i];
                cursor->next = (Node*)malloc(sizeof(Node));
                temp = cursor;
                cursor = cursor->next;
                cursor->next = NULL;
                cursor->last = temp;
            }
            else{
                last = cursor->last;
                next = cursor;
                cursor = (Node*)malloc(sizeof(Node));
                *cursor = (Node){input[i],next,last};
            }
        }
    }
    cursor = head.next;
    printf("%c",head.ch);
    printf("%c",cursor);
    cursor = cursor->next;
    while(cursor->next!=NULL){
        printf("%c",cursor->ch);
        temp = cursor;
        cursor = cursor->next;
        free(cursor);
    }
    printf("%c",cursor->ch);
    free(cursor);
    return 0;
}