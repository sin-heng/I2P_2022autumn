#include<stdio.h>
void func(int index_s,int index_p);
char S[21],P[21],ans[20];
int Index=0;//remember the index of ans
int main(void){

    scanf("%s",S);
    scanf("%s",P);
    func(0,0);
    return 0;
}
void func(int index_s,int index_p){

    if(S[index_s]=='\0' && P[index_p] == '\0'){
        for(int i=0;i<Index;i++)
            printf("%c",ans[i]);
        printf("\n");
        return;
    }
    else if(S[index_s]=='\0' || P[index_p] == '\0'){
        printf("What's the hack!?");
        return;
    }
    else{
        if(S[index_s]==P[index_p]){func(index_s+1,index_p+1);}
        else if(P[index_p]=='#'){
            for(int i=1;;i++){
                for(int j=0;j<i;j++){
                    ans[Index]=S[index_s+j];
                    Index++;
                }
                ans[Index]=' ';
                Index++;
                func(index_s,index_p+i);
            }
        }
        else if(S[index_s]!=P[index_p])
            return;
    }
}