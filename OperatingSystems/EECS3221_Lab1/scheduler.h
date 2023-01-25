/**
 *  scheduler.h
 *
 *  Full Name: Shalom Asbell
 *  Description of the program: A header file to contain the QUANTUM constant for the RR algorithm implemented in "scheduler.c".
 * It also contains explicit declarations for all the functions implemented in "scheduler.c".
 *  
 */

// length of a time quantum
#define QUANTUM 2

//explicit declarations for all functions contained by "scheduler.c"
int allTerminated(Process[], int);
void FCFS(Process[], int, int, char[]);
void RR(Process[], int, int, char[]);
void SJF(Process[], int, int, char[]);
void sortById(Process processes[], int num_of_processes);
FILE * getOutputFile(char inputFileName[], int scheduling_type);
void readyProcesses(Process processes[], Process *queue[], int num_of_processes, int clock);
void queueReadyProcesses(Process *queue[], Process processes[], int num_of_processes);
void runProcess(Process *queue[]);
void blockingAndTerminating(Process *queue[], int num_of_processes, int clock);
void timingSnapshot(Process processes[], FILE *output, int clock, int num_of_processes);
void printStatistics(Process processes[], FILE *output, int clock, int num_of_processes);
