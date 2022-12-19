/* PLEASE DO NOT MODIFY A SINGLE STATEMENT IN THE TEXT BELOW.
READ THE FOLLOWING CAREFULLY AND FILL IN THE GAPS

I hereby declare that all the work that was required to 
solve the following problem including designing the algorithms
and writing the code below, is solely my own and that I received
no help in creating this solution and I have not discussed my solution 
with anybody. I affirm that I have read and understood
the Senate Policy on Academic honesty at 
https://secretariat-policies.info.yorku.ca/policies/academic-honesty-senate-policy-on/
and I am well aware of the seriousness of the matter and the penalties that I will face as a 
result of committing plagiarism in this assignment.

BY FILLING THE GAPS,YOU ARE SIGNING THE ABOVE STATEMENTS.

Full Name: Shalom Asbell
Student Number: 215146954
Course Section: O
eecs user id: shalom01
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 30
#define fieldLength 200


#define diskFile "diskFile.dat"
#define courseFile "course.txt"

struct db_type
{
   char name[fieldLength];
   int age;
   char course1[fieldLength];
   char course2[fieldLength];
   char status[fieldLength];
 };

struct courseInfo
{ 
  char code [20]; // e.g., EECS2030
  char title [fieldLength];
  char  date [20];
  char time_start [20];
  char time_end [20];
  char  location [20]; 
};
 
 
struct courseInfo courseArr[SIZE]; // global variable  array of students added.
     
char prompt_menu(void);
void init_list(struct db_type * pArr[]); 
void clearDB(struct db_type * pArr[]);
void displayDB(struct db_type * pArr[]);
void init_courseArr(void);
void swap(struct db_type * pArr[]);

void writeDisk(struct db_type * pArr[]); 
void emptyDisk(void); 
void loadDisk(struct db_type * pArr[]);


/******helper functions*****/
int getCourseIndex(char courseName[]); //retrieves the index of the course (in the course list) with the given courseName.
int sameCourseName(char fullCode[], char code[]); //determines if the given code represents the given fullCode
int isConflict(char date1[], char date2[], int start_time1, int start_time2, int end_time1, int end_time2); //calculates if there is a conflict between two given dates and times.
int getTimeInt(char timeString[]); //returns an integer form of a 24-hour clock time string in the form of "x:x" where x is an int.
void shiftPointerArray(int index, struct db_type * pArr[]); //shifts a pointer array when an element is removed.

int main(int argc, char *argv[])
{
    struct db_type * db_pArr[SIZE];  // main db storage

    init_list(db_pArr);  // set to NULL
    
    init_courseArr();  // load course from diskfile
    
    char choice;
    for(; ;){
      choice = prompt_menu();
      switch (choice)
      {
         case 'n': enterNew(db_pArr); break;
         case 'd': displayDB(db_pArr); break;
         case 'w': writeDisk(db_pArr);  break;    
         case 'l': loadDisk(db_pArr); break;
         case 's': sort(db_pArr); break;
	   
         case 'c': clearDB(db_pArr); break;  
         case 'e': emptyDisk();break;

         case 'v': displayCourses();break;
         case 'p': swap(db_pArr); break;
         case 'r': removeRecord(db_pArr);break;
         
         case 'q': exit(1); // terminate the whole program
       }
	
     }
     return 0;
}

void init_list(struct db_type * pArr[]){
  int t;
  for (t=0; t<SIZE; t++)
  { 
     pArr[t]= NULL;
  }
}

void clearDB(struct db_type * pArr[]){
   char c3[3];
   printf("are you sure to clear db? (y) or (n)? ");
 
   fgets(c3,3,stdin);
   
   if(!strcmp(c3, "y\n"))
      init_list(pArr);
}


