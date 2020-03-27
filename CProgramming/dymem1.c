#include<stdio.h>
#include<stdlib.h>
int main(){
	// this pointer will hold the base address
	int* ptr;
	int n, i;

	// get the number of array
	n = 5;
	printf("The Number of elements entered %d \n", n);

	// dynamically allocating the memory using malloc
	// ptr = (cast-type*)calloc(n, element-size);
	ptr = (int*)malloc(n * sizeof(int));

	// check if memory has been succuessfully allocated by malloc
	if ( ptr == NULL){
		printf("MEMEORY not ALLOCATED \n");
		exit(0);
	}
	else {
		printf("MEMEORY ALLOCATED \n");
		// get the elements
		for( i = 0; i < n; ++i){
			ptr[i] = i + 1;
		}

		printf("The elements are as follows \n");
		for ( i = 0; i < n; ++i){
			printf(" %d ", ptr[i] );
		}
	}
	return 0;
}
