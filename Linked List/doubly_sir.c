#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    struct node *left;
    int info;
    struct node *right;
} DLL;
void create(DLL **p, int item) {
    DLL *temp, *cur;
    temp = (DLL *)malloc(sizeof(DLL));
    if (temp == NULL) {
        printf("\n Memory not created ");
        return;
    }
    temp->info = item;
    if (*p == NULL) {
        *p = temp;
        temp->right = temp->left = NULL;
        return;
    }
    cur = *p;
    while (cur->right != NULL)
        cur = cur->right;

    cur->right = temp;
    temp->left = cur;
    temp->right = NULL;
}
void insertBeginning(DLL **p, int item) {
    DLL *temp;
    temp = (DLL *)malloc(sizeof(DLL));
    if (temp == NULL) {
        printf("\n Memory not created ");
        return;
    }
    temp->info = item;
    temp->left = NULL;
    temp->right = *p;
    if (*p != NULL)
        (*p)->left = temp;
    *p = temp;
}
void deleteBeginning(DLL **p) {
    if (*p == NULL) {
        printf("\n List is empty.");
        return;
    }
    DLL *temp = *p;
    *p = (*p)->right;
    if (*p != NULL)
        (*p)->left = NULL;
    free(temp);
}
int countNodes(DLL *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->right;
    }
    return count;
}
DLL* findNode(DLL *p, int item) {
    while (p != NULL) {
        if (p->info == item)
            return p;
        p = p->right;
    }
    return NULL;
}

void show1(DLL *p) {
    printf("\n List of nodes: ");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->right;
    }
    printf("\n");
}
void reverseDisplay(DLL *p) {
    if (p == NULL)
        return;
    DLL *last = p;
    while (last->right != NULL) {
        last = last->right;
    }
    printf("\n Reverse list of nodes: ");
    while (last != NULL) {
        printf("%d ", last->info);
        last = last->left;
    }
    printf("\n");
}
void reverseList(DLL **p) {
    DLL *temp = NULL;
    DLL *current = *p;
    while (current != NULL) {
        temp = current->left;
        current->left = current->right;
        current->right = temp;
        *p = current;
        current = current->left;
    }
}
int main(void) {
    DLL *dll = NULL;
    int item, choice;
    do {
        printf("\e[1;1H\e[2J");
        printf("\n ********** Doubly Linked List ************\n");
        printf("\n\t 1: Create a node at the end");
        printf("\n\t 2: Insert a node at the beginning");
        printf("\n\t 3: Delete a node from the beginning");
        printf("\n\t 4: Count the number of nodes");
        printf("\n\t 5: Find a particular node");
        printf("\n\t 6: Display list of nodes");
        printf("\n\t 7: Reverse display list of nodes");
        printf("\n\t 8: Physically reverse the list");
        printf("\n\t 0: Exit");
        printf("\n\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n Enter item: ");
                scanf("%d", &item);
                create(&dll, item);
                break;
            case 2:
                printf("\n Enter item: ");
                scanf("%d", &item);
                insertBeginning(&dll, item);
                break;
            case 3:
                deleteBeginning(&dll);
                break;
            case 4:
                printf("\n Number of nodes: %d", countNodes(dll));
                break;
            case 5:
                printf("\n Enter item to find: ");
                scanf("%d", &item);
                if (findNode(dll, item) != NULL)
                    printf("\n Node found");
                else
                    printf("\n Node not found");
                break;
            case 6:
                show1(dll);
                break;
            case 7:
                reverseDisplay(dll);
                break;
            case 8:
                reverseList(&dll);
                printf("\n List reversed");
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