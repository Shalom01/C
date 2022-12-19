/***************************************
* EECS2031ON – Lab4
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>
extern int count, sum, input;
extern double resu;
extern void r_avg();

int main(int argc, char *argv[])
{
    printf("Enter number (-1 to quit): ");
    scanf("%d", &input);
	
    while(input != -1){	
      r_avg();
      printf("\nEnter number (-1 to quit): ");
      scanf("%d", &input);
     }
     return 0;
}

