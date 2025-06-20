/**
 *  scheduler.c
 *
 *  Author: Shalom Asbell
 *  Description of the program: scheduler takes an input file with processes and their information (in command argument 1) 
 *  and a digit (in command argument 2) that corresponds to the wanted scheduling algorithm (1=FCFS, 2=RR, 3=SJF). It then
 *  simulates the scheduling algorithm and outputs a timing snapshot of every cycle in the schedule 
 *  (showing the state of current processes in system) and a statistical summary of the total schedule 
 *  (showing the finishing time, CPU utilization, and process turnaround times).
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "process.h"
#include "queue.h"
#include "scheduler.h"

int main(int argc, char *argv[])
{
	FILE *inputFile = fopen(argv[1],"r"); //open the file specified by second command argument
	char *inputFileName = argv[1]; //get the inputFileName (to be used for outputFileName)
	int scheduling_type = atoi(argv[2]); //get the type of scheduling from third command argument

	int num_of_processes;
	fscanf(inputFile, "%d", &num_of_processes); //get the number of processes to schedule from the file
	Process processes[num_of_processes]; //create a list of all processes as an array

	if (num_of_processes > 0){
		int i;
		for (i = 0; i<num_of_processes; i++){ //scan the input from the file, and add A, B, C, D to each Process
			fscanf(inputFile, "%d %d %d %d",
					&processes[i].pid,
					&processes[i].cpu_time,
					&processes[i].io_time, 
					&processes[i].arrival_time);
					processes[i].totalCyclesRun = 0; //set the number of total cycles run to 0
					processes[i].runningTime = 0; //set the current cycles run to 0
		}                                                                       

		sortById(processes, num_of_processes); //sort the processes by ID

		if(scheduling_type==0){
			FCFS(processes, num_of_processes, scheduling_type, inputFileName); //run the FCFS algorithm
		}

		if(scheduling_type==1){
			RR(processes, num_of_processes, scheduling_type, inputFileName); //run the RR algorithm
		}

		if(scheduling_type==2){
			SJF(processes, num_of_processes, scheduling_type, inputFileName); //run the SJF algorithm
		}	
	}

	fclose(inputFile);  
	return 0;
}

/*
 * FCFC implements the first come first serve scheduling algorithm. It schedules the proceses passed by whichever process is "ready" first
 * and outputs the scheduling into an output FILE.
 */

void FCFS(Process processes[], int num_of_processes, int scheduling_type, char * inputFileName){

	FILE * output = getOutputFile(inputFileName, scheduling_type); //get a FILE * to a formatted output file
	Process *queue[num_of_processes]; //create a queue for our processes
	int clock = 0; //set the clock to 0
	
	while(!allTerminated(processes, num_of_processes)){
		readyProcesses(processes, queue, num_of_processes, clock); //"ready" up the ready processes
		queueReadyProcesses(queue, processes, num_of_processes); //queue "ready" processes
		runProcess(queue); //run the first available "ready" processes (i.e., set head of queue to "running" if "ready")
		timingSnapshot(processes, output, clock, num_of_processes); //input information about the current clock cycle into the output FILE
		clock++;
		blockingAndTerminating(queue, num_of_processes, clock); //if the head of the queue is "running", check if it should be "blocked" or "terminated"
	}

	printStatistics(processes, output, clock, num_of_processes); //after all processes are "terminated", print the statistics of our FCFC scheduling in the output FILE
	fclose(output);
}

/*
 * RR() implements the round-robbin scheduling algorithm. If schedules processes by a QUANTUM value that specifies the amount 
 * of time that each process is allowed to run in the CPU before changing to a different "ready" process.
 */

