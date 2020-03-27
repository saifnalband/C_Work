#include<stdio.h>
int main() {
  /* code */
  int year = 2020;
  if((year % 4 == 0 && year % 100 != 0)|| year % 400 == 0)
    printf("its leap year\n");
  else
    printf("NOT LEAP year\n");
}
