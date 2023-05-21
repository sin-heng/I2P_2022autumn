#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void){

    int n,m,x,y;
    char op[8],str[101];
    int len[101];

    scanf("%d %d",&n,&m);
    char** st = (char**)malloc(sizeof(char*)*(n+1));

    for(int i=1;i<=n;i++){
        st[i]=(char*)malloc(sizeof(char)*1);
        st[i][0]='\0';
        len[i] = 0;
    }
        
    while(m--){
        scanf("%s",op);
        if(strcmp(op,"add")==0){
            scanf("%d%s",&x,str);
            // change length
            len[x] +=strlen(str);
            // malloc new memory
            char* temp = (char*)malloc(sizeof(char)*(len[x]+1));
            strcpy(temp,st[x]);
            strcat(temp,str);
            free(st[x]);
            st[x] = temp;
        }
        else if(strcmp(op,"delete")==0){
            scanf("%d%d",&x,&y);
            if(y>=len[x]){
                free(st[x]);
                st[x] = (char*)malloc(sizeof(char)*1);
                st[x][0] = '\0';
                len[x] = 0;
            }
            else{
                len[x] -= y;
                char* temp = (char*)malloc(sizeof(char)*(len[x]+1));
                strncpy(temp,st[x],len[x]);
                temp[len[x]]= '\0';
                free(st[x]);
                st[x] = temp;
            }

        }
        else if(strcmp(op,"swap")==0){
            scanf("%d%d",&x,&y);
            char* temp = st[x];
            st[x] = st[y];
            st[y] = temp;
            int itemp = len[x];
            len[x] = len[y];
            len[y] = itemp;
        }
        else if(strcmp(op,"longest")==0){
            int longest = len[1],Index=1;
            for(int i=1;i<=n;i++){
                if(len[i]>longest){
                    Index = i;
                    longest = len[i];
                }
            }
            printf("%d %s\n",len[Index],st[Index]);
        }
        else if(strcmp(op,"all")==0){
            for(int i=1;i<=n;i++)
                printf("%s\n",st[i]);
        }
    }
    free(st);
    return 0;
}        