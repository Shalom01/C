/***************************************
* EECS2031ON – Lab5
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_num: shalom01
* Yorku #: 215146954
****************************************/
#include <stdio.h>
#include <string.h>

#define SIZE 40

//... more headers and declarations as needed
int isPalindrome (char * str);
void printReverse(char * str);
int isPalindromeR(char * str); //BONUS: Recursive implementation of isPalindrome.
int isPalindromeRHelper(char * str, int first, int last); //Helper function for bonus that passes along indexes.

int main ()
{   
   int result;  char c; int i;  int count=0;
   char arr[SIZE];
  
   fgets(arr,SIZE,stdin);
   while (strcmp("quit\n", arr)!=0)
   {
      int i=0;
      while(arr[i]!='\n'){
         i++;
      }

      arr[i]='\0';
      
	  // print backward
      printReverse(arr);
   
      if (isPalindrome (arr)) 
         printf ("\nIs a palindrome.\n\n");
      else 
         printf ("\nNot a palindrome.\n\n");
      fgets(arr,SIZE,stdin);
   }
   return 0;
}


// assume the \n was already removed manually
int isPalindrome (char * str)
{
   int lastIndex = 0;
   while(*(str + lastIndex)!='\0'){ //find the lastIndex;
      lastIndex++;
   }
   lastIndex--; //got the lastIndex.
   int firstIndex = 0;

   while(firstIndex<lastIndex){
      if(*(str + firstIndex)!=*(str + lastIndex)){
         return 0;
      }
      firstIndex++;
      lastIndex--;
   }
   return 1;
}

int isPalindromeR(char * str){
   int lastIndex = 0;
   while(*(str + lastIndex)!='\0'){
      lastIndex++;
   }
   lastIndex--; //got the lastIndex.

   return isPalindromeRHelper(str, 0, lastIndex);
}

int isPalindromeRHelper(char * str, int first, int last){
   if(last<=first){ //base case.
      return 1;
   }

   if(*(str + first) != *(str + last)){ //if at any stage, the mirror characters don't match.
      return 0;
   }

   return isPalindromeRHelper(str, first + 1, last - 1); //recursive call.
}

// assume the \n was already removed manually
void printReverse(char * str)
{
   int index = 0;
   while(*(str + index) != '\0'){
      index++;
   }
   index--;

   do
   {
      printf("%c", *(str + index));
      index--;
   } while (index>=0);
}