char prompt_menu(void){
  char s[80];
  while(1){
    printf("\n-----------------------------------------------------------------\n");
    printf("|    %-20s","(N)ew record");
    printf("%-20s","(R)emove record");
    printf("Swa(p) records\t|\n");
    printf("|    %-20s","(S)ort database");
    printf("%-20s","(C)lear database");
    printf("(D)isplay db\t|\n");
  
    printf("|    %-20s","(L)oad disk");
    printf("%-20s","(W)rite disk");
    printf("(E)mpty disk\t|\n");
  
    printf("|    %-20s", "(V)iew courses");//|\tSwa(p) record\t(Q)uit\t\t\t\t|\n");
    printf("%-20s","(Q)uit");
    printf("*Case Insensitive*\t|\n");
    printf("-----------------------------------------------------------------\n");
    printf("choose one: ");
  
    fgets(s,50, stdin); // \n added
   
    if (strlen(s) == 2 && strchr("edlsuqrcwnvpr", tolower(*s)))
       return tolower(*s); // s[0], return the first character of s  
    //else
    printf("not a valid input!\n");
 }
}

/* display all or specified course */
void displayCourses(void){  // the provide sample.out uses "%s\t%-40s%-5s %s-%s   %s\n" as formatting string for printing each course info
    char courseCode[8]; //set to 8 because of EECSXXXX assumption.
    printf("course code (or 'a')? ");
    fgets(courseCode, "%s", stdin);
    
    if(!strcmp(courseCode, "a\n")){ //if the inputted value is 'a', then output all the courses.
      printf("\n===================================================================================\n");
      int i;
      for(i=0; strcmp(courseArr[i].code, "EECS0000"); i++){
        printf("%s\t%-40s%-5s %s-%s   %s\n", courseArr[i].code, courseArr[i].title, courseArr[i].date, courseArr[i].time_start, courseArr[i].time_end, courseArr[i].location);
      }
      printf("===================================================================================");
    }else{
      int i;
      int found = 0; //assume this course doesn't exist
      for(i = 0; strcmp(courseArr[i].code, "EECS0000"); i++){ //keep searching for a course with the given course name.
        if(!sameCourseName(courseArr[i].code, courseCode)){ //if we find a course with the same name.
          printf("%s\t%-40s%-5s %s-%s   %s\n", courseArr[i].code, courseArr[i].title, courseArr[i].date, courseArr[i].time_start, courseArr[i].time_end, courseArr[i].location); //print the course.
          found = 1;
          break;
        }
      }

      if(!found){ //if we couldn't find it
        printf("error! course does not exist");
      }
    }
}

/* input items into the list */
void enterNew(struct db_type * pArr[SIZE]){
  int studentIndex = getStudentIndex(pArr);
  pArr[studentIndex] = malloc(sizeof (struct db_type)); //assign dynamic memory for the new student at the current index.

  /**input and store name data**/
  printf("name: ");
  fgets(pArr[studentIndex]->name, "%s", stdin); //get the name as a string from the user and store it into the new student data.
  pArr[studentIndex]->name[strlen(pArr[studentIndex]->name) - 1] = '\0'; //set the '\n' to '\0'.

  /**input and store age data**/
  printf("age: ");
  char ageChar[fieldLength];
  fgets(ageChar, "%s", stdin); //retrieve the age as a string
  int age = atoi(ageChar); //convert it to an int (this removes the '\n' while allowing for consistent use of fgets)
  pArr[studentIndex]->age = age; //store the age into the new student data.

  /**input and store course1 data**/
  printf("course-1: ");
  char courseName [fieldLength];
  fgets(courseName, "%s", stdin); //retrieve the course name as a string.
  courseName[strlen(courseName)-1] = '\0'; //set the '\n' to '\0'.

  int course1Index = getCourseIndex(courseName); //get the index of the course with the course name.
  while(course1Index == -1){ //while the course does not exist in the course array.
    printf("course does not exist, enter again: ");
    fgets(courseName, "%s", stdin); //get a new course name string.
    courseName[strlen(courseName)-1] = '\0'; //set the '\n' to '\0'.
    course1Index = getCourseIndex(courseName); //get the index of the course with the course name.
  }

  /**input and store course2 data**/
  printf("course-2: ");
  fgets(courseName, "%s", stdin); //retrieve the course name as a string.
  courseName[strlen(courseName)-1] = '\0'; //set the '\n' to '\0'.

  int course2Index = getCourseIndex(courseName); //get the index of the course with the course name.
  while(course2Index == -1){ //while the course does not exist in the course array.
    printf("course does not exist, enter again: ");
    fgets(courseName, "%s", stdin); //get a new course name string.
    courseName[strlen(courseName)-1] = '\0'; //set the '\n' to '\0'.
    course2Index = getCourseIndex(courseName); //get the index of the course with the course name.
  }

  strcpy(pArr[studentIndex]->course1, courseArr[course1Index].code); //copy the full course code of the course at index of course 1 into the new student data.
  strcpy(pArr[studentIndex]->course2, courseArr[course2Index].code); //copy the full course code of the course at index of course 2 into the new student data.

  /**convert the start and end times of the courses into integer values**/
  int course1StartTime = getTimeInt(courseArr[course1Index].time_start);
  int course1EndTime = getTimeInt(courseArr[course1Index].time_end);
  int course2StartTime = getTimeInt(courseArr[course2Index].time_start);
  int course2EndTime = getTimeInt(courseArr[course2Index].time_end);

  /**store status data**/
  if(isConflict(courseArr[course1Index].date, courseArr[course2Index].date, course1StartTime, course2StartTime, course1EndTime, course2EndTime)){ 
    strcpy(pArr[studentIndex]->status, "ATTENTION! time conflict\n");
    printf(pArr[studentIndex]->status);
  }else{
    strcpy(pArr[studentIndex]->status, "SUCCESSFUL! no time conflict\n");
    printf(pArr[studentIndex]->status);
  }
}

