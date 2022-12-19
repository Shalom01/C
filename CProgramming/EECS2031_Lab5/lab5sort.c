/***************************************
* EECS2031ON – Lab5
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_num: shalom01
* Yorku #: 215146954
****************************************/
#include <stdio.h>
#include <string.h>


void sortArray(char *input);
void printPtr(char *input);


int main(){

    char input[30]; //ptr block of characters (input).
    fgets(input, 30, stdin); //get the input.

    while(strcmp("quit\n", input)!=0){
        sortArray(input); //sort it.
        printPtr(input); printf("\n"); //print it.
        fgets(input, 30, stdin); //get new input.
    }
    
    return 0;
}


void sortArray(char *input){ //implemented using MergeSort for O(nlogn) complexity.
    int n=0;
    while(*(input + n)!='\n'){ //get the last index.
        n++;
    }
    
    //using selection sort.
    int i, smallest, j;
    for(i=0;i<=n-2;i++){
        smallest = i;
        for(j=i+1; j<=n-1; j++){
            if((*(input + j)) < (*(input + smallest))){
                smallest = j;
            }
        }
        char temp = *(input + i);
        *(input + i) = *(input + smallest);
        *(input + smallest) = temp;
    }
}

//Helper function used to print char* input.
void printPtr(char* input){
    int i=0;
    while(*(input + i)!='\0'){
        char c = *(input + i);
        printf("%c", c);
        i++;
    }
}
