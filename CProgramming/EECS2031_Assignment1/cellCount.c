/* PLEASE DO NOT MODIFY A SINGLE STATEMENT IN THE TEXT BELOW.
READ THE FOLLOWING CAREFULLY AND FILL IN THE GAPS

I hereby declare that all the work that was required to 
solve the following problem including designing the algorithms
and writing the code below, is solely my own and that I received
no help in creating this solution and I have not discussed my solution 
with anybody. I affirm that I have read and understood
the Senate Policy on Academic honesty at 
https://secretariat-policies.info.yorku.ca/policies/academic-honesty-senate-policy-on/
and I am well aware of the seriousness of the matter and the penalties that I will face as a 
result of committing plagiarism in this assignment.

BY FILLING THE GAPS,YOU ARE SIGNING THE ABOVE STATEMENTS.

Full Name: Shalom Asbell
Student Number: 215146954
Course Section: O
eecs user id: shalom01
*/

#include <stdio.h>
#include <stdlib.h>
#define IMAGE_SIZE 10

int cellValue; //a global variable that keeps track of the unique cell number.

//1.0: Iterative implementation helper functions.
void markCell(int image[IMAGE_SIZE][IMAGE_SIZE]);
int isNeighbour(int image[IMAGE_SIZE][IMAGE_SIZE], int i, int j, int value); //helper function that checks if a point is a neighbour to a value.
int arrayDoesNotContain(int array[], int value, int index); //helper function that returns 1 if an array (up to index) contains a value, else 0.

//2.0: Pointer implementation helper functions.
void markCellPtr(int* image);
int isNeighbourPtr(int* image, int i, int j, int value);
int blockDoesNotContain(int *ints, int value, int index); //helper function that checks if a memory block contains a given value up to an index.

//BONUS: recursive implementation helper functions.
void recursiveCellMarker(int image[IMAGE_SIZE][IMAGE_SIZE], int i, int j); //helper function that recursively marks a cell.
void colorRecursiveHelper(int image[IMAGE_SIZE][IMAGE_SIZE], int i, int j); //helper function to colorRecursively() that passes indexes i, j.

//This function prints the array
void printImgArray(int array[IMAGE_SIZE][IMAGE_SIZE])
{
    printf("------ Image Contents -------\n");
    int i, j;
	for (i=0; i<IMAGE_SIZE; i++)
    {
    for (j=0; j<IMAGE_SIZE; j++)
        printf("%02d, ", array[i][j]);
    printf("\n");
    }
    printf("-----------------------------\n");
}

/***************************PART 1***************************************/

/*
 * TASK 1.1:
 * This function colors each blood cell with a unique color iteratively.
 * (i.e. unique number)
 */

void color(int image[IMAGE_SIZE][IMAGE_SIZE]){
    //insert your code for task for 2.1 here.
    int i, j;
    cellValue=2; //set the unique cell numbering to begin at 2.
    for (i=0; i<IMAGE_SIZE; i++){
      for (j=0; j<IMAGE_SIZE; j++){
            if(image[i][j]==1){ //if we hit a 1-value point.
                image[i][j]=cellValue; //mark the point.
                markCell(image); //mark the cell around the point.
                cellValue++; //increment the unique cellNumber
            }
        }
    }
}

/*
 * This is a helper function for color() that marks the cell around a point found in the image.
 * It does this by checking scanning the map, and filling in the 1-valued points that are neighbours of the given value.
 */

void markCell(int image[IMAGE_SIZE][IMAGE_SIZE]){
    int i, j;
    int hasNeighbour = 1; //assume our value has at least one 1-value neighbour on the image.
    while(hasNeighbour){ //we do this until there are no more 1-value neighbours to our value left.
        hasNeighbour = 0; //tentatively assume that the value does not.
        for (i=0; i<IMAGE_SIZE; i++){
            for (j=0; j<IMAGE_SIZE; j++){ //search the image for neighbours of our value.
                if(image[i][j] == 1 && isNeighbour(image, i, j, cellValue)){ //if we find a 1-value point that is neighbours to our value.
                    hasNeighbour = 1; //we now know we have at least one neighbour.
                    image[i][j] = cellValue; //set the point to the value.
                }
            }
        }
    }
}

/*
 * This is a helper function for markCell(). It checks if the point is a neighbour of a given value.
 * It returns 1 if yes, 0 if no.
 */

int isNeighbour(int image[IMAGE_SIZE][IMAGE_SIZE], int i, int j, int value){

    if(i + 1 < IMAGE_SIZE && j + 1 < IMAGE_SIZE){ //check if bottom right corner of the point is accessible.
        if(image[i + 1][j + 1]==value || image[i + 1][j]==value || image[i][j + 1]==value){
            return 1; //if any of neighbours in the bottom-right corner containt the value.
        }
    }

    if(i - 1>= 0 && j - 1 >= 0){ //check if top left corner accessible.
        if(image[i - 1][j - 1]==value || image[i - 1][j]==value || image[i][j - 1]==value){
            return 1; //if any of neighbours in the top-left corner containt the value.
        }
    }

    if(i + 1 <IMAGE_SIZE && j - 1 >=0){ //check if bottom left corner accessible.
        if(image[i + 1][j - 1]==value || image[i + 1][j]==value || image[i][j - 1]==value){
            return 1; //if any of neighbours in the bottom-left corner containt the value.
        }
    }

    if(i - 1 >= 0 && j + 1 <IMAGE_SIZE){ //check if top right corner accessible.
        if(image[i - 1][j + 1]==value || image[i][j + 1]==value || image[i - 1][j]==value){
            return 1; //if any of neighbours in the top-right corner containt the value.
        }
    }

    return 0; //if it does not neighbour the value.
}