int getStudentIndex(struct db_type * pArr[SIZE]){
  int i;
  for(i=0; pArr[i]!=NULL; i++){} //iterate until we find a NULL reference. We can assume at least one exists because we can "assume the database is not full."
  return i; //return the index before the NULL index.
}

/**
 * Helper function that retrieves the index of a course based on the provided course code.
 * Input: courseCode, a string in the form of EECSXXXX or XXXX where X is an integer.
 * Output: the index of the course if found. If not found, -1.
 **/

int getCourseIndex(char courseCode[]){
  int i ;
  for(i = 0; strcmp(courseArr[i].code, "EECS0000"); i++){ //until we reach the sentinal course. 
    if(sameCourseName(courseArr[i].code, courseCode)){ //check if the given course code matches the code at the i index in the course array.
      return i; //if it matches, return the index
    }
  }
  return -1; //if course not found, return -1
}

/**
 * Helper function for getCourseIndex that determines whether the given code is the string EECSXXXX of the fullCode, or is XXXX of the fullCode.
 * Input: fullCode, the full course code string in the form EECSXXXX. code, the course code in the form XXXX or EECSXXXX.
 * Output: 1 if the codes match, else 0.
 **/

int sameCourseName(char fullCode[], char code[]){
  char digits [5];
  /**copy the course digits from the fullCode into digits.**/
  digits[0] = fullCode[4];
  digits[1] = fullCode[5];
  digits[2] = fullCode[6];
  digits[3] = fullCode[7];
  digits[4] = fullCode[8];

  if(!strcmp(fullCode, code) || !strcmp(digits, code)){ //if the code is either the full code, or if it is the digits.
    return 1;
  }
  return 0;
}

/**
 * Helper function that determines whether two courses have a timing conflict.
 * Input: date1, date2, the dates of the first and second courses as a char[].
 * start_time1, start_time2, the start times of the first and second courses as ints.
 * end_time1, end_time2, the end times of the first and second courses as ints.
 * Output: 1 if there is a timing conflict, else 0.
 **/

int isConflict(char date1[], char date2[], int start_time1, int start_time2, int end_time1, int end_time2){
  int i;
  int j;
  int datesSame = 0; //assume the dates don't overlap.
  for(i = 0; date1[i]!='\0'; i++){ //check if they do.
    for(j = 0; date2[j]!='\0'; j++){
      if(date1[i] == date2[j]){ //if any of the dates overlap.
        datesSame = 1;
        break;
      }
    }
  }

  if(!datesSame){ //if none of the dates overlap.
    return 0;
  }

  /**else check if the times overlap**/
  if(start_time1 <= start_time2 && end_time1 >= start_time2){
    return 1;
  }else if(start_time2 < start_time1 && end_time2 > start_time1){
    return 1;
  }
  return 0;
}

