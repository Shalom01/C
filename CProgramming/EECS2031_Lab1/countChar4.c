#include <stdio.h> // define EOF

int main(){
  int c;
  int count = 0;
  int lineCount = 0;
 
  c = getchar();
  while(c != EOF) /* no end of file*/
  { 
    if(c!='\n'){
       count++;
    }else{
        lineCount++;
    }

    c = getchar(); /* read next */
  }
  printf("# of chars: %d\n",count);
  printf("# of lines: %d\n", lineCount);

  return 0;

}

