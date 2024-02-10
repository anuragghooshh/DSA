#include <stdio.h>
#define MAX 5
#define TRUE 1
#define FALSE 0
typedef struct dequeue{
	 int info[MAX];
	 int rear,front;
	 int bool;
}DQ;

void enqueue(DQ *p, int item, int qno){

	 if(p->front+1 == p->rear){
		  printf("\nDQ OVERFLOW");
		  return;
	 }

	 switch(qno){
		  case 1:
				p->front = p->front+1;
				p->info[p->front] = item;
				break;
		  case 2:
				p->rear = p->rear-1;
				p->info[p->rear] = item;
				break;
	 }

}

void dequeue(DQ *p,int qno){
	 int i;
	 switch(qno){
		  case 1:
				if(p->front<0){
					 printf("\nUNDERFLOW");
					 return;
				}
				for(i=1;i<=p->front;i++){
					 p->info[i-1] = p->info[i];
				}
				p->front = p->front-1;
				break;
		  case 2:
				if(p->rear > MAX -1){
					 printf("\nUNDERFLOW");
					 return;
				}
				for(i=MAX-2; i>=p->rear; i--){
					 p->info[i+1] = p->info[i];
				}
				p->rear = p->rear+1;
				break;
	 }

}

void printQueue(DQ *dq){
    printf("\n\n");
    printf("%d\t",dq->info[0]);
    printf("%d\t",dq->info[1]);
    printf("%d\t",dq->info[2]);
    printf("%d\t",dq->info[3]);
    printf("%d\t",dq->info[4]);
}

int main() {

	 DQ dq;
	 int item, choice,qno;

	 dq.front = dq.rear = 0;

	 do{
		  printf("\n1:INSERT");
		  printf("\n2:DELETE");
		  printf("\n0:EXIT");

		  printf("\n\nENTER YOUR CHOICE : ");

		  scanf("%d",&choice);

		  switch(choice){
				case 1:
					 printf("\n\n1:At front");
					 printf("\n\n2:At Rear");
					 printf("\nENTER YOUR CHOICE : ");
					 scanf("%d", &qno);

					 printf("\nENTER VALUE : ");
					 scanf("%d", &item);

					 enqueue(&dq, item, qno);
					 break;

				case 2:
					 printf("\n\n1:At front");
					 printf("\n\n2:At Rear");
					 printf("\nENTER YOUR CHOICE : ");
					 scanf("%d", &qno);

					 dequeue(&dq, qno);
					 break;

				case 0: printf("\nTUFUTS");
						  break;

				default:printf("\nWCTA");
						  break;
		  }

	 }while(choice!=0);

	 printQueue(&dq);
}