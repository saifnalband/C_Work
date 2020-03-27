/* This is Circular Queue representation
Method : Linked List (Dynamic Implemenation 
Date : 27/03/2020 */
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
} *NODEPTR;
/* ---------------FUNCTION MENU --------------*/
int empty (NODEPTR pq);
NODEPTR insert_val(NODEPTR pq, int x);
int remove_val(NODEPTR pq);
void display_queue(NODEPTR p);
NODEPTR getnode(void);
void freenode(NODEPTR p);
void show_element(NODEPTR p);
/* ------------------------------------------- */
NODEPTR getnode(void){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}
void freenode(NODEPTR p){
    free(p);
}
int empty(NODEPTR pq){
	return((pq == NULL)?1:0);
}
int remove_val(NODEPTR pq){
    int x;
    NODEPTR p;
    if (empty(pq) == 1){
        printf("stack underflow \n");
        exit(1);
    }
    p = pq -> next;
    x = p ->info;
    if( p == pq)
         pq = NULL;
    else
         pq ->next = p -> next;
    freenode(p);
    return(x);
}
NODEPTR insert_val(NODEPTR pq, int x){
    NODEPTR p;
    p = getnode();
    p->info = x;
    if(empty(pq)==1)
        p->next = p;
    else {
        p->next = pq->next;
        pq ->next = p;
    }
    pq = p;
    printf(" %d Value insiereted in ciruclar Queue \n", x);
    return pq;
}
void show_element(NODEPTR pq){
    NODEPTR tmp;
    tmp = pq;
    int count = 0;
    if(tmp == NULL){
        printf(" EMPTY LIST \n");
        exit(1);
    }
    // printf(" Address of tmp: %d \n", tmp->next);
    // printf(" Address of pq: %d \n", pq->next);
    printf("element in the circular list are as follows: \n");
    do
    {
        printf(" %d -> ", tmp->info);
        tmp = tmp->next;
        count++;
    } while (tmp != pq);
    
    printf("\n");
    /*while( tmp != pq){
        printf(" %d -> ", tmp->info);
        tmp = tmp->next;
        count++;
    }*/
    printf("the number of elements in the circular queue are : %d \n", count);
}
int main(){
    NODEPTR pq;
    pq = insert_val(pq, 10);
    pq = insert_val(pq, 20);
    pq = insert_val(pq, 30);
    pq = insert_val(pq, 40);
    pq = insert_val(pq, 50);
    pq = insert_val(pq, 60);
    pq = insert_val(pq, 70);
    show_element(pq);
    printf(" %d Vale deleted from Circular queue \n", remove_val(pq));
    printf(" %d Vale deleted from Circular queue \n", remove_val(pq));
    printf(" %d Vale deleted from Circular queue \n", remove_val(pq));
    pq = insert_val(pq, 90);
    show_element(pq);
    printf(" %d Vale deleted from Circular queue \n", remove_val(pq));
    printf(" %d Vale deleted from Circular queue \n", remove_val(pq));
    printf(" %d Vale deleted from Circular queue \n", remove_val(pq));
    printf(" %d Vale deleted from Circular queue \n", remove_val(pq));
    return 0;
}