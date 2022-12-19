/***************************************
* EECS2031ON – Lab5
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_num: shalom01
* Yorku #: 215146954
****************************************/

#include <stdio.h>
#include <math.h>

double my_pow(double base, double power);

int main(int argc, char *argv[])
{
	
   double base; 
   int exponent;  
   printf("enter base and power: ");
   scanf("%lf %d", &base, &exponent);

   while (base != -1000){
        double res = pow(base, exponent);
        double res2 = my_pow(base, exponent);
        printf("pow:    %.4f\n", res);
        printf("my_pow: %.4f\n", res2);

        printf("enter base and power: ");
        scanf("%lf %d", &base, &exponent);
    }
    return 0;
}

// this function should be RECURSIVE
// should not use any loop here
double my_pow(double base, double power)
{     
     if(power==0){ //base case.
          return 1;
     }

     if(power<0){ //if the power is negative.
               return (1/base)*my_pow((1/base), -power - 1);
     }

     return base*my_pow(base, power - 1);
}
