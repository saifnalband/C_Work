#include <stdio.h>
#include <stdlib.h>
/* inserting in the begining*/
typedef struct node_type{
    int data;
    struct node_type *next;
} node;

typedef node *list;
int main()
{
   int n;
   char ch;
   list head,temp;
   head=NULL;
   printf("\n:: Enter the data Y/N \n");
   scanf("%c",&ch);
   while (ch =='y' || ch =='Y'){
      printf("Give data: \n");
      scanf("%d", &n);
      temp=(list)malloc(sizeof(node));
      temp->data=n;
      temp->next=head;
      head=temp;
         printf("\n:: Enter More data Y/N\n");
   scanf(" \n %c",&ch);

   }
   temp=head;
   while (temp!=NULL){
    printf("%d\n",temp->data );
    temp=temp->next;
   }
}
