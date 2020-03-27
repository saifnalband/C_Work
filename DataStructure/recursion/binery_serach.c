#include<stdio.h>
void printArray(int arr[], int n);
int binsearch(int low, int high) ;
int main(){
    extern int arr[] = {2, 5, 8, 77, 9, 56, 89};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int found;
    extern int find_element = 9;
    printArray(arr, n);
    // found = binsearch(find_element,arr,n);
    found = binsearch(arr,find_element, n); 
    if (found == -1)
        printf("element not found");
    else
        printf("found at %d position \n", found);
}
int binsearch(int low, int high){
    int mid;
    if(low>high)
	    return(-1);
    mid = (low + high)/2;
    return(find_element == a[mid] ? mid: find_element < a[mid]? binsearch(low, mid-1):binsearch(mid+1,high));
}
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
