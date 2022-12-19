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
    char inputs_table [ROWS][COLUMNS];
    char name[10]; char ageS[10]; char rateS[10];
    int age; float rate; int rows = 0;
		
    printf("Enter name, age and rate: ");
    scanf("%s %s  %s", name, ageS, rateS);
       
    while (strcmp(name, "xxx")!=0)    
    {
        sprintf(inputs_table[rows++], "%s %s %s", name, ageS, rateS);

        int j;
        for(j=0; name[j]!='\0'; j++){
            name[j]=toupper(name[j]);
        }
    
        sprintf(inputs_table[rows++], "%s %d %.2f", name, atoi(ageS)+ 10, atof(rateS)*1.5);

       /* read again using scanf(%s %s %s) */
       printf("Enter name, age and rate: ");
       scanf("%s %s  %s", name, ageS, rateS);
    }
    
    printf("\nRecords generated in %s on %s %s\n", __FILE__, __DATE__, __TIME__);
    int i;
    for(i=0; i<rows;i++){
        printf("row[%d]: %s\n", i, inputs_table[i]);
     }
     return 0;
}