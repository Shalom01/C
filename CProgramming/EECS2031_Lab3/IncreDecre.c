#include <stdio.h>
 
int main()
{
 int i=1;
 i++; 
 printf("i is %d\n", i);

 i=1;
 ++i;
 printf("i is %d\n------------\n", i);

 i=1;
 printf("i is %d\n", i++);
 printf("i is %d\n-----\n",i);
 
 i=1;
 printf("i is %d\n", ++i);
 printf("i is %d\n-------------\n",i);
 
 i=1;
 int y = i++;
 printf("i is %d, y is %d\n", i, y);

 i=1;
 y = ++i;
 printf("i is %d, y is %d\n-------------\n", i, y);

 // use ++ -- to make code succlent
 int arr[10];
 int k=0; int v=100;
 while (k<10)
   arr[k++] = v--;   // instead of arr[k]=v; k++; v--;

 int index;
 for(index=0; index<10; index++)
    printf("arr[%d]: %d\n", index,arr[index]);

 return 0;
}

