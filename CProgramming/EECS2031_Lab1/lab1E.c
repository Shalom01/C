#include <stdio.h>

void greet(int i){
   printf("Hello %d!\n", i);
}

/* function definition */
float sum (float i, float j){
   return i+j;             
}

int main()
{  
   int interactions=0;
   int i;
   float x;
   float y;

   int a = 2031;
   greet(a);

   printf("Enter the number of interactions: ");
   scanf("%d", &interactions);
   
   for(i=0;i<interactions;++i){
      printf("Enter two float numbers separated by ##: ");
      scanf("%f##%f", &x, &y);
      float su= sum(x,y);
      printf( "%f + %f = %f\n", x,y, su);
   }
 
   return 0;
}