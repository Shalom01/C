#include <stdio.h>
#include <string.h>

#define SIZE 12

int main (){
   char str[SIZE];
   int i;
   for(i=0; i<SIZE; i++)
      printf("[%d] %c %d\n",i,str[i], str[i]);
    printf("\n");

   printf("strcpy(str,\"Good\")\n");
   strcpy(str, "Good");
   strncpy(str, "Good", 1);
   
   for(i=0; i<SIZE; i++)
      printf("[%d] %c %d\n",i,str[i], str[i]);
   printf("%s\nsize:%d  length:%d\n\n", str, sizeof str,strlen(str));

   printf("strcpy(str,\"Morning\")\n");
   strcpy(str, "Morning");
   for(i=0; i<SIZE; i++)
      printf("[%d] %c %d\n",i,str[i], str[i]);
   printf("%s\nsize:%d  length:%d\n\n", str, sizeof str,strlen(str));

   printf("strncpy(str,\"XYZUVW\", 3)\n");
   strncpy(str, "XYZUVW", 3); // copy XYZ but no \0
   for(i=0; i<SIZE; i++)
      printf("[%d] %c %d\n",i,str[i], str[i]);
   printf("%s\nsize:%d  length:%d\n\n", str, sizeof str,strlen(str));
   
   //now try strcat, start from strcpy
   printf("strcpy(str,\"AB\")\n");
   strcpy(str, "AB" ); // copy XYZ but no \0
   for(i=0; i<SIZE; i++)
      printf("[%d] %c %d\n",i,str[i], str[i]);
   printf("%s\nsize:%d  length:%d\n\n", str, sizeof str,strlen(str));

   printf("strcat(str,\"OK\")\n");
   strcat(str, "OK");
   for(i=0; i<SIZE; i++)
      printf("[%d] %c %d\n",i,str[i], str[i]);
   printf("%s\nsize:%d  length:%d\n\n", str, sizeof str,strlen(str));


   printf("strncat(str,\"BYEBYE\", 1)\n");
   strncat(str, "BYEBYE",1);
   for(i=0; i<SIZE; i++)
      printf("[%d] %c %d\n",i,str[i], str[i]);
   printf("%s\nsize:%d  length:%d\n\n", str, sizeof str,strlen(str));

   
   printf("strncat(str,\"BYEBYE\"),2 \n");
   strncat(str, "BYEBYE",2);
   for(i=0; i<SIZE; i++)
      printf("[%d] %c %d\n",i,str[i], str[i]);
   printf("%s\nsize:%d  length:%d\n\n", str, sizeof str,strlen(str));

   return 0;
}
