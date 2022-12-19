#include <stdio.h>
#include <stdlib.h>

#define MY_PRINT(x,y) printf("%d -> %d\n", x,y)

#define SQUARE(x)  (x) * (x)


int main(int argc, char *argv[])
{
    int i=7; 
    int j = 8;

    int resu = SQUARE(i);
    MY_PRINT(i, resu);

    resu = SQUARE(j);
    MY_PRINT(j, resu);

    resu = SQUARE(i + j);
    MY_PRINT(i+j, resu);

    printf("This is file %s, line %d, run on  %s %s\n\n",__FILE__, __LINE__,__DATE__, __TIME__);
  
    system("dir");

    system("mkdir xxxDir");
  
    printf("\n%s\n\n", "create a sub-directory");

    system("dir");

    system("rmdir xxxDir");

    system("dir");

    return 0;
}

