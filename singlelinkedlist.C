#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next ;
};

void insertfirst(struct Node** head, int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=*head;
    *head = newnode;
}

void insertend(struct Node** head, int data){
    struct Node* temp = *head;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    
    if (*head==NULL){
        *head=newnode;
        return ;
    }
    while (temp-> next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return ;
}

void insertpos(struct Node** head, int data,int pos){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    if (pos==0){
        insertfirst(head,data);
        return ;
    }
    struct Node* temp = *head;
    for(int i=0;temp!=NULL&& i<pos-1;i++){
        temp=temp->next;
    }
   
    if (temp==NULL){
        printf("Postion out of range\n");
        free(newnode);
        return ;
    }
    newnode->next=temp->next;
    temp->next=newnode;
   
}

void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;
    insertfirst(&head,1);
    print(head);
    insertfirst(&head,2);
    print(head);
    insertfirst(&head,3);
    print(head);
    insertend(&head,4);
    print(head);
    insertend(&head,5);
    print(head);
    insertpos(&head,4,1);
    print(head);
    
}
