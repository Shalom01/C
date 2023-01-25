/**
 *  process.h
 *
 *  Full Name: Shalom Asbell
 *  Description of the program: Representation of a process in the system.
 *  
 */


#ifndef PROCESS_H
#define PROCESS_H

// representation of a a process
typedef struct process {
    int  pid; //process ID
    int  cpu_time; //the CPU time it takes to complete
    int  io_time;  //the time it needs for I/O
    int  arrival_time; //the time it arrives in the system
    int  turnaroundTime; //the turnaround time of the process
    int  totalCyclesRun; //the total cycles the process has run
    int  runningTime; //the current number of cycles the process has run (in CPU)
    int  blockedTime; //the clock time the process was "blocked"
    char state[10]; //the state of the process (i.e., "running", "blocked", "ready") and "terminated" used as a flag
} Process;

#endif
