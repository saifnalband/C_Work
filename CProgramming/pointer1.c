
#include <stdio.h> 
void printArray(int arr[], int n);
  
int main() 
{ 
   int arr[] = {10, 20, 30, 40, 50, 60}; 
   int *ptr = arr; 
   int n = sizeof(arr) / sizeof(arr[0]); 
   printArray(arr, n);
   printf("arr[2] = %d\n", arr[2]); 
   printf("*(arr + 2) = %d\n", *(arr + 2)); 
   printf("ptr[2] = %d\n", ptr[2]); 
   printf("*(ptr + 2) = %d\n", *(ptr + 2)); 
   return 0; 
} 
void printArray(int arr[], int n) 
{ 
    int i;
    printf("--------- ARRAY is ----------------------\n"); 
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]); 
        // printf("%d ",i);
    }
    printf("\n---------------------------------------\n"); 
} 