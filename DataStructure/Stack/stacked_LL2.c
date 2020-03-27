#include<stdio.h>
#include<stdlib.h>
/*
Summary : Stacked implementation of pop using dynamic implementation
used defined inputs
Date : 23 March 2020
*/
typedef struct node
{
    int info;
    struct node *next;
}*NODEPTR;
NODEPTR p;
/* --------------------------- function defination menu ---------------------*/
void freenode(NODEPTR p);
void showList(void);
NODEPTR getnode(void);
void push(int data);
void pop(void);
/* ---------------------------------------------------------------------------*/
NODEPTR getnode(void){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return(p); 
}
void freenode(NODEPTR p){
    free(p);
}
void push(int data ){
    NODEPTR q;
    q = getnode();
    q->info = data;
    q->next = p;
    p = q;
    printf("values inserted successfully \n ");
}
void pop(void){
    NODEPTR q;
    if (p == NULL){
        printf("void deletion \n");
        exit(1);
    }
    q = p;
    printf("popped item %d \n", p->info);
    p = p->next;
    freenode(q);
}
void showList(void){
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
int main()
{   
   int choice, value;
   printf("\n:: Stack using Linked List ::\n");
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
     case 1: printf("Enter the value to be insert: ");
         scanf("%d", &value);
         push(value);
         break;
     case 2: pop(); break;
     case 3: showList(); break;
     case 4: exit(0);
     default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}