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
void display(int *arr);
int largest(int * arr);

int main(int argc, char *argv[])
 {
     int array[MAX_INPUT], count;

     /* Input MAX_INPUT values from the keyboard. */
     int i;  count=0;
     
     while ( scanf("%d", &i) != EOF){
        *(array + count) = i;  // store in array[count] without using []
        count++;
     }

     *(array + count) = -1; //set the last value to be a unique value (i.e. -1), because >=0 precondition;
 
      /* Call the function and display the return value. */
      printf("Inputs: ");
      display(array);
     
     printf("\nLargest value: %d\n", largest(array));
     
     return 0;
 }
 
 /* display a int array */

 void display(int *arr)
 {
    int i = 0;
    while(*(arr + i)>=0){
        printf("%d ", *(arr + i));
        i++;
    }
 }


/* Function largest() returns the largest value */
 /* in an integer array */

 int largest(int * arr)
 {  
    int largest = *arr; 
    int i = 0;
    while(*(arr + i)>=0){
        if(largest<*(arr + i)){
            largest = *(arr + i);
        }
        i++;
    }
    return largest;
 }

