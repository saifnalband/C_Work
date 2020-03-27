#include<stdio.h>
struct Point{
	int x, y;
};
int main(){
	struct Point p1 = {1, 2};
	// p2 is the pointer to p2
	struct Point *p2 = &p1;

	// accessing the elemet from pointer p2
	printf(" x = %d, y = %d \n", p2->x,p2->y);
	return 0;
}
