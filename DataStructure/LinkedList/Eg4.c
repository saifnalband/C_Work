#include <stdio.h>
#include <stdlib.h>
/*Example 4 Complete linked list */
typedef struct node_type{
    int data;
    struct node_type *next;
} node;
typedef node *list;
list head,tail=NULL;
void insert_Begin(int);
void insert_End(int);
void insert_after(int, int);
void insert_before(int, int);
void delete_element(int);
void show_list();

void insert_Begin(int n){
	list temp;
    temp=(list)malloc(sizeof(node));
    temp->data=n;
    temp->next=head;
    head=temp;
    printf("\nInsertion is Success!!!\n");
    printf("Current Head->data:%d\n",head->data);
}

void insert_End(int n){
	/*inserting the first element */
	if (head==NULL && tail==NULL)
	{
	  tail=(list)malloc(sizeof(node));
      tail->data=n;
      tail->next=NULL;
      head=tail;
	}
	else {
		list temp;
		temp= head;
		while(temp->next!=NULL){
			temp=temp->next; 
		}
	  temp->next=(list)malloc(sizeof(node));
      temp->next->data=n;
      temp->next->next=NULL;
      tail=temp->next;
		
	}
printf("\nInsertion is Success!!!\n");
printf("Current Head->data:%d\n",head->data);
}

void insert_after(int n, int prev_n){
		list temp,new1;
		temp= head;
		while(temp->data!=prev_n){
			temp=temp->next; 
		}
	  new1=(list)malloc(sizeof(node));
      new1->data=n;
      new1->next= temp->next;
  	  temp->next = new1;
}
void insert_before(int n, int next_n){
			list temp,new1;
		temp= head;
		if (temp->data==next_n){
		temp=(list)malloc(sizeof(node));
    	temp->data=n;
    	temp->next=head;
    	head=temp; 
}
else {
		while(temp->next->data!=next_n){
			temp=temp->next; 
		}
	  new1=(list)malloc(sizeof(node));
      new1->data=n;
      new1->next= temp->next;
  	  temp->next = new1; }
}

void delete_element(int n){
	list temp,prev;
	temp=head;
	if (temp != NULL && temp->data == n)
    {
        head = temp->next;   
        free(temp);               
        return;
    }
     /*Search for the key to be deleted, keep track of the
     previous node as we need to change 'prev->next'*/
    while (temp != NULL && temp->data != n)
    {
        prev = temp;
        temp = temp->next;
    }
 
    /* If key was not present in linked list*/
    if (temp == NULL) {
    	printf("element not present in linked list\n");
    };
 
    /* Unlink the node from linked list*/
    prev->next = temp->next;
 
    free(temp); 
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

/* Program main */ 
int main()
{
   int num, prev_num, next_num;
   int option;
   char * temp;
   char ch;
   /* Display Menu */
   while(1) {

     printf("\n ***********************************\n");
     printf("\n *  Linked list operations:        *\n");
     printf("\n *  1. Insert at the top of list   *\n");
     printf("\n *  2. Insert at bottom of list    *\n");
     printf("\n *  3. Insert after an element     *\n");
     printf("\n *  4. Insert before an element    *\n");
     printf("\n *  5. Show all elements           *\n");
     printf("\n *  6. Delete an element           *\n");
     printf("\n *  7. Quit                        *\n");
     printf("\n ***********************************\n");
     printf("\n Choose an option [1-5] : ");
     if (scanf("%d", &option) != 1) {
        printf(" *Error: Invalid input. Try again.\n");
        scanf("%s", &temp); /*clear input buffer */
        continue;
     }

     switch (option) {
      case 1:        /* Add to top*/
          printf(" Enter a number to insert : ");
          if (scanf("%d", &num) != 1) {
              printf(" *Error: Invalid input.\n");
              scanf("%s", &temp);   /*clear input buffer */
              continue;
          }
          insert_Begin(num);
          printf("Number %d added to the top of the list", num);
          printf("\nPress any key to continue...");
          getch();
          break;

      case 2:    /* add to bottom */
          printf(" Enter a number to insert : ");
          if (scanf("%d", &num) != 1) {
              printf(" *Error: Invalid input. \n");
              scanf("%s", &temp); 
              continue;
          }
          insert_End(num);
          printf("%d added to the bottom of the list", num);
          printf("\nPress any key to continue...");
          getch();
          break;

      case 3:    /* Insert After */
          printf(" Enter a number to insert : ");
          if (scanf("%d", &num) != 1) {
              printf(" *Error: Invalid input.\n");
              scanf("%s", &temp);  
              continue;
          }

          printf(" After which number do you want to insert : ");
          if (scanf("%d", &prev_num) != 1) {
              printf(" *Error: Invalid input.\n");
              scanf("%s", &temp);
              continue;
          }
          if (head != NULL) {
              insert_after(num, prev_num);
              printf("%d is inserted after %d", num, prev_num);
          }else {
              printf("The list is empty", num, prev_num);
          }
              printf("\nPress any key to continue...");
              getch();
              break;

       case 4:    /* Insert Before */
           printf(" Enter a number to insert : ");
           if (scanf("%d", &num) != 1) {
              printf(" *Error: Invalid input. \n");
              scanf("%s", &temp);
              continue;
          }

          printf(" Before which number do you want to insert : ");
          if (scanf("%d", &prev_num) != 1) {
              printf(" *Error: Invalid input.\n");
              scanf("%s", &temp);
              continue;
          }

        if (head != NULL) {
             insert_before(num, prev_num);
             printf("Number %d inserted before %d", num, prev_num);
         }else {
             printf("The list is empty", num, prev_num);
         }
             printf("\nPress any key to continue...");
            getch();
            break;

      case 5: /* Show all elements */
          printf("\nElements in the list: \n [ ");
          show_list();
          printf("]\n\nPress any key to continue...");
          getch();
          break;

          case 6:    /* Delete element */
           printf(" Enter a number to delete : ");
           if (scanf("%d", &num) != 1) {
              printf(" *Error: Invalid input. \n");
              scanf("%s", &temp);
              continue;
          }
        if (head != NULL) {
             delete_element(num);
             printf("Number %d deleted", num);
         }else {
             printf("The list is empty");
         }
             printf("\nPress any key to continue...");
            getch();
            break;

      case 7:  /* Exit */
          return(0);
          break;

      default:
          printf("Invalid Option. Please Try again.");
          getch();

      } /* End of Switch */
   } /* End of While */

return(0);
}

