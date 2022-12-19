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
void largest(int * arr, int index, int* biggest);

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
    int biggest = *array; //set the biggest value to be the first one in the array.
    printf("Inputs: ");
    display(array, count);
    largest(array, count, &biggest); //we can pass the address of the value to modify it.
    printf("\nLargest value: %d\n", biggest);
     
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

void largest(int * arr, int index, int *biggest)
 {  
    int i = 0;
    while(i!=index){ //iterate until the given index.
        if(*biggest<*(arr + i)){ //if the value that biggest points to is less than the value at that point in the *arr.
            *biggest = *(arr + i); //set the value of biggest to be the value at that point.
        }
        i++;
    }
 }

