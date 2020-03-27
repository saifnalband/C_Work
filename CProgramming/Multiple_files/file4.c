#include<stdio.h>
#include "file3.c"

extern int x, y, z;
int main(){
	func_1();
	printf("%d %d %d \n", x, y, z);
	func_2();
	func3();
	func3();
	func4();
	printf("%d %d %d \n", x, y, z);
}
void func3(){
	static int b;
	y++;
	b++;
	printf("%d %d %d %d \n", x, y, z, b);	
}
void func4(){
	int x, y, z;
	x = 10;
	y = 20;
	z = 30;
	printf("%d %d %d \n", x, y, z);
}
