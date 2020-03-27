#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node_type{
    int data;
    struct node_type *next;
} node;

typedef node *list;
int main()
{
   int n;
   char ch;
   list head,tail;
   head=tail=NULL;
   printf("\n:: Enter the data Y/N \n");
   scanf("%c",&ch);  
   if (ch =='y' || ch =='Y'){
      printf("Give data: \n");
      scanf("%d", &n);
      tail=(list)malloc(sizeof(node));
      tail->data=n;
      tail->next=NULL;
      head=tail;
         printf("\n:: Enter More data Y/N\n");
   scanf(" \n %c",&ch);
   }
   while (ch =='y' || ch =='Y'){
      printf("Give data: \n");
      scanf("%d", &n);
      tail->next=(list)malloc(sizeof(node));
      tail->next->data=n;
      tail->next->next=NULL;
      head=tail;
               printf("\n:: Enter More data Y/N\n");
   scanf(" \n %c",&ch);
   }

   temp=head;
   while (temp!=NULL){
    printf("%d\n",temp->data );
    temp=temp->next;
   }
}
void showlist(list head){
    while(head !=NULL){
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");
}