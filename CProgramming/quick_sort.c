#include<stdio.h>
void printArray(int arr[], int n);
void qsort( int v[], int left, int right);
int main(){
    int arr[] = {2, 5, 8, 77, 9, 56, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array: ");
    printArray(arr, n);
    printf("------------------------ \n");
    printf("--------------- sorted array----------");
    
}