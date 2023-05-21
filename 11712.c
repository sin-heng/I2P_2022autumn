#include<stdio.h>
#include<string.h>
int x=0;//count for '='
int y=0;//count for '.'
int Index=0;//remember the index of temp
char temp[5]={'\0'};
char dict[26][5]={"*-","-***","-*-*","-**","*","**-*","--*","****",
                  "**","*---","-*-","*-**","--","-*","---","*--*",
                  "--*-","*-*","***","-","**-","***-","*--","-**-",
                  "-*--","--**"};
int main(void){

    int num;
    char ch,next;

    scanf("%d",&num);
    getchar();
    while(ch=getchar()){
        if(ch=='=')
            x+=1;
        else
            y+=1;
        if(x==1 && ch!='='){
            temp[Index]='*';
            Index++;
            x=0;
        }
        else if(x==3 && ch!='='){
            temp[Index]='-';
            Index++;
            x=0;
        }

        if(y==1 && ch!='.')
            y-=1;
        else if(y==3 && ch!='.'){
            //for(int i=0;i<Index;i++)
            //    printf("%c",temp[i]);
            for(int i=0;i<26;i++)
                if(strcmp(dict[i],temp)==0){
                    printf("%c",i+65);
                    break;
                }
            for(int i=0;i<Index;i++)
                temp[i]='\0';
            Index=0;
            y=0;
        }
        else if(y==7){
            //for(int i=0;i<Index;i++)
            //    printf("%c",temp[i]);
            for(int i=0;i<26;i++)
                if(strcmp(dict[i],temp)==0){
                    printf("%c",i+65);
                    break;
                }
            for(int i=0;i<Index;i++)
                temp[i]='\0';
            Index=0;
            printf(" ");
            y=0;
        }
        if(ch=='\n')
        {
            //for(int i=0;i<Index;i++)
            //    printf("%c",temp[i]);
            for(int i=0;i<26;i++)
                if(strcmp(dict[i],temp)==0){
                    printf("%c",i+65);
                    break;
                }
            break;
        }
    }
    printf("\n");
    return 0;
}