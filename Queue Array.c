#include<stdio.h>
#include<stdlib.h>
void enque(int);
void deque();
void print();
void display();
int is_full();
int is_empty();
int peek();
int rear = -1,front = -1;
#define SIZE 10
int queue[SIZE];
void main(){
    int op,ele;
    while(1){
        printf("\n* * * * * * * * *\n");
        printf("*  1. Enque     *\n*  2. Deque     *\n*  3. Print     *\n*  4. Peek      *\n*  5. Is full   *\n*  6. Is empty  *\n*  7. Exit      *\n*  8. Display   *\n");
        printf("* * * * * * * * *\n\nEnter your option: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1: printf("\nEnter element: ");
                scanf("%d",&op);
                enque(op);
            break;
        case 2: deque();
            break;
        case 3: print();
            break;
        case 4: printf("\nPeek = %d\n",peek());
            break;
        case 5: 
            if(is_full())
                printf("\nQueue is overlow.\n");
            else
                printf("\nQueue is not full.\n");
            break;
        case 6:
            if(is_empty())
                printf("\nQueue is underlow.\n");
            else
                printf("\nQueue is not empty.\n");
            break;
        case 7: exit(1);
            break;
        case 8: display();
            break;
        default: printf("\nEnter valid option.\n");
            break;
        }
    }
}
void enque(int in){
    if(is_full())
        printf("\nQueue is over flow.\n");
    else
        queue[++rear]=in;
}
void deque(){
    if(is_empty())
        printf("\nQueue is under flow.\n");
    else
        printf("\n%d is dequeed.\n",queue[++front]);
}
int is_full(){
    if(rear == SIZE-1)
        return 1;
    else
     return 0;
}
int is_empty(){
    if(front == rear)
        return 1;
    else
     return 0;
}
void print(){
    if(is_empty())
        printf("\nQueue is underflow.\n");
    else
        printf("\nQueue elements are: ");
        for(int i=front+1;i<=rear;i++)
            printf("%d ",queue[i]);
        printf("\n");
}
int peek(){
    return queue[rear];
}
void display(){
    printf("\nWhole Queue is : ");
    for(int i=0;i<SIZE;i++)
        printf("%d ",queue[i]);
    printf("\n");
}
