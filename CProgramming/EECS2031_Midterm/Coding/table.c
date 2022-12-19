/***************************************
* 21W EECS2031ON LabTest 1
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* EECS_username: shalom01
* York Student #: 215146954
****************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
//more header files and declarations as needed

#define ROWs 40
#define COLs 50

//declaring functions prior to use.
void removeLetter(char string[], char letter);
void setNextLetter(char string[]);
char greatestChar(char string[]);

int main(int argc, char *argv[])
{
     char table[ROWs][COLs];  /* 2D array to store lines of input */
     int row = 0; int i;
     float rate; char word1[COLs]; char word2[COLs]; char word1copy[COLs]; char letter; char lexValue; char biggestChar;
	
     printf("Enter rate~~word1 letter word2: ");
     fgets(table[row], 50, stdin);   // use fgets to read in whole line. You can move this line into while loop if you like. 
     
     while (strcmp(table[row], "quit\n")!=0) //including \n because using fgets.   
     {
      sscanf(table[row], "%f~~%s %c %s", &rate, word1, &letter, word2); //parse it using sscanf.
      biggestChar = greatestChar(word2); //get the biggest lexicographical character from word2 (i.e. Bonus Marks)
      if(strcmp(word1, word2)<0){ //compare the words, and set the lexValue accordingly, not we assume words never the same.
            lexValue = '<';
      }else{
            lexValue = '>';
      }

      //copy world1
      for(i=0; word1[i]!='\0'; i++){
            word1copy[i] = word1[i];
      }
      word1copy[i] = '\0';

      setNextLetter(word1); //set ever letter to next one
      removeLetter(word1copy, letter); //replace every instance of letter with *
      rate*=1.6; //increase the rate by an additional 60%

      sprintf(table[++row], "%s--%s--[%.4f...%d...%d] %c '%c'\n", word1, word1copy, rate, (int) floor(rate), (int) ceil(rate), lexValue, biggestChar); //format it and put into table.
      sprintf(table[++row], "xxx\n"); //add the xxx into the table.

      printf("Enter rate~~word1 letter word2: ");
      fgets(table[++row], 50, stdin);   // use fgets to read in whole line. You can move this line into while loop if you like. 
     }
     
     /* output number of rows stored   */
     printf("\nTotally %d rows are stored\n", row);

     /* output the stored rows of the table */
      for(i=0; i<row; i++){
            printf("[%d]: %s", i, table[i]);
      }   
	
       return 0;
}

/*
 *Helper method that sets every letter in a char array to the next one.
 */
void setNextLetter(char string[]){
      int i = 0;
      while(string[i]!='\0'){
            if(string[i]=='z'){
                  string[i]='a';
            }else if(string[i]=='Z'){
                  string[i]='A';
            }else{
                  string[i] = string[i] + 1;
            }
            
            i++;
      }
}
/*
 *Helper method that replaces every instance of letter in a char array with '*'.
 */

void removeLetter(char string[], char letter){
      int i = 0;
      while(string[i]!='\0'){
            if(string[i]==letter){
                  string[i]='*';
            }
            i++;
      }
}

/*
 *Helper method that returns the greatest char in a char array.
 */
char greatestChar(char string[]){
  int i=0;
  char maxChar = 'a';
  while(string[i]!='\0'){
    if(string[i]>maxChar){
      maxChar = string[i];
    }
    i++;
  }
  return maxChar;
}