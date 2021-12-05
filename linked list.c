#include <stdlib.h>
#include <stdio.h>



struct Node{
int data;
struct Node* next;

};



void printNodes(struct Node* node){
    struct Node* d = node;
    while (d != NULL){
        printf("%d ",d->data);
        d = d->next;
    }

}

void insert(struct Node** node, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp-> next = NULL;
    if (*node != NULL) temp->next = *node;
    *node = temp;
}


void deleteNode(struct Node** node, int pos){
    int a;
    struct Node* temp = *node;
    if (pos == 1){
        *node = (*node)->next;
        free(temp);
        return;
    }
    for (a = 0; a <pos-2; a++){
        if (temp != NULL){
            temp = temp-> next;
        }else{
        printf("position %d is invalid \n",pos);
        return;
        }
    }
    struct Node* temp2 =  temp->next;
    temp -> next = temp2->next;
    free(temp2);
}

void insertpos(struct Node** node, int pos, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp-> next = NULL;
    if (pos == 1){
        temp->next = *node;
        *node = temp;
        return;
    }
    int num_control;
    struct Node* temp2 = *node;
    for (num_control = 0;num_control<pos-2; num_control++){
        if (temp2 != NULL ){
            temp2 = temp2->next;
        }else{
        printf("position %d is invalid \n",pos);
        return;
        }
    }
    temp ->next = temp2-> next;
    temp2-> next = temp;

}

void deleteval(struct Node** node, int val){
    struct Node* temp = *node;
    if (temp-> data == val){
        *node = (*node) -> next;
        free(temp);
        return;
    }
    while (temp != NULL || temp->next != NULL){
            if (temp->next == NULL){
                printf("%d not found \n",val);
                return;
            }
        if ((temp -> next)-> data == val){
            struct Node* temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            return;
        }else{
            temp = temp->next;
        }
    }
    printf("%d not found",val);



}
void reverseList(struct Node** node){
    if (*node == NULL){
        return;
    }

    struct Node* temp = *node;
    struct Node* temp2 = temp->next;
    struct Node* temp3 ;

    temp -> next = NULL;
    while(1){
        if (temp2 != NULL){
            temp3 = temp;
            temp = temp2->next;
            temp2-> next = temp3;
        }else{
            *node = temp;
            return;
        }
        if (temp != NULL){
            temp3 = temp2;
            temp2 = temp->next;
            temp-> next = temp3;
        }else{
            *node = temp2;
            return;
        }

   }
}

void altrev(struct Node** node){
    if (*node == NULL){
        return;
    }
    struct Node* current = *node;
    struct Node* next;
    struct Node* prev = NULL;

    while(current != NULL){
        next = current -> next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *node = prev;

}
void recursiveprint(struct Node* node){
    if (node == NULL) return;
    recursiveprint(node->next);
    printf("%d ",node->data);
}

void recursivereverse(struct Node** node){
    struct Node* temp = *node;
    rrr(node,temp);

}

void rrr(struct Node** original, struct Node* temp){
    if (temp->next == NULL){
        *original = temp;
        return;
    }
    rrr(original,temp->next);
    struct Node* q = temp-> next;
    q -> next = temp;
    temp-> next = NULL;
}


int main(){

struct Node* head = NULL;
insertpos(&head,1,1);
insertpos(&head,2,2);
insertpos(&head,3,3);
insertpos(&head,4,4);
insertpos(&head,2,5);
insertpos(&head,2,6);
insertpos(&head,2,7);
insertpos(&head,2,8);
printNodes(head);
/*printf("\n");
reverseList(&head);
printNodes(head);
printf("\n");
altrev(&head);
printNodes(head);
printf("\n");*/
recursivereverse(&head);
printf("\n");
printNodes(head);
printf("\n");
recursiveprint(head);

return 0;

}



