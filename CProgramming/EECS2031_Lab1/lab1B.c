#include <stdio.h>

int main(int argc, char const *argv[])
{
    int Month;
    int Day;
    int Year;

    printf("Enter month, day and year separated by spaces: ");
    scanf("%d %d %d", &Month, &Day, &Year);
    printf("The input '%d %d %d' is reformatted as %d/%d/%d and %d-%d-%d\n", Month, Day, Year, Year, Month, Day, Year, Month, Day);
    


    return 0;
}
