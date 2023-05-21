//NTHU Online Judge
//Yang Mid 13633 Identation   
#include<stdio.h>
int main(void){

    char ch,pre;
    int mode=0;
    /*
    mode0: #include<stdio.h>
    mode1: indentation
    mode2: }
    mode3: regular cases
    */
    while((ch=getchar())!=EOF)
    {
        if(mode==0)
        {
            if(ch=='\n')mode=1;
        }
        else if(mode==1)
        {
            if(ch=='#')mode=0;
            else if(ch==';') ch=' ';
            else if(ch=='}') mode=2;
            else mode=3;
            
        }
        else if(mode==2)
        {
            if(ch=='\n') mode=1;
        }   
        else if(mode==3)
        {
            if(ch=='\n')
            {
                if(pre!='{'){putchar(';');}
                mode =1;
            }
        }
        putchar(ch);
        pre=ch;
    }
    return 0;
}
