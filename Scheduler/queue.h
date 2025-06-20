/**
 *  queue.h
 *
 *  Author: Shalom Asbell
 *  Description of the program: A header file that contains explicit declarations for all the functions implemented in "queue.c".
 *  
 */

void enque(Process *queue[], Process *process, int number_of_processes);
void deque(Process *queue[], int num_of_processes);
void traverse(Process *queue[], int num_of_processes);
int inQueue(Process *queue[], Process *p, int number_of_processes);
Process * head(Process *queue[]);
int isEmpty();

