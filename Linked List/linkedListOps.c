#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *nextNode;
}Node;

void insertAtFront(Node *head, int data){
    Node *tempNode = malloc(sizeof(tempNode));
    tempNode->data = data;
    tempNode->nextNode = NULL;

    if(head->nextNode==NULL){
        head->nextNode=tempNode;
        return;
    }

    tempNode->nextNode = head->nextNode;
    head->nextNode = tempNode;
}

void insertAtEnd(Node *head, int data){
    Node *tempNode = malloc(sizeof(tempNode));
    tempNode->data=data;
    tempNode->nextNode=NULL;

    if(head->nextNode == NULL){
        head->nextNode=tempNode;
        return;        
    }

    while(head->nextNode!=NULL){
        head=head->nextNode;
    }

    head->nextNode=tempNode;
}

int showReverse(Node *head){
    int data = showReverse(head=head->nextNode);
    
}

void showLength(Node *head){
    int count=0;
    for(head=head->nextNode; head!=NULL; head=head->nextNode, count++);
        
    printf("\nLength of the given Linked List is %d.", count);
}

void show(Node *head){
    printf("\n");
    head=head->nextNode;
    while (head!=NULL){
        printf("%d->",head->data);
        head=head->nextNode;
    }
    printf("NULL");
}


int main(){
    Node *head = malloc(sizeof(head));
    head->nextNode=NULL;

    int dataSet[] = {5,2,8,98,4};

    for (int i = 0; i < 5; ++i) {
        insertAtEnd(head, dataSet[i]);
    }

    // show(head);
    // showLength(head);

    // for (int i = 4; i >=0; --i) {
    //     insertAtFront(head, dataSet[i]); 
    // }

    printf("\n");
    showReverse(head);

    return 0;
}