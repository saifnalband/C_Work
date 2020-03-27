
#include<stdio.h> 
  
/* Swaps strings by swapping pointers */ 
void swap1(char **str1_ptr, char **str2_ptr) 
{ 
  char *temp = *str1_ptr; 
  *str1_ptr = *str2_ptr; 
  *str2_ptr = temp; 
}   
   
int main() 
{ 
  char *str1 = "geeks"; 
  char *str2 = "forgeeks"; 
  swap1(&str1, &str2); 
  printf("str1 is %s, str2 is %s", str1, str2); 
  getchar(); 
  return 0; 
} 
// https://computeroxy.com/postdoctoral-positions-in-machine-learning-and-medical-imaging,i9081.html
// https://computeroxy.com/postdoctoral-scholar-in-data-science-and-movement-data-analytics,i9147.html
// https://computeroxy.com/postdoc-position-in-machine-learning-in-biomedicine,i9101.html
// https://wpi.wd5.myworkdayjobs.com/en-US/WPI_External_Career_Site/login