void RR(Process processes[], int num_of_processes, int scheduling_type, char * inputFileName){
	
	FILE * output = getOutputFile(inputFileName, scheduling_type); //get a FILE * to a formatted output file
	Process *queue[num_of_processes]; //create a queue for our processes
	int clock = 0; //set the clock to 0

	while(!allTerminated(processes, num_of_processes)){
		readyProcesses(processes, queue, num_of_processes, clock); //"ready" up the ready processes
		queueReadyProcesses(queue, processes, num_of_processes); //queue "ready" processes
		runProcess(queue); //run the first available "ready" processes (i.e., set head of queue to "running" if "ready")
		timingSnapshot(processes, output, clock, num_of_processes); //input information about the current clock cycle into the output FILE
		clock++;
		blockingAndTerminating(queue, num_of_processes, clock); //if the head process hits an I/O block ("blocked") or if terminated ("terminated")
		
		if(!isEmpty()){
			Process *front = head(queue);
			if(front->runningTime == QUANTUM && strcmp(front->state, "running")==0){ //if we hit a QUANTUM
				strcpy(front->state, "ready"); //set the process to ready
				deque(queue, num_of_processes); //deque it from the head
			}
		}
	}

	printStatistics(processes, output, clock, num_of_processes); //after all processes have "terminated", print the statistics of our scheduling
	fclose(output);
}

/*
 * SJF() implements the shortest job first scheduling algorithm. At every clock cycle, if nothing is "running",
 * it finds the shortest "ready" process (the one with the least total time remaining to run) and runs it.
 */
void SJF(Process processes[], int num_of_processes, int scheduling_type, char * inputFileName){

	FILE * output = getOutputFile(inputFileName, scheduling_type); //get a FILE * to a formatted output file
	Process *queue[num_of_processes]; //create a queue for our processes
	int clock = 0; //set the clock to 0

	while(!allTerminated(processes, num_of_processes)){

		readyProcesses(processes, queue, num_of_processes, clock); //"ready" all ready processes

		if(isEmpty()){ //if the queue is empty (i.e., nothing is running in this case), find the shortest "ready" process and queue it
			Process *shortest;
			int foundReady = 0; //flag if we found a "ready" process
			int i;
			for(i = 0; i < num_of_processes; i++){ //check all processes, if we find a "ready" one, set it to shortest
				if(strcmp(processes[i].state, "ready")==0){
					shortest = &processes[i];
					foundReady = 1;
					break;
				}
			}

			if(foundReady){ //if we found a "ready" process
				for(; i<num_of_processes; i++){ //check the rest of the processes
					if(strcmp(processes[i].state, "ready")==0 && (processes[i].cpu_time - processes[i].totalCyclesRun) < (shortest->cpu_time - shortest->totalCyclesRun)){
						shortest = &processes[i]; //if we found a process whose total time left is < the shortest, set it to shortest
					}
				}
				enque(queue, shortest, num_of_processes); //add the shortest to the queue
			}
		}

		runProcess(queue); //run the process
		timingSnapshot(processes, output, clock, num_of_processes); //print the timingSnapshot into the FILE
		clock++; //increment the clock
		blockingAndTerminating(queue, num_of_processes, clock); //check if we need to "block" or "terminate" the process
	}

	printStatistics(processes, output, clock, num_of_processes);
	fclose(output);
}

/*
 * getOutputFile() returns a FILE pointer to a FILE formatted based on inputFileName and the scheduling_type
 */
FILE * getOutputFile(char * inputFileName, int scheduling_type){
	char * outputFileName = malloc(1);
	strtok(inputFileName, "."); //cut the inputFileName by the "."
	sprintf(outputFileName, "%s%s%d%s", inputFileName, "-", scheduling_type, ".txt"); //formatting output FILE
	FILE *output = fopen(outputFileName, "w"); //make output FILE
	return output;
}

/*
 * readyProcesses() "ready"s all processes for which one of:
 * (1) arrival_time = clock
 * (2) was "blocked", but completed its I/O time.
 */
void readyProcesses(Process processes[], Process *queue[], int num_of_processes, int clock){
	int i;
	for(i = 0; i < num_of_processes; i++){	//Insert all ready processes by ID into QUEUE...		
		if(processes[i].arrival_time == clock){
			strcpy(processes[i].state, "ready");
		}
			
		if((processes[i].blockedTime + processes[i].io_time) == clock && strcmp(processes[i].state, "blocked")==0){
			strcpy(processes[i].state, "ready");
		}
	}
}

/*
 * queReadyProcesses() queues all "ready" processes that are not already in the queue.
 */

void queueReadyProcesses(Process *queue[], Process processes[], int num_of_processes){
	int i;
	for(i = 0; i < num_of_processes; i++){
		if(strcmp(processes[i].state, "ready") == 0 && !inQueue(queue, &processes[i], num_of_processes)){ //if the process is "ready" and isn't already in the queue
			enque(queue, &processes[i], num_of_processes);
		}
	}
}

