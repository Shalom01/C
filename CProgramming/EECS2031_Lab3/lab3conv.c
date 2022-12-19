/***************************************
* EECS2031ON – Lab2 D
* Author: Asbell, Shalom
* Email: shalom01@my.yorku.ca
* eecs_username: shalom01
* York Student #: 215146954
****************************************/
#include <stdio.h>

/*JUSTIFICATION (for IF and FF returning the same values): 
In C, if you perform an operation on two values, and at least one is a float, 
the return will be a float value (value is expanded by C because there is no information lost). 
Integer truncation will only occur when performing an operation between two int values.*/

float fun_IF(int op1, char operator, float op2);
float fun_II(int op1, char operator, int op2);
float fun_FF(float op1, char operator, float op2);

int main(){

 int op1; float op2;  char operator;
 float resu, resu2, resu3;
 
 float a = 9/2;
 float b = 9*1.0/2;  // force 9 to be converted before /
 float c = 9/2*1.0;  // force 2 to be converted before /, but not working
 float c2 = 9/(2*1.0); // force 2 to be converted before /  
 float d = (float)9/2;  // cast 9 before /
 float e =  9/(float)2; // cast 2 before /
 float f = (float) (9/2); // cast after /, not working
 printf("9/2=%f  9*1.0/2=%f  9/2*1.0=%f   9/(2*1.0)=%f\n\n", a, b, c, c2);
 printf("(float)9/2=%f  9/(float)2=%f  (float)(9/2)=%f\n\n", d, e, f);
  
 // conversion in arithemetic
 printf("3.0*9/2/4=%f  9/2*3.0/4=%f  9*3/2*3.0/4=%f\n\n", 3.0*9/2/4, 9/2*3.0/4, 9/2*3.0/4);
 
 // conversion in assignment
 float f2  = 3.96;
 float f3 = 3.03;
 int i = f2; int j = f3;
 printf("i: %d  j: %d\n\n", i, j);

 //my code begins
 printf("Enter operand_1 operator operand_2 separated by blanks>");
 scanf("%d %c %f", &op1, &operator, &op2);
 while(op1!=-1 && op2!=-1){
    printf("Your input '%d %c %f' result in\n", op1, operator, op2);
    printf("%f (fun_IF)\n", fun_IF(op1, operator, op2));
    printf("%f (fun_IF)\n", fun_II(op1, operator, op2));
    printf("%f (fun_IF)\n\n", fun_FF(op1, operator, op2));
    
    printf("Enter operand_1 operator operand_2 separated by blanks>");
    scanf("%d %c %f", &op1, &operator, &op2);
    }

 return 0;
}
 
float fun_IF(int op1, char operator, float op2)
{
    if(operator=='+'){
        return op1 + op2;
    }else if(operator=='-'){
        return op1 - op2;
    }else if(operator=='*'){
        return op1*op2;
    }else if(operator=='/'){
        return op1/op2;
    }
}

float fun_II(int op1, char operator, int op2)
{  
    if(operator=='+'){
        return op1 + op2;
    }else if(operator=='-'){
        return op1 - op2;
    }else if(operator=='*'){
        return op1*op2;
    }else if(operator=='/'){
        return op1/op2;
    }
}

float fun_FF(float op1, char operator, float op2)
{
    if(operator=='+'){
        return op1 + op2;
    }else if(operator=='-'){
        return op1 - op2;
    }else if(operator=='*'){
        return op1*op2;
    }else if(operator=='/'){
        return op1/op2;
    }
}

 
