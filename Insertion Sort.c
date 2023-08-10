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
void insertionSort()
{
 int valueToInsert;
 int holePosition;
 int i;
 for(i = 1; i < MAX; i++)
 {
 valueToInsert = intArray[i];
 holePosition = i;
 while (holePosition > 0 && intArray[holePosition-1] > valueToInsert)
{
 intArray[holePosition] = intArray[holePosition-1];
 holePosition--;
 }
 intArray[holePosition] = valueToInsert;
 }
}
void main()
{
 printf("Enter Input Array: ");
 read();
 printf("Input Array: ");
 display();
 insertionSort();
 printf("Output Array: ");
 display();
}

/*
OUTPUT:
Enter Input Array: 4
9
7
1
6
4
8
Input Array: [ 4 9 7 1 6 4 8 ]
Output Array: [ 1 4 4 6 7 8 9 ]
*/
