/***************************************
* EECS2031ON – Lab2 C
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include<stdio.h>

int isDigit(int c);

int main(int argc, char const *argv[])
{
    int numberArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int c = getchar();
    
    while(c!=EOF){
        if(isDigit(c)){
            numberArray[c -'0'] = numberArray[c -'0'] + 1; 
        }
        c = getchar();
    }
    
    int i;
    for(i=0; i<=9; i++){
        printf("%d: %d\n", i, numberArray[i]);  
    }

    return 0;
}

int isDigit(int c){
    if(c>='0' && c<='9'){
        return 1;
    }
    return 0;
}