/***************************************
* EECS2031ON – Lab 6 lab6Dargv.c
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_num: shalom01
* Yorku #: 215146954
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getDiff(char *[], int);
int getSum(char *[], int);

int main(int argc, char *argv[]){
    printf("There are %d arguments (excluding \"a.out\")", argc - 1);
    if(strcmp(*(argv + 1), "sum")==0){
        int i = 2;
        printf("\n%d", atoi(argv[i++]));

        while(i<argc){
            printf(" + %d", atoi(argv[i++]));
        }
        printf("\n= %d", getSum(argv, argc));

    }else if(strcmp(*(argv + 1), "diff")==0){
        int i = 2;
        printf("\n%d", atoi(argv[i++]));

        while(i<argc){
            printf(" - %d", atoi(argv[i++]));
        }
        printf("\n= %d", getDiff(argv, argc));

    }
    return 0;
}

int getDiff(char * ptr [], int n){
    int i;
    int value = atoi(*(ptr + 2));
    for(i = 3; i < n; i++){
        value = value - atoi(*(ptr + i));
    }
    return value;
}
int getSum(char * ptr[], int n){
    int i;
    int value = atoi(*(ptr + 2));
    for(i = 3; i < n; i++){
        value += atoi(*(ptr + i));
    }
    return value;
}