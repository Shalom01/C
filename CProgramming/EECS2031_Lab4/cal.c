int x;   // define a global variable
static int y;   // define a global variable

void modify (void) // define a function
{
  x -= 10;
  y *= 10 +  2;
}

void doNothing(void){
  y += 0; // no change, just demo that y is accessible here. 
}