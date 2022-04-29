#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))

int queue[20000];
int front = 10000;
int rear = 10000;
void push_front(int n);
void push_back(int n);
int pop_front(void);
int pop_back(void);
int main()
{
	int N, tmp;
	char commend[12];
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%s", commend);
		if (strcmp(commend, "push_front") == 0) {
			scanf("%d", &tmp);
			push_front(tmp);
		}
		else if (strcmp(commend, "push_back") == 0) {
			scanf("%d", &tmp);
			push_back(tmp);
		}
		else if (strcmp(commend, "pop_front") == 0) {
			printf("%d\n", pop_front());
		}
		else if (strcmp(commend, "pop_back") == 0) {
			printf("%d\n", pop_back());
		}
		else if (strcmp(commend, "size") == 0) {
			printf("%d\n",rear-front);
		}
		else if (strcmp(commend, "empty") == 0) {
			if (rear == front)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(commend, "front") == 0) {
			if (rear == front)
				printf("-1\n");
			else
				printf("%d\n", queue[front]);
		}
		else if (strcmp(commend, "back") == 0) {
			if (rear == front)
				printf("-1\n");
			else
				printf("%d\n", queue[rear-1]);
		}
	}
	return 0;
}

void push_front(int n)
{
	queue[--front] = n;
}
void push_back(int n)
{
	queue[rear++] = n;
}
int pop_front(void)
{
	if (front == rear)
		return -1;
	return queue[front++];
}
int pop_back(void)
{
	if (front == rear)
		return -1;
	return queue[--rear];
}

