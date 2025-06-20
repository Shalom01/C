# Author: Shalom Asbell
# Description: makefile for scheduling program        
CC=gcc
DEPS = scheduler.h process.h queue.h
OBJ = scheduler.o
CFLAGS=-Wall
STD_FLAG=-std=c99


scheduler.o: scheduler.c scheduler.h queue.c queue.h
	$(CC) $(CFLAGS) scheduler.c queue.c $(STD_FLAG)  -lm -o scheduler

clean:
	rm -rf *.o