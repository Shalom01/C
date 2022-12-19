/***************************************
* EECS2031ON – Lab3 
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>

#define MAX_SIZE 20

int length(char arr[]);
int indexOf(char arr[], char c);
int occurrence(char arr[], char c);
int isQuit (char arr[]);

int main() {
   char word[MAX_SIZE];
   char c;

   char helloArr[]  = "helloWorld";
   printf("\"%s\" contains %d characters, but the size is %d (bytes)\n", helloArr, length(helloArr), sizeof(helloArr));
   helloArr[5] = '\0'; helloArr[3]='X'; helloArr[7] ='Y';
   printf("\"%s\" contains %d characters, but the size is %d (bytes)\n\n", helloArr, length(helloArr), sizeof(helloArr));


   /********** Fill in your code here. **********/
   printf("Enter a word and a character separated by blank: ");
   scanf("%s %c", word, &c);

   while (isQuit(word)!=1)   
   {  
      printf("Input word is \"%s\". Contains %d characters\n", word, length(word));
      printf("'%c' appears %d times in the word\nIndex of '%c' in the world is %d\n\n", c, occurrence(word, c), c, indexOf(word, c));
      printf("Enter a word and a character separated by blank: ");
      scanf("%s %c", word, &c);
   }

   return 0;
}

int length(char arr[])
{ 
   int length = 0;
   char c = arr[length];
   while(c!='\0'){
      length++;
      c = arr[length];
   }
   return length;
}

int indexOf(char arr[], char c)
{
   int i=0;
   char character = arr[i];
   while(character!='\0'){
      if(c==character){
         return i;
      }
      character = arr[++i];
   }

   return -1;
}

int occurrence(char arr[], char c)
{  int count = 0;
   int index = 0;
   char character = arr[index];
   while(character!='\0'){
      index++;
      if(c==character){
         count++;
      }
      character = arr[index];
   }
   return count;
}

int isQuit (char arr[])
{
   if (arr[0]=='q' && arr[1]=='u' && arr[2]=='i' && arr[3]=='t' && arr[4]=='\0'){
      return 1;
   }
   return 0;
}