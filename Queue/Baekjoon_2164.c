#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 500000
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))
int queue[500000];
int front = 0;
int rear = 0;
void push(int n);
int pop(void);
int main()
{
	int N, tmp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		push(i);
	while (rear - front != 1) {
		pop();
		push(pop());
	}
	printf("%d\n", pop());
	return 0;
}

void push(int n)
{
	queue[rear++ % SIZE] = n;
}

int pop(void)
{
	if (front == rear)
		return -1;
	return queue[front++ % SIZE];
}


