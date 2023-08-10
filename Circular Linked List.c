#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
 int data;
 struct node *next;
}*start=NULL;
void insertbeg()
{
 struct node *nn,*temp;int a;
 nn=(struct node *)malloc(sizeof(struct node));
 printf("enter data:");
 scanf("%d",&nn->data);
 a=nn->data;
 if(start==NULL)
 {
 nn->next=nn;
 start=nn;
 }
 else
 {
 temp=start;
 while(temp->next!=start)
 {
 temp=temp->next;
 }
 temp->next=nn;
 nn->next=start;
 start=nn;
 }
 printf("%d succ. inserted\n",a);
 return;
}
void insertend(void)
{
 struct node *nn,*lp;int b;
 nn=(struct node *)malloc(sizeof(struct node));
 printf("enter data:");
 scanf("%d",&nn->data);
 b=nn->data;
 if(start==NULL)
 {
 nn->next=nn;
 start=nn;
 }
  else
 {
 lp=start;
 while(lp->next!=start)
 {
 lp=lp->next;
 }
 lp->next=nn;
 nn->next=start;
 }
 printf("%d is succ. inserted\n",b);
 return;
}
void insertmid(void)
{
 struct node *nn,*temp,*ptemp;int x,v;
 nn=(struct node *)malloc(sizeof(struct node));
 if(start==NULL)
 {
 printf("sll is empty\n"); return;
 }
 printf("enter data before which no. is to be inserted:\n");
 scanf("%d",&x);
 if(x==start->data)
 {
 insertbeg();
 return;
 }
 ptemp=start;
 temp=start->next;
 while(temp!=start&&temp->data!=x)
 {
 ptemp=temp;
 temp=temp->next;
 }
 if(temp==start)
 {
 printf("%d data does not exist\n",x);
 }
 else
 {
 printf("enter data:");
 scanf("%d",&nn->data);
 v=nn->data;
 ptemp->next=nn;
 nn->next=temp;
 printf("%d succ. inserted\n",v);
 }
 return;
}
void deletion()
{
 struct node *pt,*t,*pp;
 int x;
 printf("enter data to be deleted:");
 scanf("%d",&x);
 if(start==NULL)
 {
 printf("sll is empty\n");
 return;
 }
 if(start->next==start)
 {
start=NULL;
 }
 else
 {
 pt=start;
 while(pt->next!=start)
 {
if(pt->data==x)
{
if(start->data==x)
{
t=start;
while(t->next!=start)
{
t=t->next;
}
t->next=start->next;
start=start->next;
}
else
{
pp->next=pt->next;
return;
}
}
pp=pt;
pt=pt->next;
 }
 if(pt->data==x)
 {
pp->next=pt->next;
return;
 }
 }
}
void display()
{
 struct node *temp;
 if(start==NULL)
 {
 printf("sll is empty\n");
 return;
 }
 printf("elements are:\n");
 temp=start;
 while(temp->next!=start)
 {
 printf("%d->",temp->data);
 temp=temp->next;
 }
 printf("%d",temp->data);
 return;
}
void main()
{
 int c,a;
 while(1)
 {
 printf("\n1:insertbeg\n2:insert end\n3:insert mid\n4:delete\n5:display\n6:exit\nenter choice:");
 scanf("%d",&c);
 switch(c)
 {
case 1:insertbeg();
display();
break;
case 2:insertend();
display();
break;
case 3:insertmid();
display();
break;
case 4:deletion();
display();
break;
case 5:display();
break;
case 6:exit(0);
break;
default:printf("wrong choice\n");break;
 }
 }
}
/*
OUTPUT:
1:insertbeg
2:insert end
3:insert mid
4:delete
5:display
6:exit
enter choice:1
enter data:
1
1 succ. inserted
elements are:
1
1:insertbeg
2:insert end
3:insert mid
4:delete
5:display
6:exit
enter choice:2
enter data:2
2 is succ. inserted
elements are:
1->2
1:insertbeg
2:insert end
3:insert mid
4:delete
5:display
6:exit
enter choice:2
enter data:3
3 is succ. inserted
elements are:
1->2->3
1:insertbeg
2:insert end
3:insert mid
4:delete
5:display
6:exit
enter choice:4
enter data to be deleted:2
elements are:
1->3
1:insertbeg
2:insert end
3:insert mid
4:delete
5:display
6:exit
enter choice:5
elements are:
1->3
1:insertbeg
2:insert end
3:insert mid
4:delete
5:display
6:exit
enter choice:6
*/