/*
 * runProcess() checks the head of the queue (if its not empty) and if it is "ready", runs it. If the state is "running" 
 * and we still havn't completed a CPU burst, increment the totalCyclesRun, and the totalCPUTime and the current runningTime of the process.
 */
void runProcess(Process *queue[]){
	if(!isEmpty()){
		Process *front = head(queue);
		if(strcmp(front->state, "ready")==0){ //if the top of the queue is ready, run it
			strcpy(front->state, "running");
		}

		if(strcmp(front->state, "running")==0 && ceil(front->cpu_time/2.0)!=front->runningTime){ //if the front process is running
			front->totalCyclesRun++;
			front->runningTime++;
		}
	}
}

/*
 * blockingAndTerminating() changes the state to "blocked" when the process runs for its first CPU burst
 * and to "terminated" when it completes its second burst.
 */
void blockingAndTerminating(Process *queue[], int num_of_processes, int clock){
	if(!isEmpty()){
		Process *front = head(queue);
		if(strcmp(front->state, "running")==0){
			if(ceil(front->cpu_time) == front->totalCyclesRun){//if the front process completed its second CPU burst
				strcpy(front->state, "terminated"); //terminate the process
				front->turnaroundTime = clock - front->arrival_time; //set turnaroundTime to current clock time - arrival time
				front->runningTime = 0; //reset the runningTime
				deque(queue, num_of_processes); //remove it from the queue
			}

			if(ceil(front->cpu_time/2.0) == front->runningTime){ //if we completed our first CPU burst
				strcpy(front->state, "blocked"); //block it
				front->blockedTime = clock; //set the time it was blocked to the current clock
				front->runningTime = 0; //reset the runningTime
				deque(queue, num_of_processes); //remove it from the queue
			}
		}
	}
}

/*
 * sortByID() is a simple insertion sort that sorts an array of processes by ID.
 */
void sortById(Process processes[], int num_of_processes){
	int i;
	for(i = 1; i < num_of_processes; i++){
		int j = i;
		while(j > 0 && processes[j-1].pid > processes[j].pid){
			Process temp = processes[j];
			processes[j] = processes[j - 1];
			processes[j - 1] = temp; 
			j--;
		}
	}
}

/*
 * allTerminated() returns 1 if all the processes in an array of processses have terminated, else 0.
 */
int allTerminated(Process process[], int num_of_processes){
	int i;
	for(i = 0; i < num_of_processes; i++){
		if(strcmp(process[i].state, "terminated")!=0){ //if we find one process with a state other than "terminated"
			return 0;
		}
	}
	return 1;
}

/*
 * timingSnapshot() prints into the passed FILE *
 * (1) The passed clock time
 * (2) All the "running", "ready", and "blocked" processes from a list of processes.
 */
void timingSnapshot(Process processes[], FILE *output, int clock, int num_of_processes){
	fprintf(output, "%d", clock);
	
	int i;
	for(i = 0; i < num_of_processes; i++){
		if(strcmp(processes[i].state, "running") == 0 || strcmp(processes[i].state, "ready") == 0 || strcmp(processes[i].state, "blocked") == 0){
			fprintf(output, " %d:%s", processes[i].pid, processes[i].state);
		}
	}
	
	fprintf(output, "\n");
}

/*
 * printStatistics() prints into the passed FILE *
 * (1) Finishing time 
 * (2) CPU utilization
 * (3) Each processes turnaround time.
 */ 
void printStatistics(Process processes[], FILE *output, int clock, int num_of_processes){
	fprintf(output, "\nFinishing time: %d\n", clock - 1); //print the finishing time of all processes into output FILE
	
	int totalCPUTime = 0;
	int i;
	for(i = 0; i < num_of_processes; i++){
		totalCPUTime += processes[i].totalCyclesRun; //add up the cycles run for each process 
	}

	fprintf(output, "CPU utilization: %.2f\n", (totalCPUTime)/((double) (clock))); //print the CPU utilization time into output FILE
	for(i = 0; i < num_of_processes; i++){
		fprintf(output, "Turaround process %d: %d\n", processes[i].pid, processes[i].turnaroundTime); //print the pID and turaround time into output FILE
	}
}