/*
 * TASK 1.2:
 * This function counts the number of distinct 
 * number (i.e. the number of cells).
 */

int cellCount(int image[IMAGE_SIZE][IMAGE_SIZE]){
    //insert your code for task for 2.2 here.
    int uniqueCells[IMAGE_SIZE] = {0}; //array to store all the unique numbers.
    int indexOfUnique = 0; //to keep track of where we are at in uniqueCells.
    int i, j;
    for(i=0; i<IMAGE_SIZE; i++){
        for(j=0; j<IMAGE_SIZE; j++){ //iterate through the image.
            //if a value is coloured (i.e. non-zero), and our unique array doesn't contain it.
            if(image[i][j]!=0 && arrayDoesNotContain(uniqueCells, image[i][j], indexOfUnique)){ 
                uniqueCells[indexOfUnique++] = image[i][j]; //add it to our uniqueCells array and increment the index.
            }
        }
    }

    return indexOfUnique; //which is the same as the amount of unique numbers.
}

/*
 * This is a helper funciton for cellCount().
 * It checks if an int array does not contain a value up to a given index.
 */

int arrayDoesNotContain(int array[], int value, int index){
    int i;
    for(i=0; i<=index; i++){ //iterate through the array up to the given index.
        if(array[i]==value){ //if at any point, we find the value.
            return 0;
        }
    }

    return 1;
}

/*******************************PART 2*****************************************/

/*
 * TASK 2.1:
 * This function colors each blood cell with a unique color using pointer notation only.
 * (i.e. unique number)
 */

void colorPtr(int* image){
    int i, j;
    cellValue=2; //set the unique cell numbering to begin at 2.
    for (i=0; i<IMAGE_SIZE; i++){
      for (j=0; j<IMAGE_SIZE; j++){
            if(*(image + i*IMAGE_SIZE + j)==1){ //if we hit a 1-value point.
                *(image + i*IMAGE_SIZE + j)=cellValue; //mark the point.
                markCellPtr(image); //mark the cell around the point using markCellPtr.
                cellValue++; //increment the unique cellNumber
            }
        }
    }
}

/*
 * This function is a helper function for colorPtr that iteratively marks a cell using pointers.
 */

void markCellPtr(int* image){
    int i, j;
    int hasNeighbour = 1; //assume our value has at least one 1-value neighbour.
    while(hasNeighbour){ //we do this until there are no more 1-value neighbours to our value left.
        hasNeighbour = 0; //tentatively assume that the value does not.
        for (i=0; i<IMAGE_SIZE; i++){
            for (j=0; j<IMAGE_SIZE; j++){ //search the image for neighbours of our value.
                //if we find a 1-value point that is neighbours to our value.
                if(*(image + i*IMAGE_SIZE + j) == 1 && isNeighbourPtr(image, i, j, cellValue)){
                    hasNeighbour = 1; //we now know we have at least one neighbour.
                    *(image + i*IMAGE_SIZE + j) = cellValue; //set the point to the value.
                }
            }
        }
    }
}

/*
 * This function is a helper function for markCellPtr that checks if a point has a neighbour with a particular value.
 */

int isNeighbourPtr(int* image, int i, int j, int value){
    if(i + 1 < IMAGE_SIZE && j + 1 < IMAGE_SIZE){ //check if bottom-right corner of the point is accessible.
        if(*(image + (i + 1)*IMAGE_SIZE + j + 1)==value || *(image + i*IMAGE_SIZE + j + 1) ==value || *(image + (i + 1)*IMAGE_SIZE + j)==value){
            return 1; //if any of neighbours in the bottom-right corner containt the value.
        }
    }

    if(i - 1>= 0 && j - 1 >= 0){ //check if top-left corner accessible.
        if(*(image + (i-1)*IMAGE_SIZE + j - 1) ==value || *(image + (i-1)*IMAGE_SIZE + j)==value || *(image + i*IMAGE_SIZE + j - 1)==value){
            return 1; //if any of neighbours in the top-left corner containt the value.
        }
    }

    if(i + 1 <IMAGE_SIZE && j - 1 >=0){ //check if bottom-left corner accessible.
        if(*(image + (i + 1)*IMAGE_SIZE + j - 1)==value || *(image + (i + 1)*IMAGE_SIZE + j)==value || *(image + i*IMAGE_SIZE + j - 1)==value){
            return 1; //if any of neighbours in the bottom-left corner containt the value.
        }
    }

    if(i - 1 >= 0 && j + 1 <IMAGE_SIZE){ //check if top-right corner accessible.
        if(*(image + (i-1)*IMAGE_SIZE + j + 1)==value || *(image + (i-1)*IMAGE_SIZE + j)==value || *(image + i*IMAGE_SIZE + j + 1)==value){
            return 1; //if any of neighbours in the top-right corner containt the value.
        }
    }

    return 0; //if it does not neighbour the value.
}

