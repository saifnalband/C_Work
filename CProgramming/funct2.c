
#include <stdio.h> 
  
char fun() 
{ 
   return 'G'; 
} 
  
int main(void) 
{ 
    // Note that fun() is not declared  
    printf("%d\n", fun()); 
    return 0; 
} 
