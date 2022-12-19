/***************************************
* EECS2031ON – Lab3
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include<stdio.h>

int isDivisible(int numer, int denom);

int main(){
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    while(year>=0){
        if((isDivisible(year, 4) && !isDivisible(year, 100))|| isDivisible(year, 400)){
            printf("Year %d is a leap year\n", year);
        }else{
            printf("Year %d is not a leap year\n", year);
        }
        printf("\nEnter a year: ");
        scanf("%d", &year);
    }
    return 0;
}

int isDivisible(int numer, int denom){
    if(numer%denom == 0){
        return 1;
    }
    return 0;
}