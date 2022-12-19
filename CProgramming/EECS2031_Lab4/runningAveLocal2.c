/***************************************
* EECS2031ON – Lab4
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>

void r_avg(int);

int main(int argc, char *argv[])
{
	
   int input;  
   printf("Enter number (-1 to quit): ");
   scanf("%d", &input);

   while (input != -1){
        r_avg(input);

        printf("\nEnter number (-1 to quit): ");
        scanf("%d", &input);
    }
	
    return 0;
}

void r_avg(int input)
{
    static int count;
    static int sum;

    sum+=input;
    count++;

    double resu = 1.0*sum/count;
    printf("running average is %d / %d = %.3f\n", sum, count, resu);     
}
