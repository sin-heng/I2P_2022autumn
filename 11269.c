#include <stdio.h>
#include<string.h>
#define MAX_SIZE 500
char content[MAX_SIZE];
char input[MAX_SIZE];
int main()
{
    /* your code here */
    //分別記住四種字串的長度
    int len_back = strlen("/backspace");
    int len_left = strlen("/left");
    int len_right = strlen("/right");
    int len_new = strlen("/newline");

    int in_con=0;//用來記住content的位置，充當游標的角色

    while(fgets(input, MAX_SIZE, stdin)){//當讀入不為ctrl-z則繼續
        int length = strlen(input);//記住每次輸入的長度
        for(int i=0;i<length;i++){
            if(input[i]=='\n')//輸入內有'\n'則跳過
                continue;
            if(input[i]=='/'){//輸入內有'/'則檢查下一個字母
                if(input[i+1]=='b'){//backspace
                    i+=len_back-1;//跳過'/backspace'的長度，但因為之後會i++，所以要-1
                    if(in_con>=1)//確保content的游標沒超越左邊界
                        in_con--;
                    content[in_con] = ' ';
                }
                else if(input[i+1]=='l'){//left
                    i+=len_left-1;//跳過'/left'的長度
                    if(in_con>=1)//確保content的游標沒超越左邊界
                        in_con--;
                }
                else if(input[i+1]=='n'){//newline
                    i+=len_new-1;//跳過'/newline'的長度
                    content[in_con] = '\n';
                    in_con++;
                }
                else if(input[i+1]=='r'){//right
                    i+=len_right-1;//跳過'/right'的長度
                    if(in_con<500)//確保content的游標沒超過右邊界
                        in_con++;
                }
            }
            else{//除卻以上五種情況，其餘都直接加入content
                content[in_con] = input[i];
                in_con++;
            } 
        }
    }
    printf("%s", content);
    return 0;
}