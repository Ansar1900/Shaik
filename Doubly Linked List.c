#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 struct node *prev;
int data;
 struct node *next;
}*head=NULL, *last=NULL;
void insert_begning()
{
 struct node *var;
 var=(struct node *)malloc(sizeof(struct node));
 printf("enter the node to be insert begining\n");
 scanf("%d",&var->data);
 if(head==NULL)
 {
head=var;
head->prev=NULL;
head->next=NULL;
last=head;
 }
 else
 {
var->prev=NULL;
var->next=head;
head->prev=var;
head=var;
 }
}
void insert_end()
{
struct node *var,*temp;
 var=(struct node *)malloc(sizeof(struct node));
 printf("enter the node to be insert begining\n");
 scanf("%d",&var->data);
 if(head==NULL)
 {
 head=var;
 head->prev=NULL;
 head->next=NULL;
 last=head;
 }
 else
 {
temp=last;
temp->next=var;
var->next=NULL;
var->prev=temp;
last=var;
   }
}
void insert_mid()
{
struct node *temp,*var,*temp1;
 int loc;
 var=(struct node *)malloc(sizeof(struct node));
 printf("enter the node to be insert begining\n");
 scanf("%d",&var->data);
 var->next=NULL;
 var->prev=NULL;
 printf("after which data you want to insert data ");
 scanf("%d",&loc);
 if(head==NULL)
 {
 head=var;
 head->prev=NULL;
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
head->prev=var;
head=var;
}
else
{
temp1->next=var;
var->prev=temp1;
var->next=temp;
temp->prev=var;
}
}
temp1=temp;
temp=temp->next;
 }
 }
 last=head;
 while(last->next!=NULL)
 {
 last=last->next;
 }
}
void delete_from_end()
{
 struct node *temp;
 temp=last;
 if(head==NULL)
 {
 printf("list is empty");
 }
 else
 {
last=temp->prev;
last->next=NULL;
return;
 }
}
void delete_from_middle()
{
 struct node *temp,*var,*temp1;
 int loc;
 printf("enter node to be deleted");
 scanf("%d",&loc);
 temp=head;
 while(temp!=NULL)
 {
if(temp->data ==loc)
{
 if(head->data==loc)
 {
 head=head->next;
 head->prev=NULL;
 return;
 }
 else
 {
 var=temp->next;
 temp1->next=var;
 var->prev=temp1;
 return;
 }
}
 temp1=temp;
 temp=temp->next;
 }
}
void delete_from_begining()
{
if(head==NULL)
{
printf("list is empty");
}
else
{
 head=head->next;
 head->prev=NULL;
}
}
void display()
{
 struct node *temp;
 temp=head;
 if(temp==NULL)
 {
printf("List is Empty");
 }
 while(temp!=NULL)
 {
printf("%d<-> ",temp->data);
 temp=temp->next;
 }
}
void main()
{
 int ch;
 while(1)
 {
printf("Select the choice of operation on link list");
printf("\n1.insert at begning\n2.insert at at end\n3.insert at middle");
printf("\n4.delete from end\n5.delete from middle \n”);
printf(“6.delete from begining\n7.display list\n8.exit");
printf("\n\nenter the choice of operation you want to do ");
scanf("%d",&ch);
switch(ch)
{
case 1:insert_begning();
 display();
break;
case 2:insert_end();
display();
break;
case 3:insert_mid();
display();
break;
case 4:delete_from_end();
display();
break;
  case 5:delete_from_middle();
display(); break;
case 6:delete_from_begining();
display(); break;
case 7 :display();
break;
case 8 :exit(0);
 break;
 }
 }
}
/*
OUTPUT:
Select the choice of operation on link list
1.insert at begning
2.insert at at end
3.insert at middle
4.delete from end
5.delete from middle
6.delete from begining
7.display list
8.exit
enter the choice of operation you want to do 1
enter the node to be insert begining
1
1<->
Select the choice of operation on link list
1.insert at begning
2.insert at at end
3.insert at middle
4.delete from end
5.delete from middle
6.delete from begining
7.display list
8.exit
enter the choice of operation you want to do 2
enter the node to be insert begining
2
1<-> 2<->
Select the choice of operation on link list
1.insert at begning
2.insert at at end
3.insert at middle
4.delete from end
5.delete from middle
6.delete from begining
7.display list
8.exit
enter the choice of operation you want to do 7
1<-> 2<->
Select the choice of operation on link list
1.insert at begning
2.insert at at end
3.insert at middle
4.delete from end
5.delete from middle
6.delete from begining
7.display list
8.exit
enter the choice of operation you want to do 4
1<->
Select the choice of operation on link list
1.insert at begning
2.insert at at end
3.insert at middle
4.delete from end
5.delete from middle
6.delete from begining
7.display list
8.exit
enter the choice of operation you want to do 8
*/
