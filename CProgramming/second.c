#include<stdio.h>
/* copy input to output */
int main(){
  int c;
  /* c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }*/
  // v2
  int nc;
  nc = 0;
  while ((c = getchar()) != '\n') {
    /* code */
    // putchar(c);
    ++nc;
  }
  printf("%d\n",nc );
}
