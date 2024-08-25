#include<stdio.h>
#include<stdlib.h>
struct Node{
      int data;
      struct Node *next;
};

void linkedListTraversal(struct Node* ptr){
    while(ptr!=NULL){
    printf("%d\n", ptr->data);
    ptr = ptr->next;
    }
}

//case1:Delete first Node

struct Node * deleteAtLast(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next !=NULL){
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;

}

int main(){
       struct Node *head;
       struct Node *second;
       struct Node *third;
       struct Node *fourth;

       head = (struct Node *)malloc(sizeof(struct Node));
       second = (struct Node *)malloc(sizeof(struct Node));
       third = (struct Node *)malloc(sizeof(struct Node));
       fourth = (struct Node *)malloc(sizeof(struct Node));

        head->data = 80;
        head->next = second;

        second->data = 10;
        second->next = third;

        third->data = 60;
        third->next = fourth;

        fourth->data = 90;
        fourth->next = NULL;
        
        printf("Linked list before deletion\n");
        linkedListTraversal(head);

        head = deleteAtLast(head);
        printf("Linked list after deletion from end\n");
        linkedListTraversal(head);

        return 0;
}