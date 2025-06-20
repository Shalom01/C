# OS SCHEDULING SIMULATOR

*******************************************************************************************************
*Author*: Shalom Asbell                                                                            
*Description*: a readable file describing each included file and its dependencies                     
  and instructions of how to run the project.                                                         
*******************************************************************************************************

## FILE DESCRIPTIONS

1. *Name*: scheduler.c  
   *Description*: the main C file of the program. Contains the scheduling simulation algorithms for FCFS,  
   RR, and SJF.  
   *Dependencies*: scheduler.h, queue.c, queue.h, process.h, <stdio.h>, <stdlib.h>, <string.h>, <math.h>  

2. *Name*: scheduler.h  
   *Description*: a header file that contains the constants and explicit function declarations  
   of the scheduler.c file.  
   *Dependencies*: None  

3. *Name*: queue.c  
   *Description*: a C file that implements a queue data structure of Process pointers.  
   *Dependencies*: queue.h, process.h, <stdlib.h>, <stdio.h>, <string.h>  

4. *Name*: queue.h  
   *Description*: a header file that contains the constants and explicit function declarations  
   of the queue.c file.  
   *Dependencies*: None  

5. *Name*: process.h  
   *Description*: a header file that defines a process in our system.  
   *Dependencies*: None  

6. *Name*: Makefile  
   *Description*: a makefile that allows for easy compilation and running of the project.  
   *Dependencies*: None  

7. *Name*: README.txt  
   *Description*: a readable file that contains project file descriptions and instructions  
   for how to run the project.  
   *Dependencies*: None  

## HOW TO RUN

1. Navigate to the project folder in a terminal.  
2. Type `make` to compile the program using the provided Makefile.  
3. Type `./scheduler processFile digit` to run the program.  

   - `processFile` is the full name of the input file.  
   - `digit` is the digit corresponding to the desired scheduling algorithm:  
     - `0` = FCFS  
     - `1` = RR  
     - `2` = SJF  
