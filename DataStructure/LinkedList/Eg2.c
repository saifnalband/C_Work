#include <stdio.h>
#include <stdlib.h>
/* Example 2:  inserting in the end*/
typedef struct node_type{
    int data;
    struct node_type *next;
} node;

typedef node *list;
void show_list(list);
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
      tail=tail->next;
      printf("\n:: Enter More data Y/N\n");
      scanf(" \n %c",&ch);
   }
   printf("\n");
   show_list(head);
   printf("\n");
}
void show_list(list start){
    while(start!=NULL){
        printf("%d",start->data);
        start=start->next;
    }
    printf("\n");
}