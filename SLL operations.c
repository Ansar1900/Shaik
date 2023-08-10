#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
}*head=NULL;
void insert_first()
{
struct node *var;
var=(struct node*)malloc(sizeof(struct node));
printf("\n Enter value:\n");
scanf("%d",&var->data);
if (head==NULL)
{
head=var;
head->next=NULL;
}
else
{
var->next=head;
head=var;
}
}
void insert_last()
{
struct node *var,*temp;
var=(struct node*)malloc(sizeof(struct node));
printf("\n Enter value:\n");
scanf("%d",&var->data);
if(head==NULL)
{
head=var;
head->next=NULL;
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
var->next=NULL;
temp->next=var;
}
}
void insert_mid()
{
struct node *temp,*var,*temp1;
int loc;
var=(struct node*)malloc(sizeof(struct node));
printf("\n Enter node value:\n");
scanf("%d",&var->data);
printf("enter position to be insert\n");
scanf("%d",&loc);
if(head==NULL)
{
head=var;
head->next=NULL;
}
else
{
temp=head;
while(temp!=NULL)
{
if(temp->data==loc)
{
if(head->data==loc)
{
var->next=head;
head=var;
}
else
{
temp1->next=var;
var->next=temp;
}
}
temp1=temp;
temp=temp->next;
}
}
}
void delete_first()
{
if(head==NULL)
{
printf("List is Empty\n");
}
else
{
head=head->next;
}
}
void delete_last()
{
struct node *temp,*temp1;
if(head==NULL)
{
printf("List is Empty\n");
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp1=temp;
temp=temp->next;
}
if(temp->data==head->data)
head=NULL;
temp1->next=NULL;
}
}
void delete_mid()
{
struct node *temp1,*temp;
int teno;
printf("\n Enter the node to be deleted \n");
scanf("%d",&teno);
if (head==NULL)
{
printf("\n No data to delete\n");
return;
}
else
{
temp=head;
while(temp!=NULL)
{
if(temp->data==teno)
{
if (head->data==teno)
{
head=head->next;
}
else
{
temp1->next=temp->next;
}
}
temp1=temp;
temp=temp->next;
}
}
}
void display()
{
struct node *disp;
if (head==NULL)
{
printf("\n No records to view\n");
return;
}
disp=head;
while(disp!=NULL)
{
printf("%d->",disp->data);
disp=disp->next;
}
}
void main()
{
int ch;
while (1)
{
printf("\n 1.Insert Begining\n");
printf("2.Insert Last\n");
printf("3.Insert Middle\n");
printf("4.Delete At First\n");
printf("5.Delete At Last\n");
printf("6.Delete At Middle\n");
printf("7. To display list\n");
printf("8. To exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:insert_first();
display(); break;
case 2:insert_last();
display(); break;
case 3:insert_mid();
display(); break;
case 4: delete_first();
display(); break;
case 5: delete_last();
display(); break;
case 6: delete_mid();
display(); break;
case 7: display(); break;
case 8:exit(0); break;
default: printf(“\nEnter Correct option\n”);
}
}
}
/*
OUTPUT:
1.Insert Begining
2.Insert Last
3.Insert Middle
4.Delete At First
5.Delete At Last
6.Delete At Middle
7. To display list
8. To exit
Enter your choice
1
Enter value:
1
1->
1.Insert Begining
2.Insert Last
3.Insert Middle
4.Delete At First
5.Delete At Last
6.Delete At Middle
7. To display list
8. To exit
Enter your choice
1
Enter value:
2
2->1->
1.Insert Begining
2.Insert Last
3.Insert Middle
4.Delete At First
5.Delete At Last
6.Delete At Middle
7. To display list
8. To exit
Enter your choice
2
Enter value:
3
2->1->3->
1.Insert Begining
2.Insert Last
3.Insert Middle
4.Delete At First
5.Delete At Last
6.Delete At Middle
7. To display list
8. To exi
*/
