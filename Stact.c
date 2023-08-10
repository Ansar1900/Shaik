#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void print();
void display();
int is_full();
int is_empty();
int peek();
int TOP = -1;
#define SIZE 10
int stack[SIZE];
void main(){
    int op,ele;
    while(1){
        printf("\n*********\n");
        printf("1.Push\n2.Pop\n3.Print\n4.Peek\n5.Is full\n6.Is empty.\n7.Exit\n8.Display\n");
        printf("***********\n\nEnter your option: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1: printf("\nEnter element: ");
                scanf("%d",&op);
                push(op);
            break;
        case 2: pop();
            break;
        case 3: print();
            break;
        case 4: printf("\nPeek = %d\n",peek());
            break;
        case 5: 
            if(is_full())
                printf("\nStack is overlow.\n");
            else
                printf("\nStack is not full.\n");
            break;
        case 6:
            if(is_empty())
                printf("\nStack is underlow.\n");
            else
                printf("\nStack is not empty.\n");
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
void push(int in){
    if(is_full())
        printf("\nStack is over flow.\n");
    else
        stack[++TOP]=in;
}
void pop(){
    if(is_empty())
        printf("\nStack is under flow.\n");
    else
        printf("\n%d is poped.\n",stack[TOP--]);
}
int is_full(){
    if(TOP == SIZE-1)
        return 1;
    else
     return 0;
}
int is_empty(){
    if(TOP == -1)
        return 1;
    else
     return 0;
}
void print(){
    if(is_empty())
        printf("\nStack is underflow.\n");
    else
        printf("\nStack elements are: ");
        for(int i=0;i<=TOP;i++)
            printf("%d ",stack[i]);
        printf("\n");
}
int peek(){
    return stack[TOP];
}
void display(){
    printf("\nWhole Stack is : ");
    for(int i=0;i<SIZE;i++)
        printf("%d ",stack[i]);
    printf("\n");
}
