#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))

int queue[20000];
int front = 10000;
int rear = 10000;
int find_index(int n);
void push_front(int n);
void push_back(int n);
int pop_front(void);
int pop_back(void);
int main()
{
	int N, M, i, j, sol, tmp, tmp1, tmp2, f_index;
	sol = 0;
	scanf("%d %d", &N, &M);
	int *arr;
	arr = (int*)malloc(sizeof(int) * M);
	for (i = 0; i < M; i++)
		scanf("%d", arr + i);
	for (i = 1; i <= N; i++)
		push_back(i);
	for (i = 0; i < M; i++) {
		f_index = find_index(arr[i]);
		if (f_index == front) {
			pop_front();
		}
		else {
			tmp1 = f_index - front;
			tmp2 = rear - f_index;
			if (tmp1 < tmp2) {
				for (j = 0; j < tmp1; j++)
					push_back(pop_front());
				sol += tmp1;
			}
			else {
				for (j = 0; j < tmp2; j++)
					push_front(pop_back());
				sol += tmp2;
			}
			pop_front();
		}
	}
	printf("%d", sol);
	return 0;
}
int find_index(int n) {
	for (int i = front; i < rear; i++) {
		if (queue[i] == n)
			return i;
	}
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

