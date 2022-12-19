/***************************************
* EECS2031ON – Lab 6 lab6LL2.c
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_num: shalom01
* Yorku #: 215146954
****************************************/
#include <stdio.h>
#include <stdlib.h>

void insertBegining(int);

struct node { 
   int data;
   struct node * next;
};

struct node * head;

int main()
{
   head = NULL;

   insertBegining(100);
   insertBegining(200);
   insertBegining(300);
   insertBegining(400);   
   insertBegining(500);

   int i; 
   struct node * cur;
   for(cur= head; cur != NULL; cur= cur->next)
     printf("%d ", cur->data);
   printf("\n");  
}   

void insertBegining(int dat){
   struct node * newNode =  malloc(sizeof(struct node)); //allocate dynamic memory for pointer *newNode
   (*newNode).data = dat;
   (*newNode).next = head;
   
   head = newNode; //the head points to the newNode

}
