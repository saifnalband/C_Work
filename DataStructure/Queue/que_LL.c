/* This is Queue representation
Method : Linked List (Dynamic Implemenation 
Date : 25/03/2020 */
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
} *NODEPTR;
struct queue{
    NODEPTR front, rear;
};
/* ---------------FUNCTION MENU --------------*/
int empty (struct queue *pq);
void insert_val(struct queue *pq, int x);
int remove_val(struct queue *pq);
void display_queue(NODEPTR p);
NODEPTR getnode(void);
void freenode(NODEPTR p);
/* ------------------------------------------- */
NODEPTR getnode(void){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}
void freenode(NODEPTR p){
    free(p);
}
void insert_val(struct queue *pq, int x){
    NODEPTR p;
    p = getnode();
    p->info = x;
    p->next = NULL;
    if(pq->rear == NULL)
        pq->front = p;
    else
        (pq->rear)->next = p;
    pq->rear = p;
    printf(" VALUE INSERTED IN QUEUE: %d \n", x);
}
int remove_val(struct queue *pq){
    int x;
    NODEPTR p;
    if(empty(pq)){
        printf("queue underflow \n");
        exit(1);
    }
    p = pq->front;
    x = p->info;
    pq->front = p->next;
    if(pq->front == NULL)
        pq->rear = NULL;
    freenode(p);
    return(x);
}
int empty(struct queue *pq){
	return((pq->front == pq->rear)?1:0);
}
void display_queue(NODEPTR p){
    NODEPTR tmp = p;
    printf(" The Elements in the queue are as follows : \n");
    printf(" pq->front : %d \n", tmp->info);
    while(tmp != NULL){
        printf(" %d -> ", tmp->info);
        tmp = tmp->next;
    }
    printf(" NULL \n");
}
/* ---------------------- hardcode menu ------------------------*/
/* int main(){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->front = q->rear = NULL;
	insert_val(q,10);
	insert_val(q,20);
	insert_val(q,30);
	insert_val(q,40);
	insert_val(q,50);
    display_queue(q->front);
    printf(" VALUE REMOVED FROM QUEUE %d \n",remove_val(q)); 
    printf("Queue Front : %d \n", q->front->info); 
    printf("Queue Rear : %d \n", q->rear->info); 
    return 0;
}*/
/* ---------------------- User Menu ------------------------*/
int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    int choice, value;
    printf("\n:: Queue Implementation using Linked List ::\n");
    while(1){
      printf("\n************** QUEUE MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4.Display Front element.\n5. Display Rear Element\n6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	  case 1: printf("Enter the value to be insert: ");
		 scanf("%d", &value);
		 insert_val(q, value);
		 break;
	 case 2: remove_val(q); break;
	 case 3: display_queue(q->front); break;
     case 4: printf(" FRONT ELEMENT is %d \n", q->front->info); break;
     case 5: printf(" REAR ELEMNT is %d \n", q->rear->info); break;
	 case 6: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}
/* ---------------------------------------------------------------------- */