#include<stdio.h>
#include<stdlib.h>
/*
Summary : Stacked implementation of pop using dynamic implementation
Hard coded
Date : 23 March 2020
*/
typedef struct node
{
    int info;
    struct node *next;
}*NODEPTR;
/* --------------------------- function defination menu ---------------------*/
void freenode(NODEPTR p);
void showList(NODEPTR p);
NODEPTR getnode(void);
NODEPTR push(NODEPTR p, int data);
NODEPTR pop(NODEPTR p);
/* ---------------------------------------------------------------------------*/
NODEPTR getnode(void){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return(p); 
}
void freenode(NODEPTR p){
    free(p);
}
NODEPTR push(NODEPTR p, int data ){
    NODEPTR q;
    q = getnode();
    q->info = data;
    q->next = p;
    p = q;
    // printf("values inserted successfully \n ");
    return p;
}
NODEPTR pop(NODEPTR p){
    NODEPTR q;
    if (p == NULL){
        printf("void deletion \n");
        exit(1);
    }
    q = p;
    printf("popped item %d \n", p->info);
    p = p->next;
    freenode(q);
    return p;
}
void showList(NODEPTR p){
    NODEPTR tmp;
    tmp = getnode();
    tmp = p;
    while (tmp != NULL)    {
        printf(" | %d | \n ",tmp->info);
        printf("------- \n");
        tmp = tmp->next;
    }
    printf("  NULL \n");
}
int main(){
    NODEPTR p;
    p = push(p, 20);
    p = push(p, 30);
    p = push(p, 40);
    p = push(p, 50);
    showList(p);
    p = pop(p);
    showList(p);
}