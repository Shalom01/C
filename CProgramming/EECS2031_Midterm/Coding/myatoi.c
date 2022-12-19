/***************************************
* 21W EECS2031ON LabTest 1
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* EECS_username: shalom01
* York Student #: 215146954
****************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//more header files and declarations as needed

#define SIZE 10

//declaring functions prior to use.
int my_atoi (char c[]);
int isQuit(char string[]);
int isLetter(char c);
   
int main(int argc, char *argv[]){
  int a,b;
  char arr [SIZE];

  printf("Enter a word of positive number or 'quit': " );
  scanf("%s", arr);
  while(!isQuit(arr))
  {
    printf("%s\n", arr);

    a = atoi(arr);
    printf("atoi:    %d (%#o, %#X)\t%d\t%d\n", a,a,a, a*2, a*a);

    b = my_atoi(arr);
    printf("my_atoi: %d (%#o, %#X)\t%d\t%d\n", b,b,b, b*2, b*b);


    printf("\nEnter a word of positive number or 'quit': " );
    scanf("%s", arr); 
  }
  return 0;
}

/* convert an array of digit characters into a decimal int. 
   Input is either a valid Decimal or Octal or Hex integer literal.
*/

int my_atoi (char c[])
{
  int base, i; //the base value, and i to iterate.
  int end = 0; //where should we stop (down to what values should we ignore).
  if(c[0]=='0' && c[1]=='x'){ //if its hexadecimal.
    base = 16; //set the base to 16.
    end = 2; //our last stop is index 2. 
  }else if(c[0]=='0'){ //else if Octal.
    base = 8; //set base to 8.
    end = 1; //our last stop is index 1.
  }else{ //else, its decimal.
    base = 10;
    end = 0;
  }

  int value = 0;
  int position = 0;
  for(i = strlen(c) - 1; i>=end; i--){ //iterate downward the string until you reach the appropriate stopping point.
      if(base==16 && isLetter(c[i])){ //if were dealing with hex and we bump into a character, we need to find the corresponding digit value.
        if(c[i]=='A' || c[i]=='a'){
          value = 10*pow(base, position) + value;
        }else if(c[i]=='B' || c[i]=='b'){
          value = 11*pow(base, position) + value;
        }else if(c[i]=='C' || c[i]=='c'){
          value = 12*pow(base, position) + value;
        }else if(c[i]=='D' || c[i]=='d'){
          value = 13*pow(base, position) + value;
        }else if(c[i]=='E' || c[i]=='e'){
          value = 14*pow(base, position) + value;
        }else if(c[i]=='F' || c[i]=='f'){
          value = 15*pow(base, position) + value;
        }
      }else{
        value = (c[i] - '0')*pow(base, position) + value; //calculate the value.
      }

      position+=1; //increment the position (the location of the digit);
  }
  return value; //return the calculated value.
}

/*
*Helper method that determines if a string = "quit"
*/
int isQuit(char string[]){
  if(string[0]=='q' && string[1]=='u' && string[2]=='i'&& string[3]=='t' && string[4]=='\0'){
    return 1;
  }
  return 0;
}

/*
*Helper method that determines if a character is a letter. 
*/
int isLetter(char c){
  if((c >='a' && c<='z')|| (c>='A' && c<='Z')){
    return 1;
  }
  return 0;
}