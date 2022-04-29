#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))
int queue[1000];
int front = -1;
int rear = 0;
void push(int n);
int pop(int n, int k);
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
		push(i);
	printf("<");
	printf("%d", pop(N,K));
	for (int i = 0; i < N - 1; i++) {
		printf(", %d", pop(N, K));
	}
	printf(">");
	return 0;
}

void push(int n)
{
	queue[rear++] = n;
}

int pop(int n, int k)
{
	int tmp;
	while (k > 0) {
		front = (front + 1)%n;
		if (queue[front] != -1) {
			k--;
		}
	}
	tmp = queue[front];
	queue[front] = -1;
	return tmp;
}


