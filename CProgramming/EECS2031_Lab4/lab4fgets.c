/***************************************
* EECS2031ON – Lab4
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>
#include<string.h>
#include<math.h>

#define SIZE 10
#define SIZE2 40

int main(int argc, char *argv[])
{
     char resu[SIZE2];
     char input[SIZE2];    
     char name[SIZE];  
     int age;
     float rate;
	
     printf("Enter name, age and rate (or \"exit\"): ");
     fgets(input, 40, stdin);
     while (strcmp(input, "exit\n")!=0)
     {    
       //output original input using two functions.
       printf("%s", input);  // no \n needed
       fputs(input, stdout); 
      
       // tokenize input
       sscanf(input, "%s %d %f", name, &age, &rate);

       rate = rate*2.0; //double the rate.
       if(name[0]>='a' && name[0]<='z'){  //capitalize the first letter.
         name[0] = name[0] - ('a'-'A');
       }

       sprintf(resu, "%s-%d-%.3f-[%.0f,%.0f]\n\n", name, age+10, rate, floor(rate), ceil(rate));  //build resu.
       printf(resu);  //print it.

      /* use fgets to read again */
      printf("Enter name, age and rate (or \"exit\"): ");
      fgets(input, 40, stdin);
     } 
    return 0;
}
