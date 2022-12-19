/***************************************
* EECS2031ON – Lab4
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int age = 10;
    int age2 = 100;
    int *ptr = &age;

    printf("age: %d %d\n", age, *ptr);

    *ptr = 14;
    printf("age: %d %d\n", age, *ptr);

    int *ptr2 = &age2;
    printf("age2: %d %d\n", age2, *ptr2);

    *ptr2 = *ptr * 3;
    printf("age2: %d %d\n", age2, *ptr2);

    ptr2 = ptr; //setting the references to be the same.
    printf("ptr2's current pointee: %d\n", *ptr2);
    printf("age: %d %d %d\n", age, *ptr, *ptr2);

    *ptr2 = *ptr2 -1; //changing the pointee of ptr2 (which will change all values).
    printf("age: %d %d %d\n", age, *ptr, *ptr2);
    printf("%p %p %p\n", &age, ptr, ptr2);  //by putting ptr and ptr2 directly, we display the value of the poitner variable itself.

    return 0;
}
