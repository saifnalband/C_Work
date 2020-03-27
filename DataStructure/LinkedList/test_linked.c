#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}*NODEPTR;
/* --------------------------- function defination menu ---------------------*/
void freenode(NODEPTR p);
void showList(NODEPTR p);
NODEPTR getnode(void);
NODEPTR insertFirst(NODEPTR p, int data);
NODEPTR deleteFirst(NODEPTR p);
/* ---------------------------------------------------------------------------*/
NODEPTR getnode(void){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return(p); 
}
void freenode(NODEPTR p){
    free(p);
}
NODEPTR insertFirst(NODEPTR p, int data ){
    NODEPTR q;
    q = getnode();
    q->info = data;
    q->next = p;
    p = q;
    // printf("values inserted successfully \n ");
    return p;
}
NODEPTR deleteFirst(NODEPTR p){
    NODEPTR q;
    if (p == NULL){
        printf("void deletion \n");
        exit(1);
    }
    q = p;
    printf("deleted item %d \n", p->info);
    p = p->next;
    freenode(q);
    return p;
}
void showList(NODEPTR p){
    NODEPTR tmp;
    // tmp = getnode();
    tmp = p;
    while (tmp != NULL)    {
        printf(" %d --> ",tmp->info);
        tmp = tmp->next;
    }
    printf(" NULL \n");
}
int main(){
    NODEPTR p;
    p = insertFirst(p, 20);
    p = insertFirst(p, 30);
    p = insertFirst(p, 40);
    p = insertFirst(p, 50);
    showList(p);
    p = deleteFirst(p);
    showList(p);
    p = insertFirst(p, 60);
    p = deleteFirst(p);
    p = insertFirst(p, 70);
    showList(p);
}
