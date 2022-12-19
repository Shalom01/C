/***************************************
* EECS2031ON – Lab 6 lab6LLX.c
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_num: shalom01
* Yorku #: 215146954
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50
#define MAX_LEN 30

struct integers
{
  int int1;
  int int2;
};

struct node {  // list 'node' struct
   char data;
   struct node *next;
};


void init( );
void display();
int len();
int search(char); 
char get(int);
void insert(char d );
void insertAfter(char key, int index);
void delete (char d);


struct node * head;   // global variable, the head of the linkedlist

int main()
{
    int i, index; char key;

    struct integers arr[MAX_LEN]; // an array of ten structs

    char buffer[BUFFER_SIZE];
    int value1, value2;
    int count= 0;

    FILE * file;
    file = fopen("data.txt", "r");

    while (fgets(buffer, BUFFER_SIZE, file) != NULL)     // or  while (fscanf(file, "%d %d", &value1, &value2) == 2)
    {
       sscanf(buffer, "%d %d", &value1, &value2);   // tokenize buffer and store into value1 and value2

       arr[count].int1 = value1;
       arr[count].int2 = value2;
       count++;
    }

    fclose(file);

    /* print the array of structures */
    for(i=0; i< count; i++){
        printf("arr[%d]: %d %d\n", i, arr[i].int1, arr[i].int2);
    }

    // now building up the list by reading from the array of structures
    printf("\n");
    init();

    i=0;
    for(; i < count; i++){
       // read two ints from each structure in the array, sum up and added into the list
        char value = arr[i].int1 + arr[i].int2;
        insert(value); 
        printf("insert %c: (%d)", value, len());  display();
    }
    // no more coding in main()
    char removeList [] = {'B','S','A','O','R','K','Y','U','L','\0'}; // \0 is the terminating token
    i=0;
    while ( (key=removeList[i]) != '\0'){
        delete(key);
        printf("remove %c: (%d)", key, len()); display();
        i++;
    }

    // insert again
    char addList [] = "YORKULABS"; 
    i=0;
    while ( (key=addList[i]) != '\0'){ 
        insert(key);
        printf("insert %c: (%d)", key, len());
        display();
        i++;
    }

    int v = get(0);  printf("\nget(0): %c\n", v);
    v = get(3);  printf("get(3): %c\n", v);
    v = get(6);  printf("get(6): %c\n", v);
    v = get(7);  printf("get(7): %c\n", v);
    v = get(8);  printf("get(8): %c\n", v);

    key ='x'; index =2; insertAfter(key,index);
    printf("\ninsert %c after index %d: (%d)\t", key,index,len()); display();
    key ='y'; index = 0; insertAfter(key,index);
    printf("insert %c after index %d: (%d)\t", key,index,len()); display();
    key ='z'; index = 6;insertAfter(key,index);
    printf("insert %c after index %d: (%d)\t", key,index,len()); display();

    v = get(0);  printf("\nget(0): %c\n", v);
    v = get(3);  printf("get(3): %c\n", v);
    v = get(6);  printf("get(6): %c\n", v);
    v = get(7);  printf("get(7): %c\n", v);
    v = get(8);  printf("get(8): %c\n", v);


   // search
    printf("\n");
    char searchList [] = "yorkUxyZAb";
    int len = strlen(searchList);
    i=0;
    while ( i < len ){
       char key = *(searchList + i);
       printf("search %c ....  ", key);
        
       if (search(key))
          printf("found\n");
       else
          printf("not found\n");
       i++;
  
    }


}

/* Initialize the list. */
void init( )
{
   head = NULL;
}



/* Print the content of the list. */
void display()
{
    struct node *current = head;
    while (current != NULL){
       printf( "%3c", current->data );
       current = current -> next;
    }printf( "\n" );

}

/* return the length of the linked list */
int len()
{
   struct node * current = head; //create a pointer to the head
   int count = 0;
   while(current != NULL){ 
      count++;
      current = current -> next;
   }
   return count;
}

/* get the data at node index */
char get(int index){
   int i = 0;
   struct node * node = head;
   while(i!=index && node!=NULL){
      node = node->next;
      i++;
   }
   return node->data;
}

/* search the list for key, return whether it is found */
int search (char key)
{
   struct node * node = head;
   while(node->data!=key && node->next!=NULL){
      node = node->next;
   }

   if(node->data==key){
      return 1;
   }

   return 0;
}


/* Insert a new data element with key d into the end of the list. */
/* Hint: You need to consider the special case that the list is empty,
   and the general case that the list is not empty */
void insert(char d)  //  at the end
{
   if (head == NULL){/* the list is empty */
      head = malloc(sizeof(struct node));
      head->data = d;
      head->next = NULL;
   }else{  // general case, insert at the end.
      struct node *node = head;
      while(node->next!=NULL){
         node = node->next;
      }
      struct node *newNode = malloc(sizeof(struct node));
      (*node).next = newNode;
      newNode->data = d;
      newNode->next = NULL;
   }
}

/* insert in the middle.
  insert new node with data d, after the node of index 'index'
  assume the list is not empty, and index is in [0, len()-1]
 */
void insertAfter(char d, int index )
{
   int i = 0;
   struct node * node = head;
   struct node * newNode = malloc(sizeof(struct node));
   newNode->data = d;
   while(i<len()){
      if(i==index){
         newNode->next = node->next;
         node->next = newNode;
         break;
      }
      node = node->next;
      i++;
   }
}

/* lab version */
/* Remove the node with value d from the list */
/* assume the list is not empty  */
/* assume the node to be deleted is in the list */
/* assume no duplicated keys in the list */
/* You don't have to free the space */
void delete(char d)
{
   /* special case: to be removed is the first, need to change head  */
   if (head -> data == d){
        head = head -> next;
   }
   
   else  // general case, remove from the middle or the last
   {
      struct node *node = head;
      while(node->next!=NULL){
         if(node->next->data == d){
            node->next = node->next->next;
            break;
         }
         node = node->next;
      }
   }
}