/***************************************
* EECS2031ON lab2E
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* EECS_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>
#define SIZE 50    // assume no more than 50 literals in input
int main(){
 
  int c; //character being read
  float value = 0.0; //the value of the number
  float resu[SIZE]; //array to hold the numbers
  float position = 1.0; //float that determines the position of the digit
  int isFloating = 0; //0 if not a floating digit, 1 if floating digit
  int j = 0;
  int i;

  c = getchar(); //get the first character and store it as an int
  while (c != EOF){ 
  
    if (c == ' ' || c == '\n'){ //if the character is a blank or new line character
        resu[j] = value; //add the previous value to the array
        j++; //increment to the next spot in the array

        position = 1.0; //set the next number to the ones spot
        value = 0.0; //set the next value to zero
        isFloating = 0; //assume it's not floating
        c = getchar(); //get the next character
    }

    if(c =='.'){ //if c is a .
        c = getchar(); //get the next character
        isFloating = 1; //we are dealing with floating digits now
        position = 0.1;
    }

    if(c <='9' && c >='0'){ //if the character is a numerical value
        if(isFloating){
            value = value + ((float)(c -'0') * position);
            position = position/10.0;
        }else{
            value = (value * position) + (float) (c -'0');
            position = 10;
        }
    }

    c = getchar(); // read next
    if(c==EOF){
        resu[j] = value; //add the value to the array
    }
  }
 
  printf("--------\n");
  for(i=0; i<j; i++){
    printf("%.4f\t%.4f\n", resu[i], (resu[i] * 2.0)); 
  }
  return 0;
}