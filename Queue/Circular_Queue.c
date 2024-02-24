#include <stdio.h>
#define MAX 5
#define TRUE 1
#define FALSE 0


typedef struct circular_queue{
    int info[MAX];
    int rear,front;
    int bool;
}CQ;

void enqueue(CQ *p, int item){
    if(p->front == p->rear && p->bool == TRUE){
        printf("\nCQ OVERFLOW");
        return;
    }
    
    p->rear=(p->rear+1)%MAX;
    p->info[p->rear]=item;
    p->bool=TRUE;
}

void dequeue(CQ *p){
    if(p->front == p->rear && p->bool == FALSE){
        printf("\nCQ UNDERFLOW");
    }
    printf("%d", p->info[p->front]);
    p->front = (p->front + 1)%MAX;
    p->bool = FALSE;
}

void show(CQ *cq){
    printf("\n\nFront -> ");
    int i = cq->front;
    do {
        i = (i + 1) % MAX;
        printf("%d ", cq->info[i]);
    } while (i != cq->rear);
    printf("-> Rear\n");
}

int main() {
    CQ cq;
    int item, choice;
    
    cq.front = cq.rear = 0;
    
    do{
        printf("\n1:INSERT");
        printf("\n2:DELETE");
        printf("\n0:EXIT");
        printf("\n\nENTER YOUR CHOICE : ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("\nEnter value : ");
                scanf("%d", &item);
                enqueue(&cq, item);
                break;
            case 2:
                dequeue(&cq);
                break;
            case 0: printf("\nTUFUTS");
                    break;
            default:printf("\nWCTA");
                    break;
        }
    }while(choice!=0);
    
    show(&cq);
}