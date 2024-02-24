#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    struct node *left;
    int info;
    struct node *right;
}DLL;

//Prototype
void create(DLL **, int);
void show1(DLL *);

int main(){
    DLL *dll = NULL;
    int item, choice;
    do{
        printf("\e[1;1H\e[2J");
        printf("\n ********** Doubly Linked List ************\n");
        printf("\n\t 1: Create a node at the front");
        printf("\n\t 2: Display list of nodes");
        printf("\n\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("\n Enter item: ");
            scanf("%d", &item);
            create(&dll, item);
            break;
        case 2:
            show1(dll);
            break;
        case 0:
            printf("\n Exiting.\n");
            break;
        default:
            printf("\n Invalid choice.\n");
            break;
        }
        getch();
    } while (choice != 0);
    return 0;
}

void show1(DLL *p){
    printf("\nNULL<=>");
    while (p!=NULL){
        printf("%d<=>",p->info);
        p=p->right;
    }
    printf("NULL");
}

void create(DLL **p, int item) {
    DLL *temp;
    temp = (DLL *)malloc(sizeof(DLL));

    if (temp == NULL) {
        printf("\n Memory not created ");
        return;
    }

    temp->right = temp->left = NULL;
    temp->info = item;

    if (*p == NULL) {
        *p = temp;
        return;
    }

    temp->right = *p;
    (*p)->left = temp;
    *p = temp;
}