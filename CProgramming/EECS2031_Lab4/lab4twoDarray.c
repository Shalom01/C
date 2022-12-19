#include<stdio.h>
#include<string.h>

int main(){

  int a [3][2] = {{1,2},{3,4},{5,6}};
  printf("sizeof %d\n", sizeof a);
  int i, j;
  for(i=0; i<3; i++){
    for(j=0; j<2; j++)
      printf("%d ", a[i][j]);
    printf("\n") ;
  }
  a[0][1] = 100;
  a[2][1] *= 10;
  printf("enter new value for a[1][0]: ");
  scanf("%d", &a[1][0]);
  
  printf("\n");  
  for(i=0; i<3; i++){  // nested loop
    for(j=0; j<2; j++)
      printf("%d ", a[i][j]);
    printf("\n") ;
  }

  printf("-----------\n\n") ;

  // array of strings
  char b[3][20] = {"Hello", "The", "World!"};
  printf("sizeof %d\n", sizeof b) ;
  printf("%s  %d\n\n", b[0], strlen(b[0]));
  for(i=0; i<3; i++)
    printf("%s\n", b[i]) ; // print at the row level, one loop 

   printf("\n") ;  
  
  //modify 
  b[1][0] = 't';  // cell level directly
  strcpy(b[2], "beautiful land"); // whole row level
  printf("enter new word for first row: "); // whole row level
  scanf("%s", b[0]); //whole row level
  for(i=0; i<3; i++)
    printf("%s\n", b[i]) ;
}
