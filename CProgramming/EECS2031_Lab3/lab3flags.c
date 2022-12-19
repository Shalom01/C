/***************************************
* EECS2031ON – Lab2 D
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>

#define SIZE 16
void printBinary(short int);

/*counting digits*/

int main () {
  int c, i,index;
  short flags = 0;
  printf("flags: ");printBinary(flags); printf("\n\n");

  while ((c = getchar()) != EOF){
   if (c<='9' && c>='0'){  // if c is a digit with numerical value x, turn bit x of flags on
      index = 1 << c-'0'; //set the value to 1 (the LSB becomes 1), and then shift it the appropriate amount of times to the left.
      flags = flags | index; //turn the value on in the flag.
   } 
  
  }
  printf("\nflags: "); printBinary(flags); printf("\n");

  // output  by checking the lower 10 bits one by one
  // hint: at least two apporches for this.
  // you can use one idiom mentioned in lab manual, or get hint 
  // from the printBinary() function below.
  for(i=0; i<=9; i++)  {
    int check = (flags>>i) & 1;    // is bit i is on or off, i.e., 0 or 1?
    if ( check  )    // check == 1
      printf("%d: %s\n", i, "yes");
    else printf("%d: %s\n", i, "no");
  } 

 return 1;  
  

 }

void printBinary(short int n ){
   //printf("binary: ");
   int cou = SIZE-1;
   int k[SIZE]={0};

   while (n) {
      if (n & 1)
         k[cou]=1; //printf("1");
      else
         k[cou]=0; //printf("0");

      n >>= 1; 
      cou--;
   }
   int i=0;
   for(; i< SIZE;i++)
   {
      printf("%d", k[i]);
      if ((i+1)%8==0)
      {
         printf(" ");
      }
   }
}