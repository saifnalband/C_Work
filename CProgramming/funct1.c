
#include <stdio.h> 
int main(void) 
{ 
    // Note that fun() is not declared  
    printf("%d\n", fun()); 
    return 0; 
} 
  
char fun() 
{ 
   return 'G'; 
} 
/* In C, if a function is called before its declaration, 
the compiler assumes return type of the function as int.*/