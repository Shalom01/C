/***************************************
* EECS2031ON – Lab 6 setArr3.c
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_num: shalom01
* Yorku #: 215146954
****************************************/
#include <stdio.h>
#include <stdlib.h>

void setArr (int, int);

int * arr[10]; // array of 10 int pointers, global variable

int main(int argc, char *argv[])
{
     int i;
       
     setArr(0, -10);
     setArr(1, 100);
     setArr(2, 200);
     setArr(3, 300);
     setArr(4, 400);
       
        
     for(i=0; i<5;i++) 
        printf("arr[%d] -*-> %d %d\n", i, *arr[i], **(arr + i) );   /* should be -10,100, 200,300,400 */
     return 0;
}

void setArr (int index, int v){
     arr[index] = (int*) malloc(sizeof(int)); //allocate dynamic memory for addresses in arr[index].
     *arr[index] = v; //set the value of the dynamic adresses (by *arr[index]) to point to the value of v.
}