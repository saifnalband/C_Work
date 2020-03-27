#include <stdio.h>
#include <stdlib.h>
/*Example 3 stacked implementation using linked list */
typedef struct node_type{
    int data;
    struct node_type *next;
} node;

typedef node *list;
list head=NULL;
void show_list();
void push(int n);
void pop();

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
     case 3: show_list(); break;
     case 4: exit(0);
     default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}
void push (int n){
    list temp;
    temp=(list)malloc(sizeof(node));
    temp->data=n;
    temp->next=head;
    head=temp;
    printf("\nInsertion is Success!!!\n");
    printf("Current Head->data:%d\n",head->data);
}
void pop(){
    list temp;
    if (head==NULL)
        printf("stack is empty\n");
    else{
        temp=(list)malloc(sizeof(node));
        temp=head;
        printf("deleted item %d ", temp->data);
        head=head->next;
        free(temp);
    }
}
void show_list(){
   if(head==NULL)
      printf("\nStack is Empty!!!\n");
   else{
        list temp;
        temp=(list)malloc(sizeof(node));
        temp=head; 
        while(temp->next!=NULL){
            printf("%d--->",temp->data);
            temp=temp->next;
        }
      printf("%d--->NULL",temp->data);
   }
} 