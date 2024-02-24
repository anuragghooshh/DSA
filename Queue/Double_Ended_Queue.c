#include <stdio.h>
#define MAX 5

typedef struct dequeue {
    int info[MAX];
    int rear, front;
} DQ;

void enqueue(DQ *p, int item, int qno) {
    if ((p->rear == MAX && p->front == -1) || (p->front == p->rear + 1)) {
        printf("\nDQ OVERFLOW");
        return;
    }

    switch (qno) {
        case 1:
            if (p->front == -1)
                p->front = p->rear = 0;
            else
                p->front = (p->front - 1 + MAX) % MAX;
            p->info[p->front] = item;
            break;
        case 2:
            if (p->front == -1)
                p->front = p->rear = 0;
            else
                p->rear = (p->rear + 1) % MAX;
            p->info[p->rear] = item;
            break;
    }
}

void dequeue(DQ *p, int qno) {
    if (p->front == -1) {
        printf("\nUNDERFLOW");
        return;
    }

    switch (qno) {
        case 1:
            if (p->front == p->rear)
                p->front = p->rear = -1;
            else
                p->front = (p->front + 1) % MAX;
            break;
        case 2:
            if (p->front == p->rear)
                p->front = p->rear = -1;
            else
                p->rear = (p->rear - 1 + MAX) % MAX;
            break;
    }
}

void printQueue(DQ *dq) {
    printf("\n\n");
    if (dq->front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    int i = dq->front;
    do {
        printf("%d\t", dq->info[i]);
        i = (i + 1) % MAX;
    } while (i != (dq->rear + 1) % MAX);
}

int main() {
    DQ dq;
    int item, choice, qno;

    dq.front = dq.rear = -1;

    do {
        printf("\n1: INSERT");
        printf("\n2: DELETE");
        printf("\n0: EXIT");

        printf("\n\nENTER YOUR CHOICE : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n\n1: At front");
                printf("\n\n2: At Rear");
                printf("\nENTER YOUR CHOICE : ");
                scanf("%d", &qno);

                printf("\nENTER VALUE : ");
                scanf("%d", &item);

                enqueue(&dq, item, qno);
                break;

            case 2:
                printf("\n\n1: At front");
                printf("\n\n2: At Rear");
                printf("\nENTER YOUR CHOICE : ");
                scanf("%d", &qno);

                dequeue(&dq, qno);
                break;

            case 0:
                printf("\nExiting.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != 0);

    printQueue(&dq);

    return 0;
}
