/***************************************
* EECS2031ON – Lab2 B
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include<stdio.h>

int isLowerCaseLetter(int c);

int main(int argc, char const *argv[])
{
   int c = getchar();

   while(c!=EOF){
       if(isLowerCaseLetter(c)){
           c -= 'a' - 'A';
       }
       putchar(c);
       c=getchar();
   }
    return 0;
}

int isLowerCaseLetter(int c){
    if(c>='a' && c<= 'z'){
        return 1;
    }
    return 0;
}

