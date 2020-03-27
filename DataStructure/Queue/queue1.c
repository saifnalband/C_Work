#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 5
struct queue{
	int items[MAXQUEUE];
	int front, rear;
};
int front_element(struct queue *pq);
int rear_element(struct queue *pq);
int empty(struct queue *pq);
int remove_val(struct queue *pq);
void insert_val(struct queue *pq, int x);
int main(){
	struct queue q;
	q.front = q.rear = MAXQUEUE-1;
	insert_val(&q,10);
	insert_val(&q,20);
	insert_val(&q,30);
	printf("%d dequeued from queue\n\n", remove_val(&q));
    printf("Front item is %d\n", front_element(&q));
    printf("Rear item is %d\n", rear_element(&q));
    return 0;	
}

int front_element(struct queue *pq){
	if(empty(pq)){
		printf("queue EMPTY \n");
		exit(1);
	}
	return(pq->items[pq->front]);
}
int rear_element(struct queue *pq){
	if(empty(pq)){
		printf("queue EMPTY \n");
		exit(1);
	}
	return(pq->items[pq->rear]);
}
int empty(struct queue *pq){
	return((pq->front==pq->rear)?1:0);
}
int remove_val(struct queue *pq){
	if(empty(pq)){
		printf("queue underflow \n");
		exit(1);
	}
	if(pq->front == MAXQUEUE-1)
		pq->front = 0;
	else
		// pq->front = pq->front + 1; 
		(pq->front)++;
	printf("FRONT Item : %d \n", pq->items[pq->front]);
	return(pq->items[pq->front]);
}
void insert_val(struct queue *pq, int x){
	if(pq->rear == MAXQUEUE-1)
		pq->rear = 0;
	else
		(pq->rear)++;
	if(pq->rear == pq->front){
		printf("queue overflow \n");
		exit(1);
	}
	pq->items[pq->rear] = x;
	printf("%d enqueued to queue\n", x); 
	return;
}
