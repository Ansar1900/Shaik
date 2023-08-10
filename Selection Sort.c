#include <stdio.h>
#define MAX 7
int intArray[MAX];
void read()
{
 int i;
 for(i = 0;i < MAX;i++)
 {
 scanf("%d", &intArray[i]);
 }
}
void display()
{
 int i;
 printf("[ ");
 for(i = 0;i < MAX;i++)
 {
 printf("%d ", intArray[i]);
 }
 printf(" ]\n");
}
void selectionSort()
{
 int indexMin,i,j;
 for(i = 0; i < MAX-1; i++)
 {
indexMin = i;
 for(j = i+1;j < MAX;j++)
{
 if(intArray[j] < intArray[indexMin])
{
 indexMin = j;
 }
 }
 int temp = intArray[indexMin];
 intArray[indexMin] = intArray[i];
 intArray[i] = temp;
 }
}
void main()
{
 printf("Enter Input Array: ");
 read();
 printf("Input Array: ");
 display();
 selectionSort();
 printf("Output Array: ");
 display();
}

/*
OUTPUT:
Enter Input Array: 4
2
1
7
9
4
2
Input Array: [ 4 2 1 7 9 4 2 ]
Output Array: [ 1 2 2 4 4 7 9 ]
*/
