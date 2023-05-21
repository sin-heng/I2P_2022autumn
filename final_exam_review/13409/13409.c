#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void){

    char op[8],stmp[101];
    int x,y,N,M;
    int len[101];

    scanf("%d %d",&N,&M);

    char** st = (char**)malloc(sizeof(char*)*(N+1));
    for(int i=1;i<=N;i++){
        st[i] = (char*)malloc(sizeof(char)*1);
        st[i][0]='\0';
        len[i]=0;
    }

    for(int i=0;i<M;i++){
        scanf("%s",op);
        if(strcmp(op,"add")==0){
            scanf("%d %s",&x,stmp);
            len[x] += strlen(stmp);
            char* tmp = (char*)malloc(sizeof(char)*(len[x]+1));
            strcpy(tmp,st[x]);
            strcat(tmp,stmp);
            free(st[x]);
            st[x] = tmp;
        }
        else if(strcmp(op,"delete")==0){
            scanf("%d %d",&x,&y);
            if(y>=len[x]){
                char* tmp = (char*)malloc(sizeof(char));
                free(st[x]);
                st[x] = tmp;
                st[x][0]='\0';
                len[x]=0;
            }
            else{
                len[x] -= y;
                char* tmp = (char*)malloc(sizeof(char)*(len[x]+1));
                strncpy(tmp,st[x],len[x]);
                tmp[len[x]] = '\0';
                free(st[x]);
                st[x] = tmp;
            }
        }
        else if(strcmp(op,"swap")==0){
            scanf("%d %d",&x,&y);
            char* tmp = st[x];
            st[x] = st[y];
            st[y] = tmp;
            int itmp = len[x];
            len[x] = len[y];
            len[y] = itmp;
        }
        else if(strcmp(op,"longest")==0){
            int longest = len[1],Index=1;
            for(int i=2;i<=N;i++){
                if(len[i]>longest){
                    longest = len[i];
                    Index = i;
                }
            }
            printf("%d %s\n",len[Index],st[Index]);
        }
        else if(strcmp(op,"all")==0){
            for(int i=1;i<=N;i++)
                printf("%s\n",st[i]);
        }
    }
    free(st);
    return 0;
}