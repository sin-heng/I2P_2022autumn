#include<stdio.h>
#include<string.h>
char str[1000001];
int sub[1000001];
int type[100001],A[100001],B[100001],Id[100001],C[100001],Ida[100001],Idb[100001];
int alphabet[100001][26];

int main(void){

    int Q,length;
    char a,b;

    scanf("%s",str);
    scanf("%d",&Q);

    length = strlen(str);
    for(int i=0;i<length;i++)
        sub[i]=-1;

    // Input
    for(int i=0;i<Q;i++){
        scanf("%d",&type[i]);
        if(type[i]==1){
            scanf(" %c %c",&a,&b);
            A[i] = a;
            B[i] = b;
        }
        else if(type[i]==2){
            scanf(" %d %c",&Id[i],&a);
            C[i] = a;
        }
        else if(type[i]==3){
            scanf(" %d %d",&Ida[i],&Idb[i]);
        }
    }

    for(int i=0;i<26;i++)
        alphabet[Q][i] = 'a' + i;

    for(int i=Q-1;i>=0;i--){
        for(int j=0;j<26;j++)
            alphabet[i][j] = alphabet[i+1][j];
        if(type[i]==1){
            alphabet[i][A[i]-'a'] = alphabet[i+1][B[i]-'a'];
        }
        else continue;
    }

    for(int i=0;i<Q;i++){
        if(type[i]==2){
            sub[Id[i]] = alphabet[i+1][C[i]-'a']; 
        }
        else if(type[i]==3){
            char ctmp = str[Ida[i]];
            str[Ida[i]] = str[Idb[i]];
            str[Idb[i]] = ctmp;
            int itmp = sub[Ida[i]];
            sub[Ida[i]] = sub[Idb[i]];
            sub[Idb[i]] = itmp;
        }
    }
    // Output
    for(int i=0;i<length;i++){
        if(sub[i]!=-1)
            printf("%c",(char)sub[i]);
        else
            printf("%c",(char)alphabet[0][str[i]-'a']);
    }
    printf("\n");
    return 0;
}