#include <stdio.h>
#define MAX 10
int list[MAX];
void display()
{
 int i;
 printf("[");
 for(i = 0; i < MAX; i++)
{
 printf("%d ",list[i]);
 }
printf("]\n");
}
void read()
{
int i;
 for(i = 0; i < MAX; i++)
{
 scanf("%d",&list[i]);
 }
}
void bubbleSort()
{
 int temp;
 int i,j;
for(i = 0; i < MAX-1; i++)
{
 for(j = 0; j < MAX-1-i; j++)
{
 if(list[j] > list[j+1])
{
 temp = list[j];
 list[j] = list[j+1];
 list[j+1] = temp;
 }
}
 }
}
void main()
{
printf("Enter Input Array: ");
 read();
printf("Input Array: ");
display();
 bubbleSort();
 printf("\nOutput Array: ");
 display();
}

/*
OUTPUT:
Enter Input Array: 5
6
3
2
4
5
9
7
4
6
Input Array: [5 6 3 2 4 5 9 7 4 6 ]
Output Array: [2 3 4 4 5 5 6 6 7 9 ]
*/
