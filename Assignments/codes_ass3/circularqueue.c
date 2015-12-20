//array as circular queue

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int front=0,rear=0,arr[1000]={0};
int enqueue(int integer)
{
	if(front-rear=1)
	{
		printf("cannot insert");
		return -1;
	}
	arr[rear]=integer;
	rear++;
	if(rear>n-1)
		rear=rear%n;
	return rear;
}
int dequeue()
{
	return arr[front];
	front++;
}
	
int main()
{
	int i,j,n;
	char k;
	scanf("%d",&n);
	scanf("%c",&k);
	if(k=='e')
	{
		scanf("%d",&integer);
		enqueue(integer);
	}
	else
		dequeue();

	for(i=0;i<n;i++)
		printf("%d",arr[i]);
return 0;
}


