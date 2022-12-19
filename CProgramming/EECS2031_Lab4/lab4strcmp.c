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

int my_strcmp(char a[], char b[]);

int main(){
   char a[SIZE];
   char b[SIZE];
   
   scanf("%s", a); 
   scanf("%s",b);

   while (strcmp(a, "xxx") || strcmp(b, "xxx")){
      int resu = strcmp(a,b); 
      if (resu < 0) 
         printf("strcmp:   \"%s\" appears earlier in dictionary than \"%s\"\n", a,b);
      else if (resu > 0) 
         printf("strcmp:   \"%s\" appears later in dictionary than \"%s\"\n", a,b);
      else 
         printf("\"%s\" and \"%s\" are same\n", a, b);
      
      int resu2 = my_strcmp(a,b);
      if (resu2 < 0) printf("mystrcmp: \"%s\" appears earlier in dictionary than \"%s\"\n\n", a,b);
      else if (resu2 > 0) printf("mystrcmp: \"%s\" appears later in dictionary than \"%s\"\n\n", a,b);
      else printf("\"%s\" and \"%s\" are same\n\n", a,b);

      scanf("%s", a); 
      scanf("%s",b);
   }
}


int my_strcmp(char a[], char b[]){

   int i=0;

   while(a[i]!='\0' && b[i]!='\0'){ //while we havn't reached the null character
      if(a[i]>b[i]){ //if a is lexicographically after b
         return 1;
      }else if(a[i]<b[i]){ //if a is lexicographically before b
         return -1;
      }
      i++;
   }

   if(a[i]=='\0' && b[i]=='\0'){ //if they both have the same size
      return 0;
   }else if(a[i]=='\0'){   //if a is shorter
      return -1;
   }
   return 1;   //if a is longer
}
