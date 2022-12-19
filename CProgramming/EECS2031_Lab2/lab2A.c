/***************************************
* EECS2031ON – Lab2 A
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/

#include<stdio.h>

int isDigit(int c);
int isLetter(int c);


int main(int argc, char const *argv[])
{   
    int value;
    char character;
    printf("Enter an integer and a character separated by a blank: ");
    scanf("%d %c", &value, &character);

    while(value != -1000){

        if(isDigit(character)){
            int sum = character - '0' + value; 
            printf("Character '%c' represents a digit. Sum of %c and %d is %d\n", character, character, value, sum);
        }else if(isLetter(character)){
            printf("Character '%c' represents a letter.\n", character);
        }else{
            printf("Character '%c' represents others.\n", character);
        }

        printf("\nEnter an integer and a character separated by a blank: ");
        scanf("%d %c", &value, &character);
    }

    return 0;
}

int isDigit(int c){
    if(c<='9' && c>='0'){
        return 1;
    }
    return 0;
}

int isLetter(int c){
    if((c>='a' && c<='z') || (c>='A' && c<='Z')){
        return 1;
    }
    return 0;
}

