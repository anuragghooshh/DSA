#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *nextAddress;
};

void insertNodeAtEnd(struct Node *head,int value){
    struct Node *newNode = malloc(sizeof(newNode));
    newNode->value = value;
    newNode->nextAddress=NULL;

    if(head->nextAddress==NULL){
        head->nextAddress=newNode;
        return;
    }

    while(head->nextAddress!=NULL){
        head=head->nextAddress;
    }

    head->nextAddress=newNode;
}

void insertNodeAtFront(struct Node *head,int value){
    struct Node *newNode = malloc(sizeof(newNode));
    newNode->value = value;
    newNode->nextAddress=NULL;

    if(head->nextAddress==NULL){
        head->nextAddress=newNode;
        return;
    }

    newNode->nextAddress = head->nextAddress;
    head->nextAddress = newNode;
}

void printLinkedList(struct Node *head){
    printf("\n");
    while(head!=NULL){
        printf("%d-> ",head->nextAddress->value);
        head=head->nextAddress;
    }
}


int main(){
    struct Node *head = malloc(sizeof(head));
    head->nextAddress = NULL;

    int choice;

    insertNodeAtEnd(head,32);
    insertNodeAtEnd(head,18);
    insertNodeAtEnd(head,77);
    printLinkedList(head);

    insertNodeAtFront(head,93);
    printLinkedList(head);
    
    return 0;
}