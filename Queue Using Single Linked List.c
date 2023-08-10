#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void enqueue();
void dequeue();
void print();
void is_empty();
void peek();
void main(){
    int op,ele;
    while(1){
        printf("\n* * * * * * * * *\n");
        printf("*  1. Enqueue   *\n*  2. Dequeue   *\n*  3. Print     *\n*  4. Peek      *\n*  5. Is empty  *\n*  6. Exit      *\n");
        printf("* * * * * * * * *\n\nEnter your option: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1: enqueue();
            break;
        case 2: dequeue();
            break;
        case 3: print();
            break;
        case 4: peek();
            break;
        case 5: is_empty();
            break;
        case 6: exit(0);
            break;
        default: printf("\nEnter valid option.\n");
            break;
        }
    }
}
void enqueue(){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    if(!p){
        printf("\nQueue is overflow!\n");
    }
    else{
        printf("Enter data value: ");
        scanf("%d",&p->data);
        p->next=NULL;
        printf("\n%d is enqueued.\n",p->data);
        if(front==NULL)
            front=rear=p;
        else{
            rear->next=p;
            rear=p;
        }
    }
}
void dequeue(){
    if(front==NULL)
        printf("\nQueue is empty!\n");
    else{
        struct node *temp=front;
        printf("\n%d is dequeued.\n",front->data);
        front=front->next;
        free(temp);
    }
}
void print(){
    if(front==NULL)
        printf("\nQueue is empty!\n");
    else{
        struct node *temp=front;
        printf("\nQueue elements are: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void is_empty(){
    if(front==NULL)
        printf("\nQueue is empty.\n");
    else
        printf("\nQueue is not empty.\n");
}
void peek(){
    if(front==NULL)
        printf("\nQueue is empty.\n");
    else
        printf("\nPeek is %d\n",rear->data);
}
