/***************************************
* EECS2031ON – Lab3
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>
#include <string.h> //for strlen() function
#include <stdlib.h>  // for atoi

#define SIZE 10
 
int my_atoi (char c[], int base);
int power(int base, int n);

int main(){
  int a, base;
  char arr [SIZE];

  printf("Enter a word of positive number and base, or 'quit': " );
  scanf("%s %d", arr, &base);
  while(strcmp(arr, "quit")!= 0)
  {
    printf("%s\n", arr);
    a = my_atoi(arr, base);
    printf("my_atoi: %d (%#o, %#X)\t%d\t%d\n", a,a,a, a*2, a*a);
    printf("\nEnter a word of positive number and base, or 'quit': " );
    scanf("%s %d", arr, &base);
  }
  return 0;
}

/* convert an array of digit characters into a decimal int */

/* textbook did scan from left to right.
 Here you should scan from right to left. This is a little complicated 
 but more straightforward (IMHO) */

int my_atoi (char c[], int base)
{
    int i;
    int value = 0;
    int position = 0;
    for(i = strlen(c) - 1; i>=0; i--){
        value = (c[i] - '0')*power(base, position) + value;
        position+=1;
    }
    return value;
}

int power(int base, int n)
{ int value = 1;
  int i;
  for(i=1; i<=n; i++){
    value = value * base;
  }
  return value;
}
