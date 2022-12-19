/***************************************
* EECS2031ON – Lab4
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include<stdio.h>
#include<string.h>

#define SIZE 30

void my_strcat(char a[], char b[]);

int main(){
   char a[SIZE];
   char b[SIZE];
   char c[SIZE];
   char d[SIZE];

   scanf("%s",a);
   scanf("%s",b);
   while (strcmp(a, "xxx") || strcmp(b, "xxx")){
    
      strcpy(c,a); strcpy(d,b);

      strcat(a,b);
      my_strcat(c,d);
      
      printf("strcat:   %s\n", a); 
      printf("mystrcat: %s\n\n", c);

      scanf("%s",a);
      scanf("%s",b);
   }

   return 0;
}


void my_strcat(char a[], char b[]){

   int i=0;
   int j=0;

   //get the index of '\0' in a.
   while(a[i]!='\0'){
     i++;
   }

   //merge b into a.
   while(b[j]!='\0'){
      a[i]=b[j];
      j++;
      i++;
   }

   a[i]=b[j]; //put the '\0' at the end.
}
