#include<stdio.h>
#include<stdlib.h>
/* ----------- Linked List Representation: --------------
Method : dynamic memory allocation
Problem : Print reverse Linked List
Date : 24 March 2020
Arthor : Dr. Saif Nalband
--------------------------------------------------------- */
typedef struct node
{
    int info;
    struct node *next;
}*NODEPTR;
/* --------- FUNCTION MENU --------------------------------- */
void freenode(NODEPTR p);
void show_List(NODEPTR p);
NODEPTR getnode(void);
NODEPTR insertFirst(NODEPTR p, int data);
NODEPTR insertLast(NODEPTR p, int data);
void insert_position(NODEPTR p,int data, int pos);
NODEPTR deleteFirst(NODEPTR p);
NODEPTR deleteLast(NODEPTR p);
void delete_position(NODEPTR p,int pos);
NODEPTR reverse_LL(NODEPTR p);
void remove_dublicate(NODEPTR p);
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
NODEPTR insertLast(NODEPTR p, int data){
    NODEPTR tmp,q;
    tmp = p;
    while (tmp != NULL && tmp->next != NULL){
        tmp = tmp->next;
    }
    q = getnode();
    q->info = data;
    q->next = NULL;
    if (tmp != NULL)
        tmp->next = q;
    else
        p = q;
    return p;
}
void insert_position(NODEPTR p,int data, int pos){
    NODEPTR q,tmp;
    int count = 1;
    tmp = p;
    if(p == NULL){
        printf("void insertion \n");
        exit(1);
    }
    while (count != (pos - 1)){
        tmp = tmp->next;
        count++;
    }
    
    q = getnode();
    q->info = data;
    q->next = tmp->next;
    tmp->next = q;
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
NODEPTR deleteLast(NODEPTR p){
    NODEPTR tmp;
    if (p == NULL)
        return NULL;
    if (p->next == NULL){
        freenode(p);
        return NULL;
    }
    tmp = p;
    while (tmp->next->next != NULL){
        tmp = tmp->next;
    }
    freenode(tmp->next);

    tmp->next = NULL;
    return p;
}
void delete_position(NODEPTR p,int pos){
    NODEPTR tmp,q;
    tmp = p;
    if(p == NULL){
        printf(" LINKED LIST IS EMPTY !!!!! \n ");
        return;
    }
    if( pos == 1){
        p = tmp->next;
        freenode(tmp);
        // printf(" Linked List had one Element and element was Deleted !!! \n");
        return;
    }
    for (int i = 1; i < pos-1; i++)    {
        tmp = tmp->next;
    }
    // q = getnode();
    q = tmp->next->next;
    freenode(tmp->next);
    tmp->next = q;   
} 
void show_List(NODEPTR p){
    NODEPTR tmp;
    tmp = p;
    if(p == NULL){
        printf("LINKED LIST EMPTY \n");
        return;
    }
    while (tmp != NULL){
        printf(" %d --> ", tmp->info);
        tmp = tmp->next;
    }
    printf(" NULL \n");
}
NODEPTR reverse_LL(NODEPTR p){
    NODEPTR prev = NULL;
    NODEPTR current = p;
    NODEPTR next = NULL;

    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    p = prev;
    return p;
}
void remove_dublicate(NODEPTR p){
    NODEPTR tmp1, tmp2, rm1;
    tmp1 = p;
    while(tmp1 != NULL && tmp1->next != NULL){
        tmp2 = tmp1;
        while(tmp2->next != NULL){
            if(tmp1->info == tmp1->next->info){
                rm1 = tmp2->next;
                tmp2->next = tmp2->next->next;
                freenode(rm1);
            }
            else
                tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
}
/* ---------------------------------------------------------------------- 
--------------- MAIN FUNCTION ------------------------------------------
------------------------------------------------------------------------- */

int main(){
    int choice, num,afterNum, beforeNum, position;
    NODEPTR p = NULL;
    NODEPTR tmp1;
    printf("\n:: ----------Linked List ----------- ::\n");
    while(1){
      printf("\n*************** MENU ***************\n");
      printf("1. Insert at First \n");
      printf("2. Insert at LAST \n");
      printf("3. Insert an Element at particualr Position \n");
      printf("4. Delete First Element \n");
      printf("5. Delete LAST Element \n");
      printf("6. Delete Element at Position  \n");
      printf("7. Show Linked List Elements: \n");
      printf("8. Reverse the linked list: \n");
      printf("9. Remove dublicate Elements: \n");
      printf("10. EXIT \n ");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
        case 1: printf("Enter the value to be insert: ");
            scanf("%d", &num);
            p = insertFirst(p, num);
            break;
        case 2: printf("ENter the element to be inserted at last: ");
            scanf("%d",&num);
            p = insertLast(p, num);
            break;
        case 3: show_List(p);
            printf("On which Position the new Value has to be entered : ");
            scanf("%d",&position); 
            printf("ENter the element to be inserted at last: ");
            scanf("%d",&num);
            insert_position(p,num,position);
            break;
        case 4:
            p = deleteFirst(p);
            break;
        case 5:
            p = deleteLast(p);
            break;
        case 6: show_List(p);
            printf("On which Position the new Value has to be deleted : ");
            scanf("%d",&position); 
            delete_position(p,position);
            break;
        case 7: 
            show_List(p); break;
        case 8:
            show_List(p);
            tmp1 = reverse_LL(p);
            printf(" The reverrse Linked List: \n");
            show_List(tmp1);
            break;
        case 9: 
            printf(" The Original Linked List \n");
            show_List(p);
            remove_dublicate(p);
            printf(" New updated list \n");
            show_List(p);
            break;
        case 10: exit(0);
        default: printf("\nWrong selection!!! Please try again!!!\n");
      } // end of switch 
   } // end of While loop
}
