#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
bool check(char*,char*);
void to_upper(char*);
int main () {
   char key[21],str[10001];
   const char *s = "-/:()[],.";
   char *token;
   int total=0;
   
   scanf("%s",key);
   to_upper(key);
   while(scanf("%s",str)!=-1){
      token = strtok(str, s);
      while( token != NULL ) {
         if(check(key,token))
            total++;
         token = strtok(NULL, s);
      }
   }
   printf("%d\n",total);
   return(0);
}
void to_upper(char* ch){

   for(int i=0;ch[i]!='\0';i++)
      ch[i] = toupper(ch[i]);
}
bool check(char* key,char* str){

   bool flag = true;
   if(strlen(key)!=strlen(str))
      return false;
   for(int i=0;key[i]!='\0';i++){
      if(key[i]!=toupper(str[i])){
         flag = false;
         break;
      }
   }
   return flag;
}