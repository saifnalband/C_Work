#include<stdio.h>
int main(){
	int i;
	for(i = 0; i<10; i++){
		LOOP:
		break;
		printf("%d ", i);
		goto LOOP;
	}
	return 0;
}
