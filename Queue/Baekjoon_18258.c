#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))
int queue[2000000];
int front = 0;
int rear = 0;
void push(int n);
int pop(void);
int main()
{
	int N, tmp;
	scanf("%d", &N);
	char commend[6];
	for (int i = 0; i < N; i++) {
		scanf("%s", commend);
		if (strcmp(commend, "push") == 0) {
			scanf("%d", &tmp);
			push(tmp);
		}
		else if (strcmp(commend, "pop") == 0) {
			printf("%d\n", pop());
		}
		else if (strcmp(commend, "size") == 0) {
			printf("%d\n", rear - front);
		}
		else if (strcmp(commend, "empty") == 0) {
			if (front == rear)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(commend, "front") == 0) {
			if (front == rear)
				printf("-1\n");
			else
				printf("%d\n", queue[front]);
		}
		else if (strcmp(commend, "back") == 0) {
			if (front == rear)
				printf("-1\n");
			else
				printf("%d\n", queue[rear-1]);
		}
	}
	return 0;
}

void push(int n)
{
	queue[rear++] = n;
}

int pop(void)
{
	if (front == rear)
		return -1;
	return queue[front++];
}


