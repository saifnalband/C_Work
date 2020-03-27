#include<stdio.h>
int x;
int x = 10;
int main() 
{ 
   // int x; 
   // int x = 5; 
   printf("%d", x); 
   printf("Size of int = %ld\n", sizeof(int)); 
   printf("Size of long = %ld\n", sizeof(long)); 
   printf("Size of long long = %ld \n", sizeof(long long)); 
   return 0;  
} 
/* C allows global deaclartion to be declared but C++ doesn't */