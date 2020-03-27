
#include <stdio.h> 
  
int main() 
{ 
  
    // Null pointer 
    char* np = NULL; 
  
    // Pointer to null pointer 
    char** pnp = &np; 
  
    if (*pnp == NULL) { 
        printf("Pointer to a null pointer is valid\n"); 
    } 
    else { 
        printf("Pointer to a null pointer is invalid\n"); 
    } 
  
    return 0; 
} 
/* What happens here is that when a Null pointer is created, it points to null, 
without any doubt. But the variable of Null pointer takes some memory.*/