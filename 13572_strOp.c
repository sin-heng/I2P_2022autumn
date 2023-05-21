//NTHU Online Judge
//Yang HW5 13572 String Operations 1   
#include<stdio.h>
#include<string.h>
int main(void){

    char str[1000001];
    int num;
    char alphabet[27]; // from 1 to 26
    char ch1,ch2;
    /*
    1: get line
    2: get command number
    3: throw '\n'
    4: %c %c get command
    5: change array alphabet
    6: use alphabet to change array
    7: output
    */
    for(int i=1;i<=26;i++){alphabet[i]=(char)(96+i);}
    scanf("%s",str);
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        getchar();
        scanf("%c %c",&ch1,&ch2);
        for(int i=1;i<=26;i++)
            if(alphabet[i]==ch1)
            {
                alphabet[i] = ch2;
            }
    }
    int length = strlen(str);
    for(int i=0;i<length;i++)
        str[i] = alphabet[(int)(str[i])-96];
    printf("%s\n",str);
    return 0;
}