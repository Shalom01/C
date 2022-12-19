/***************************************
* EECS2031ON – Lab 6 lab6B.c
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_num: shalom01
* Yorku #: 215146954
****************************************/

// Inputs a list of strings from the keyboard, sorts t
 /* and then displays them on the screen. */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

 #define MAXLINES 30
 #define MAXCOLS  50 


 void print2D(char p[][MAXCOLS], int n);
 void exchange2D(char p[][MAXCOLS], int i, int j);
 void sort2D(char p[][MAXCOLS], int n);
 
 int main()
 {
     char inputs[MAXLINES][MAXCOLS];
     printf("sizeof inputs: %d\n\n", sizeof inputs);
 
     /* Read in the lines from the keyboard, using fgets */
    
    int i = 0;
    
    printf("Enter string: ");
    fgets(inputs[i], MAXCOLS, stdin);

    while(strcmp(inputs[i], "xxx\n")!=0){
        i++;
        printf("Enter string: ");
        fgets(inputs[i], MAXCOLS, stdin);
    }
    
    printf("\n");
     
     // display the array by calling print2D( ..)

     print2D(inputs, i);

     // swap the first and second row here
     char temp [MAXCOLS];
     strcpy(temp, inputs[0]);
     strcpy(inputs[0], inputs[1]);
     strcpy(inputs[1], temp);

     // call exchange2D() to swap some other rows
     exchange2D(inputs, 2, 3);

     printf("\n== after swapping ==\n");
    
     // display the swapped array by calling print2D() 
     print2D(inputs, i);

    
     // call sort2D to sort
     sort2D(inputs, i);

     printf("\n== after sorting ==\n");

     // display the sorted array by calling print2D()
	 print2D(inputs, i);
     
     return 0;
 }


 // do exchange, have to involve data movement 
 void exchange2D(char p[][MAXCOLS], int i, int j)
 {
     char temp [MAXCOLS];
     strcpy(temp, p[i]);
     strcpy(p[i], p[j]);
     strcpy(p[j], temp);
 }

 // do exchange, have to involve data movement 
 void sort2D(char p[][MAXCOLS], int n)
 {  
     char value [MAXCOLS];
     int i; 
     int j;
     int index;
     for(i = 0; i < n; i++){
         strcpy(value, p[i]);
         index = i;
         for(j = i - 1; j>=0; j--){
             if(strcmp(value, p[j]) < 0){
                exchange2D(p, index, j);
                index = j;
             }
         }
     }
 }

 void print2D(char p[][MAXCOLS], int n)
 {
     int i;
     for(i = 0; i < n; i++){
        printf("[%d]: %s", i, p[i]);
     }
 }                        

