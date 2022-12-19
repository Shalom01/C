#include <stdio.h>
#include <string.h>

#define SIZE 12

int main (){
   char str[SIZE];
   int i;
   for(i=0; i<SIZE; i++)
      printf("[%d] %c %d\n",i,str[i], str[i]); //print the location in the array, the character and the ASCII representation of the character
    printf("\n");


   scanf("%s", str);

   while ( str != "quit"){ 
    for(i=0; i<SIZE; i++)
      printf("[%d] %c %d\n",i,str[i], str[i]);

    printf("%s  %d  %d\n\n", str, sizeof str,strlen(str));

    scanf("%s", str); // read again
  }     
   return 0;
}
