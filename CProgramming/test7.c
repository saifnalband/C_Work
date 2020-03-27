#include <errno.h> 
#include <stdio.h> 
// #include <string.h> 
int main(int argc, char *argv[]) 
{ 
    FILE *fp; 
  
    fp = fopen(argv[1], "r"); 
    if (fp == NULL) { 
        fprintf(stderr, "%s\n", strerror(errno)); 
        return errno; 
    } 
  
    printf("file exist\n"); 
  
    fclose(fp); 
  
    return 0; 
} 
/* In C language, when we don’t provide prototype of function, 
the compiler assumes that function returns an integer. 
In our example, we haven’t included “string.h” header file 
(strerror’s prototype is declared in this file), that’s why compiler 
assumed that function returns integer. But its return type is pointer to 
character. In x86_64, pointers are 64-bit wide and integers are 
32-bits wide, that’s why while returning from function, the returned address 
gets truncated (i.e. 32-bit wide address, which is size of integer on x86_64)
which is invalid and when we try to dereference this address, 
the result is segmentation fault. */ 