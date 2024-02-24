#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev_add;
    struct Node *next_add;
}Node;

void insert(int data, Node *head){
    Node *newNode = malloc(sizeof(newNode));
    newNode->data = data;

    if(head->next_add == NULL){
        head->next_add = newNode;
        newNode->prev_add=NULL;
        newNode->next_add=NULL;
        return;
    }

    while(head->next_add!=NULL){
        head=head->next_add;
    }
    
    newNode->prev_add=head;
    newNode->next_add=NULL;
    head->next_add=newNode;
}

void print(Node *head){
    head=head->next_add;
    printf("\n");
    while(head!=NULL){
        printf("|%X| %d |%X| <=> ",head->prev_add,head->data,head->next_add);
        head=head->next_add;
    }
    printf("NULL");
}

int main(){
    Node *head = malloc(sizeof(head));
    head->next_add=NULL;

    int dataSet[] = {5,2,8,98,4};

    for (int i = 0; i < 5; ++i) {
        insert(dataSet[i], head);
    }

    print(head);
}