#include<stdio.h>
void display_array() 
{ 
    // Declare an array 
    int val[3] = { 5, 10, 15}; 
  
    // Declare pointer variable 
    int *ptr; 
  
    // Assign address of val[0] to ptr. 
    // We can use ptr=&val[0];(both are same) 
    ptr = val ; 
    printf("Elements of the array are: \n"); 
    printf(" ptr[0]: %d \n ptr[1]: %d \n ptr[2]: %d \n", ptr[0], ptr[1], ptr[2]); 
  
    return; 
} 
  
// Driver program 
int main() 
{ 
    display_array(); 
    return 0; 
} 