/*
 * TASK 2.2:
 * This function returns the number of unique cells using pointer notation.
 */

int cellCountPtr(int* image){
    int uniqueCells[IMAGE_SIZE] = {0}; //declaring extra array to store the values.
    int *unique = uniqueCells; //pointer notation for uniqueCells.
    int i;
    int indexOfUnique = 0;
    for(i=0; i < IMAGE_SIZE*IMAGE_SIZE; i++){
        if(*(image + i)!=0 && blockDoesNotContain(unique, *(image + i), indexOfUnique)){
            *(unique + indexOfUnique) = *(image + i);
            indexOfUnique++;
        }
    }

    return indexOfUnique;
}

/*
 * This function is a helper function for cellCountPtr.
 * It returns 0 if the memory block determined by *ints contains a value up to an index.
 */ 

int blockDoesNotContain(int *ints, int value, int index){
    int i;
    for(i=0; i<=index;i++){ //iterate through the memory block.
        if(*(ints+i)==value){ //if at any point, the memory block decided by our pointer and index contains the value.
            return 0;
        }
    }

    return 1;
}

/*******************************BONUS**************************************/

/*
 * BONUS:
 * This function recursively colors each cell with a unique color.
 * (i.e., unique number).
 */

void colorRecursively(int image[IMAGE_SIZE][IMAGE_SIZE]) {
    cellValue=2; //set the unique numbering to begin from 2.
    colorRecursiveHelper(image, 0, 0); //calls recursive helper method with origin point.
}

/*
 * This function is a helper function for colorRecursively() that passes along i and j indexes over recursive calls.
 */

void colorRecursiveHelper(int image[IMAGE_SIZE][IMAGE_SIZE], int i, int j){

    if(i < 0 || j < 0 | i >=IMAGE_SIZE || j>=IMAGE_SIZE){ //base cases.
        return;
    }

    if(image[i][j]==1){
        recursiveCellMarker(image, i, j); //calls recursive helper method.
        cellValue++; //increments the unique cell number.
    }

    /**recursive calls**/
    colorRecursiveHelper(image, i + 1, j);
    colorRecursiveHelper(image, i, j + 1);
    colorRecursiveHelper(image, i + 1, j + 1);
}

/*
 * This is a helper function for color(). 
 * It recursively marks a cell with a unique number.
 */

void recursiveCellMarker(int image[IMAGE_SIZE][IMAGE_SIZE], int i, int j){

    if(image[i][j]!=1){
        return; //if the value is not 1, do nothing.
    }

    image[i][j] = cellValue; //otherwise mark it with it's unique number.

    /***recursively check the numbers around the location to see if they are members of the cell***/
    if(i + 1 <IMAGE_SIZE && j + 1 <IMAGE_SIZE){ //check if bottom right corner accessible.
        recursiveCellMarker(image, i + 1, j + 1);
        recursiveCellMarker(image, i + 1, j);
        recursiveCellMarker(image, i, j + 1);
    }

    if(i - 1 >= 0 && j - 1 >= 0){ //check if top left corner accessible.
        recursiveCellMarker(image, i - 1, j - 1);
        recursiveCellMarker(image, i - 1, j);
        recursiveCellMarker(image, i, j - 1);
    }

    if(i + 1 <IMAGE_SIZE && j - 1 >=0){ //check if bottom left corner accessible.
        recursiveCellMarker(image, i + 1, j - 1);
        recursiveCellMarker(image, i + 1, j);
        recursiveCellMarker(image, i, j - 1);
    }

    if(i - 1 >= 0 && j + 1 <IMAGE_SIZE){ //check if top right corner accessible.
        recursiveCellMarker(image, i - 1, j + 1);
        recursiveCellMarker(image, i, j + 1);
        recursiveCellMarker(image, i - 1, j + 1);
    }
}

/********************************TESTING*************************************/

#ifndef __testing
int main(){

    // DO not change anything in main(), it will confuse the
    // auto-checker.  
    puts("testing the code with color() function");
    int count = 0;
    int cellImg[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};

    printImgArray(cellImg);
    color(cellImg);
    printImgArray(cellImg);
    count=cellCount(cellImg);
    printf("Total number of cells in the image: %d\n",count);
 

    puts("Testing the code with colorPtr");
    int cellImg_[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};

    int* ptr = cellImg_;
    printImgArray(ptr);
    colorPtr(ptr);
    printImgArray(ptr);
    count=cellCountPtr(ptr);
    printf("Total number of cells in the image: %d\n",count); 
    
	puts("Testing the code with colorRecursively");
    int cellImg__[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};
    printImgArray(cellImg__);
    colorRecursively(cellImg__);
    printImgArray(cellImg__);
    count=cellCount(cellImg__);
    printf("Total number of cells in the image: %d\n",count);
    return 0;
}
#endif