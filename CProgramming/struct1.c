#include<stdio.h>
struct Point{
	int x, y;
};
int main(){
	struct Point p1 = {0,1};
	// accessing the point
	p1.x = 20;
	printf(" x = %d , y = %d \n", p1.x, p1.y);
	return 0;
}