/**Helper function that converts a time string into an integer.
 * Input: a char[] in the form "X:X" where X is an int in 24-hour clock time.
 * Output: an integer form of the given time string.
 **/

int getTimeInt(char timeString[]){
  int hours;
  int minutes;
  sscanf(timeString, "%d:%d", &hours, &minutes); //parse the time string into hours and minutes.
  return hours*100 + minutes; //return the integer form.
}

/* display records */
void displayDB(struct db_type * pArr[]){

  printf("===============================");
  int i;
  for(i = 0; pArr[i]!=NULL; i++){ //iterate up to the last student.
    /**print age and name**/
    printf("\n\nname:\t %s", pArr[i]->name);
    printf("\nage:\t %d", pArr[i]->age);
    
    /**retrieve the index of the courses in the course array based on the student's data**/
    int course1Index = getCourseIndex(pArr[i]->course1);
    int course2Index = getCourseIndex(pArr[i]->course2);

    /**print all of the courses data**/
    printf("\ncourse1: %s\t%-40s%-5s %s-%s   %s\n", courseArr[course1Index].code, courseArr[course1Index].title, courseArr[course1Index].date, courseArr[course1Index].time_start, courseArr[course1Index].time_end, courseArr[course1Index].location);
    printf("course1: %s\t%-40s%-5s %s-%s   %s\n", courseArr[course2Index].code, courseArr[course2Index].title, courseArr[course2Index].date, courseArr[course2Index].time_start, courseArr[course2Index].time_end, courseArr[course2Index].location);
    printf("remarks: %s", pArr[i]->status);
  }
  printf("\n========== %d records ==========\n", getStudentIndex(pArr)); //the number of records is the last student index + 1.
}

/* remove an existing item */
void removeRecord (struct db_type * pArr[]){

  printf("enter full name to remove: ");
  char name[fieldLength];
  fgets(name, "%s", stdin); //get the name.
  name[strlen(name) - 1] = '\0'; //replace the '\n' with '\0'.

  int i;
  int found = 0; //assume the name wasn't found.
  for(i = 0; pArr[i]!=NULL; i++){ //iterate up to the last student index.
    if(!strcmp(name, pArr[i]->name)){ //check if the name is the same as the name data in pArr[i].
      pArr[i] = NULL; //set the PArr[i] to point to NULL.
      shiftPointerArray(i, pArr); //shift the pointer array downwards to fill the gap.
      found = 1;
    }
  }

  if(!found){ //inform the user if we found the name.
    printf("record not found\n");
  }else{
     printf("record [%s] removed successfully.\n", name);
  }
}

/**
 * Helper function that shifts the pointers in a pointer array of struct * db_type downward from the given index.
 * Input: index, an integer that indicates where to shift from. struct db_type * pArr[], an array of struct db_type * to be shifted.
 * Output: an array of pointers shifted downward starting from the index.
 **/

void shiftPointerArray(int index, struct db_type * pArr[]){
  int i;
  for(i = index; pArr[i]!=NULL; i++){ //iterate until the last student index.
    pArr[i] = pArr[i + 1]; //replace the i index with the one above it.
  }
  pArr[i] = NULL;
}

/* swap records */
void swap(struct db_type * pArr[]){
  int i;
  int lastStudentIndex = getStudentIndex(pArr); //get the last index.
  if(!(lastStudentIndex%2==0)){ //if the last index is odd.
    lastStudentIndex--; //decrement the lastStudentIndex.
  }

  for(i = 0; i < lastStudentIndex; i+=2){ //iterate up to the student index, incrementing by 2.
    /**swap the pointers of i and i + 1**/
    struct db_type * temp = pArr[i];
    pArr[i] = pArr[i + 1];
    pArr[i + 1] = temp;
  }
} 

