#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 10
struct stack{
	int top;
	int items[STACKSIZE];
};
int empty (struct stack *ps){
	if (ps->top == -1)
		return 1;
	else
		return 0;
}

int pop(struct stack *ps){
	if(empty(ps)){
		printf("stack underflow \n");
		exit(1);
	}
	return(ps->items[ps->top--]);
}
int push(struct stack *ps, int x){
	if(ps->top == STACKSIZE-1){
		printf("stack overflow \n");
		exit(1);
	}
	else{
		ps->items[++(ps->top)] = x;
		printf("element pushed successfully: %d \n", x);
	}
	return 1;
}
int stacktop(struct stack *ps){
	if(empty(ps)){
		printf("stack underflow \n");
		exit(1);
	}
	else
		return(ps->items[ps->top]);
}
// Driver program to test above functions 
int main() 
{ 
    struct stack st; 
    
    return 0; 
} 
