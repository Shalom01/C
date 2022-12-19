/***************************************
* EECS2031ON – Lab5
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_num: shalom01
* Yorku #: 215146954
****************************************/
#include <stdio.h>

#define MAX_INPUT 20
 
// more headers and declarations as needed
void display(int *arr, int index);
int largest(int * arr, int index);

int main(int argc, char *argv[])
 {
     int array[MAX_INPUT], count;

     /* Input MAX_INPUT values from the keyboard. */
     int i;  count=0;
     
     while ( scanf("%d", &i) != EOF){
        *(array + count) = i;  // store in array[count] without using []
        count++;
     }
 
      /* Call the function and display the return value. */
      printf("Inputs: ");
      display(array, count);
     
     printf("\nLargest value: %d\n", largest(array, count));
     
     return 0;
 }
 
 /* display a int array */

 void display(int *arr, int index)
 {
    int i = 0;
    while(i!=index){
        printf("%d ", *(arr + i));
        i++;
    }
 }


/* Function largest() returns the largest value */
 /* in an integer array */

 int largest(int * arr, int index)
 {  
    int largest = *arr; 
    int i = 0;
    while(i!=index){
        if(largest<*(arr + i)){
            largest = *(arr + i);
        }
        i++;
    }
    return largest;
 }

