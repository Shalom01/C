/**
 *  queue.c
 *
 *  Full Name: Shalom Asbell
 *  Description of the program: this program implements a queue of Process *'s.
 *  
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "process.h"
#include "queue.h"

int front = 0; //the index of the front of the queue
int size = 0; //the number of Process *s in the queue


/*
 * enque() enque's a Process * into the passed queue.
 */
void enque(Process *queue[], Process *process, int number_of_processes){
    if(size != number_of_processes){ //if the queue isn't full
        queue[(front + size) % number_of_processes] = process; //set the end of the queue to be the process. 
        size++;
    }
}

/*
 * deque() deque's the head of the queue.
 */
void deque(Process *queue[], int number_of_processes){
    if(size == 0){
        printf("queue is empty");
    }else{
        front = (front + 1) % number_of_processes; //shift the front one over.
        size--; //decrement the size
    }
}

/*
 * inQueue() returns 1 if the passed Process * is in the queue, else 0.
 */

int inQueue(Process *queue[], Process *p, int number_of_processes){
    int i = front;
    int rear = (front + size) % number_of_processes;
    while(i != rear){
        if(queue[i]==p){ //if the Process address is in the queue
            return 1;
        }
        i = (i + 1) % number_of_processes;
    }
    return 0;
}

/*
 * head() returns the head of the queue
 */
Process * head(Process *queue[]){
    return queue[front];
}

/*
 * isEmpty() returns 0 if the queue is empty, else 1.
 */
int isEmpty(){
    if(size==0){
        return 1;
    }
    return 0;
}
