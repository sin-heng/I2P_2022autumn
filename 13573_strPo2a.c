// string operations 2
// 13573
#include<stdio.h>
#include<string.h>
char str[1000001];
int sub[1000001],type[100001],Id[100001],A[100001],B[100001],C[100001];
int alphabet[26];

int main(void){

    int N,id,M;
    char* A,*B,*C;
    char ch1,ch2;

    scanf("%s",str);
    scanf("%d",&N);

    for(int i=0;i<100001;i++)
        sub[i]=-1;
    
    for(int i=0;i<N;i++){
        scanf("%d",&type[i]);
        if(type[i]==1){
            scanf(" %c %c",&ch1,&ch2);
            A[i] = ch1;
            B[i] = ch2;
        }
        else if(type[i]==2){
            scanf(" %d %c",&Id[i],&ch1);
            C[i] = ch1;
        }
    }
    for(int i=0;i<26;i++)
        alphabet[i] = i+'a';
    for(int i=N;i>=0;i--){
        if(type[i]==1){
            alphabet[A[i]-'a'] = alphabet[B[i]-'a'];
        }
        else if(sub[Id[i]]==-1){
            sub[Id[i]]=i;
            C[i] = alphabet[C[i] - 'a'];
        }
    }
    for(int i=0;i<strlen(str);i++){
        if(sub[i]!=-1)
            printf("%c",C[i]);
        else
            printf("%c",alphabet[str[i]]);
    }
    return 0;
}
