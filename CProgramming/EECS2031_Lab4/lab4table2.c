/***************************************
* EECS2031ON – Lab4
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ROWS 20
#define COLUMNS 30

int main(int argc, char *argv[])
{
     char input_table[ROWS][COLUMNS];
     int current_row=0;
     char name [10]; int age; float rate;
  	
     printf("Enter name, age and rate: ");
     fgets(input_table[current_row], 30, stdin);   // read into table directly. add a \n.  Don't change this line
     sscanf(input_table[current_row], "%s %d %f", name, &age, &rate); //retrieve the name, age and rate from the input.
	
     while(strcmp(name, "xxx")!=0)
     {
      int j;
      for(j=0;name[j]!='\0';j++){  //capitalize the name.
          name[j]=toupper(name[j]);
      }

      sprintf(input_table[++current_row], "%s %d %.2f\n", name, age+10, rate*1.5);   //put the updated string into the next row in the array.
      current_row++;     //increment for the next input.

      printf("Enter name, age and rate: ");
      fgets(input_table[current_row], 30, stdin);   // read into table directly. add a \n.  Don't change this line
      sscanf(input_table[current_row], "%s %d %f", name, &age, &rate);     //retrieve the name, age and rate from the input.
     }

     printf("\nRecords generated in %s on %s %s\n", __FILE__, __DATE__, __TIME__);
     int j;
     for(j=0; j<current_row; j++){
          printf("row[%d]: %s", j, input_table[j]);
     }

     return 0;
}

