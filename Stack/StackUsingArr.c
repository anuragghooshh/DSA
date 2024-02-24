#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 6

int top = -1;
int stack[MAX];

int isFull(){
    if(top==MAX)
        return 1;
    
    return 0;
}
int isEmpty(){
    if(top==-1)
        return 1;
    
    return 0;
}

void showStack(){
    if(isEmpty()){
        printf("\nSTACK EMPTY.");
        return;
    }

    printf("\n");
    for(int i=0; i<=top; i++)
        printf("%d ", stack[i]);
}

void push(int data){
    if(isFull()){
        printf("\nSTACK FULL.");
        exit(1);
    }

    top++;
    stack[top]=data;
    showStack();
}

int pop(){
    if(isEmpty()){
        printf("\nSTACK EMPTY.");
        exit(1);
    }
    int data;

    data=stack[top];
    top--;
    showStack();
    return data;
}


int main(){
    int menu=1;

    do{
        printf("\e[1;1H\e[2J");
        printf("\nMENU");
        printf("\n\n\t1 | Push");
        printf("\n\t2 | Pop");
        printf("\n\t3 | Print");
        printf("\n\t0 | Exit");
        printf("\n\nEnter your choice : " );
        scanf("%d", &menu);

        switch (menu){
            case 1:
                int data;
                printf("\nEnter data to push : ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                printf("\n%d has been popped from the stack!", pop());
                break;
            case 3:
                showStack();
                break;
            case 0:
                break;
            default:
                printf("\nINVALID INPUT!");
                break;
        }
        getch();
    }while(menu);

    return 0;
}