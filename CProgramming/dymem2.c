#include<stdio.h>
#include<stdlib.h>
int main(){
	// this pointer will hold the base address
	int *ptr, *ptr2;
	int n, i;

	// get the number of array
	n = 5;
	printf("The Number of elements entered %d \n", n);

	// dynamically allocating the memory using malloc
	// ptr = (cast-type*)calloc(n, element-size);
	ptr = (int*)malloc(n * sizeof(int));
	ptr2 = (int*)calloc(n, sizeof(int));
	

	// check if memory has been succuessfully allocated by malloc
	if ( ptr == NULL || ptr2 == NULL){
		printf("MEMEORY not ALLOCATED \n");
		exit(0);
	}
	else {
		printf("MEMEORY ALLOCATED \n");

		// free ptr
		free(ptr);
		printf("PTR is free \n");

		// free ptr2
		printf("Malloc Memory successfully freed.\n"); 
  
        	// Memory has been successfully allocated 
        	printf("\nMemory successfully allocated using calloc.\n"); 
  
        	// Free the memory 
        	free(ptr2); 
        	printf("Calloc Memory successfully freed.\n"); 
	}
	return 0;
}
