/***************************************
* EECS2031ON – Lab4
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>

void r_avg(int, int);


int main(int argc, char *argv[])
{
	
      int input; int count=0; int sum=0;
      

      printf("Enter number (-1 to quit):  ");
      scanf("%d", &input);

      while(input != -1)
      {
         ++count; //inrement the count.
         sum+=input; //add the input to the sum.
         r_avg(sum, count);

         printf("\n\nEnter number (-1 to quit):  ");
         scanf("%d", &input);
       }  
	
       return 0;
}

void r_avg(int sum, int count)
{
   double resu = 1.0*sum/count;
   printf("running average is %d / %d = %.3f", sum, count, resu);   
}
