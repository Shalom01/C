/***************************************
* EECS2031ON – Lab4
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>

// define global variables and a function
int count=0;
int sum=0;
int input;
double resu;

void r_avg (void)
{   
    ++count;
    sum+=input;
    resu = 1.0*sum/count;
    printf("running average is %d / %d = %.3f\n",  sum, count, resu);
}

