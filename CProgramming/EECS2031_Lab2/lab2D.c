/***************************************
* EECS2031ON – Lab2 D
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>
#define SIZE 50    // assume no more than 50 literals in input
int main(){
 
  int c;
  int value = 0;
  int resu[SIZE];
  int negative = 0;
  int position = 1;
  int j = 0;
  int i;

  c = getchar();
  while ( c != EOF){
  
    if (c == ' ' || c == '\n'){
        if(negative){ //if the value is negative
            value*=-1;
        }

        resu[j] = value; //add the value to the array
        j++; //increment to the next spot

        position = 1; //set the next number to the ones spot
        value = 0; //set the next value to zero
        negative = 0; //assume non-negative, unless told otherwise
        c = getchar(); //get the next character
    }

    if(c=='-'){ //if the number is preceded by a '-', set the value to be a negative value and skip to the next character.
        c = getchar(); 
        negative = 1;
    }

    if(c<='9' && c>='0'){ //if the character is a numerical value
        value = (value * position) + (c -'0'); //add it to the value in its correct digit position
        position = 10; //if it's not the first value, keep multiplying by 10.
    }

    c = getchar(); // read next
    if(c==EOF){
        resu[j] = value; //add the value to the array
    }
  }
 
  printf("--------\n");
  
  for(i=0; i<j; i++){
    printf("%d\t%d\n", resu[i], resu[i] * 2); 
  }
   
  return 0;
}