/* load from course.txt, store into (global) array of courses  */
void init_courseArr(void){ 
   FILE *fr; //file pointer
   fr = fopen (courseFile, "r");
   char arr[50];  
   int count = 0;
   while ((fgets(arr,100,fr)) != NULL)
   {  
     strncpy(courseArr[count].code,  arr, strlen(arr)-1); // remove \n  
     courseArr[count].code[strlen(arr)-1] = '\0';  //to be safe
	 
     fgets(arr,100,fr);  
     strncpy(courseArr[count].title ,  arr, strlen(arr)-1);
     courseArr[count].title[strlen(arr)-1] = '\0';  //to be safe
     
          
     fgets(arr,100,fr); 
     strncpy(courseArr[count].date,  arr, strlen(arr)-1);
     courseArr[count].date[strlen(arr)-1] = '\0';  //to be safe
	   
     // other ways, remove \n before
     fgets(arr,100,fr);
     arr[strlen(arr)-1] = '\0';
     strcpy(courseArr[count].time_start,  arr);
      
     fgets(arr,100,fr);
     arr[strlen(arr)-1] = '\0';
     strcpy(courseArr[count].time_end,  arr);
      
     fgets(arr,100,fr);
     arr[strlen(arr)-1] = '\0';
     strcpy(courseArr[count].location,  arr); 
	  
     count++;
     fgets(arr,100,fr); // read the empty line
   }

   strcpy(courseArr[count].code, "EECS0000"); // a terminator token structure

   fclose(fr);
	 
 }
    
/************************ DISK IO *****************************************************************/

void writeDisk(struct db_type * pArr[]){
  FILE *fp;
  int i;

  if ( (fp=fopen(diskFile,"ab")) == NULL)
  {
    printf("cannot open file\n");
    return;
  }

  
  for (i=0; i< SIZE ; i++)
  {
     if ( pArr[i] != NULL)
     {  
       if (fwrite( pArr[i], sizeof(struct db_type), 1, fp) != 1)
       { 
          printf("file write error\n");
       }
     } 
   }
   fclose(fp);
}

void emptyDisk(void){

  FILE *fp;
  
  char c3[3];
  printf("are you sure to empty disk? (y) or (n)? ");
  fgets(c3,3,stdin);
  if(strcmp(c3, "y\n"))
     return;
 
  //else
  if ( (fp = fopen(diskFile,"w")) == NULL)
  {
     printf("no file to open\n");
     return;
  }
  fclose(fp); // open close, will empty the file
}


void loadDisk(struct db_type * pArr[]){
  FILE *fp;
  int i;
  char c3[3];
  printf("will overwrite current records. are you sure to load disk? (y) or (n)? ");
  fgets(c3,3,stdin);
  if(strcmp(c3, "y\n"))  
     return;

  struct db_type * tmp;
  
  if ( (fp = fopen(diskFile,"r")) == NULL)
  {
    printf("cannot open file\n");
    return;
  }

  init_list(pArr);
  for (i=0; i < SIZE ; i++)
  {
     tmp =  (struct db_type *) malloc (sizeof(struct db_type));   
	   
     if (fread( tmp, sizeof(struct db_type), 1, fp) != 1)
     {
       if (feof(fp))
       { fclose(fp); 
         return;
       }
       printf("file read error\n");
     }else{
      pArr[i] = tmp;
    }
  }
}

/****bonus*************************************************************************************/

/* sort the records by ages */
void sort(struct db_type * pArr[])
{
  int i; 
  int j;
  int index;
  for(i = 1; pArr[i]!=NULL; i++){ //iterate up to the last student index.
   index = i;
   for(j = i - 1; j>=0; j--){
    if(pArr[index]->age < pArr[index - 1]->age){ //if the age data pointed to by pArr[index] is less than the one pointed to by pArr[index + 1].
      /**swap the pointers**/
      struct db_type * ptr = pArr[index];
      pArr[index] = pArr[index - 1];
      pArr[index - 1] = ptr;
      index = j; //set the index to j.
    }
   }
  }
}