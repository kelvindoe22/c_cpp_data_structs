#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void insert_head(struct Node** node, int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp ->prev = NULL;
    temp->next = NULL;
    if ((*node)== NULL){
        *node = temp;
        return;
    }
    (*node) ->prev = temp;
    temp->next = (*node);
    *node = temp;
}

void insert_tail(struct Node** node, int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->prev = NULL;
    temp->next = NULL;
    if (*node == NULL){
            insert_head(node,val);
            return;
        }
    struct Node* temp2 = *node;
    while(temp2->next != NULL ){
        temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->prev=temp2;
}


void printNodes(struct Node* node){
    struct Node* d = node;
    while (d != NULL){
        printf("%d ",d->data);
        d = d->next;
    }
}

void printNodesspec(struct Node* node){
    struct Node* d = node;
    while (d != NULL){
        if (d->prev == NULL){
            printf("NULL ");
        }else{
            printf("%d ",d->prev->data);
        }
        d= d->next;
    }
}

void reverse_print(struct Node* node){
    struct Node* temp = node;
    if (temp == NULL) return;
    while (temp->next != NULL){
        temp = temp-> next;
    }
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp-> prev;
    }
    printf("\n");
}

int main()
{
struct Node* head = NULL;

insert_head(&head,6);
insert_head(&head,7);
insert_head(&head,8);
insert_tail(&head,5);
insert_tail(&head,4);
printNodes(head);
printf("\n");
reverse_print(head);
}
