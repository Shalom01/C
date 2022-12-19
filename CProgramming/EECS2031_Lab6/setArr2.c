/***************************************
* EECS2031ON – Lab 6 setArr2.c
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_num: shalom01
* Yorku #: 215146954
****************************************/
#include <stdio.h>

void setArr (int, int);

int * arr[10]; // array of 10 int pointers

int main(int argc, char *argv[])
{
     int i;
       
     setArr(0, -10);
     setArr(1, 100);
     setArr(2, 200);
     setArr(3, 300);
     setArr(4, 400);
       
        
     for(i=0; i<5;i++) 
        printf("arr[%d] -*-> %d %d\n", i, *arr[i], **(arr+i) );   /* should be -10,100, 200,300,400 */
     return 0;
}

/* set arr[index], which is a pointer, to point to an integer of value v */
void setArr (int index, int v){
     int i = v;
     arr[index] = &i;
}

/**********************************************PROBLEM II-B Explanation****************************************************************
 i in setArr is a local variable. The memory location of i will be deallocated when the function exits (when pushed off stack) and the value will be erased.
 When you try to access the location again in printf in main(), it will attempt to access the value at the
 address supplied by &i in setArr, but the value will no longer be there (it has been cleared), so it will output a garbage value.
 **************************************************************************************************************************************/
