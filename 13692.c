#include<stdio.h>
#include<string.h>
int alphabet[1000001][26];
int sub[1000001];
int type[100001],Id[100001],A[100001],B[100001],C[100001],Ida[100001],Idb[100001];
int main(void){

    char str[1000001];
    int Q;
    //int type1=0,type2=0;

    scanf("%s",str);
    scanf("%d",&Q);
    
    for(int i=0;i<26;i++)
        alphabet[Q][i] = i+'a';

    for(int i=0;i<1000001;i++)
        sub[i] = -1;

    for(int i=0;i<Q;i++){
        scanf("%d",&type[i]);
        if(type[i]==1){
            scanf(" %c %c",&A[i],&B[i]);
        }
        else if(type[i]==2){
            scanf(" %d %c",&Id[i],&C[i]);
        }
        else if(type[i]==3){
            scanf(" %d %d",&Ida[i],&Idb[i]);
        }
    }
    //phase 1
    for(int i=Q-1;i>=0;i--){
        for(int j=0;j<26;j++)
            alphabet[i][j] = alphabet[i+1][j];
        if(type[i]==1){
            alphabet[i][A[i]-'a'] = alphabet[i+1][B[i]-'a'];
        }
        else
            continue;
    }
    //phase 2
    for(int i=0;i<Q;i++){
        if(type[i]==2)
            sub[Id[i]] = alphabet[i+1][C[i]-'a'];
        else if(type[i]==3){
            char tmp = str[Ida[i]];
            str[Ida[i]] = str[Idb[i]];
            str[Idb[i]] = tmp;
            int itmp = sub[Ida[i]];
            sub[Ida[i]] = sub[Idb[i]];
            sub[Idb[i]] = itmp;
        }
    }

    int len = strlen(str);
    for(int i=0;i<len;i++){
        if(sub[i]!=-1){
            printf("%c",(char)sub[i]);
            //type1 ++ ;
        }
        else{    
            printf("%c",(char)alphabet[0][str[i]-'a']);
            //type2++;
        }
    }
    printf("\n");
    //printf("%d %d\n",type1,type2);
    return 0;
}