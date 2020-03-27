#include<stdio.h>
int binsearch(int x, int v[],int n);
void printArray(int arr[], int n);
int binarySearch(int arr[], int x, int n) ;
int main(){
    int arr[] = {2, 5, 8, 77, 9, 56, 89};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int found;
    int find_element = 9;
    printArray(arr, n);
    // found = binsearch(find_element,arr,n);
    found = binarySearch(arr,find_element, n); 
    if (found == -1)
        printf("element not found");
    else
        printf("found at %d position \n", found);
}
int binsearch(int x, int v[], int n){
    int low, high, mid;


        
}
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
int binarySearch(int arr[], int x, int n) 
{ 
    int l = 0;
    int r = n - 1;
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
} 
