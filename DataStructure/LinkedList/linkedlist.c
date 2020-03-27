    SinglyLinkedListNode *tmp1 = 
#include<stdio.h>
#include<stdlib.h>
// Complete the insertNodeAtHead function below.
typedef struct  SinglyLinkedListNode {
      int data;
      SinglyLinkedListNode *next;
} SinglyLinkedListNode;
 
 
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode *new_node;
    new_node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    new_node->data = data;
    new_node->next = llist;
    new_node->data = data;

    llist = new_node;
    return llist;
}
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode *tmp,*q;
    int count = 1;
    /*if(head == NULL){
        printf("LINKED LIST EMPTY");
        return 0;
    } */
    tmp = head;
    if(tmp->next == NULL || position == 0){
        head = tmp->next;
        free(tmp);
        return 0;
    }
    
    /*for(int i = 1; i<position-1; i++){
        tmp = tmp->next;
    }*/
    while (count != position){
        tmp = tmp->next;
        count++;
    }
    q = tmp->next->next;
    free(tmp->next);
    tmp->next = q;
    return head;
}
