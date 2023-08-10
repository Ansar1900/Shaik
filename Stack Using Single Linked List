#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top,*p;
void push(){
    p=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data value: ");
    scanf("%d",&p->data);
    p->next=NULL;
    if(top==NULL)
        top=p;
    else{
        p->next=top;
        top=p;
    }
    printf("\n%d is pushed.\n",top->data);
}
void pop(){
    if(top==NULL)
        printf("\nStact is empty!\n");
    else{
        p=top;
        printf("\n%d is poped.\n",top->data);
        top=top->next;
        free(p);
    }
}
void Display(){
    p=top;
    if(top==NULL)
        printf("\nStack  is empty.\n");
    else{
        printf("\nStack elements are: ");
        while(p!=NULL){
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}
void is_empty(){
    if(top==NULL)
        printf("\nStack is Empty!\n");
    else
        printf("\nStack is not empty.\n");
}
void peek(){
    if(top==NULL)
        printf("\nStack is Empty!\n");
    else
        printf("\nPeek element is : %d\n",top->data);
}
void main(){
    int op;
    while(1){
        printf("\n* * * * * * * *\n");
        printf("* 1. PUSH     *\n* 2. POP      *\n* 3. DISPLAY  *\n* 4. IS EMPTY *\n* 5. PEEK     *\n* 6. EXIT     *\n");
        printf("* * * * * * * *\n");
        printf("\nEnter your option: ");
        scanf("%d",&op);
        switch(op){
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: Display();
                break;
            case 4 : is_empty();
                break;
             case 5:peek();
                break;
            case 6:exit(0);
                break;
            default : printf("\nWRONG OPTION!\n");
        }
    }
}
