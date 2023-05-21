// string operations 2
// 13573
#include<stdio.h>
#include<string.h>
// s < 10^6
char str[1000001];
int sub[1000001];
// Q < 10^5
int type[100001],Id[100001],A[100001],B[100001],C[100001];
int alphabet[26];
int main(void){

    int N; // N for number of operations; 
    char c1,c2;

    scanf("%s",str);
    scanf("%d",&N);

    // set sub[] to default number: -1
    for(int i=0;i<1000001;i++)
        sub[i]=-1;
    
    // record all operation
    for(int i=0;i<N;i++){
        scanf("%d",&type[i]);
        if(type[i]==1){
            scanf(" %c %c",&c1,&c2);
            A[i] = c1;
            B[i] = c2;
        }
        else if(type[i]==2){
            scanf(" %d %c",&Id[i],&c1);
            C[i] = c1;
        }
    }

    // set up alphabet array
    for(int i=0;i<26;i++)
        alphabet[i] = i+'a';

    // operate from back
    for(int i=N-1;i>=0;i--){
        if(type[i]==1){
            alphabet[A[i]-'a'] = alphabet[B[i]-'a'];
        }
        else if(sub[Id[i]]==-1){
            sub[Id[i]]=i;
            C[i] = alphabet[C[i] - 'a'];
        }
    }

    // output
    int len = strlen(str);
    for(int i=0;i<len;i++){
        if(sub[i]!=-1)
            printf("%c",(char)C[sub[i]]);
        else
            printf("%c",(char)alphabet[str[i]-'a']);
    }
    printf("\n");
    return 0;
}