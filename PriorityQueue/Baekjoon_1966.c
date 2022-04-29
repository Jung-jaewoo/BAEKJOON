#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))
typedef struct {
	int index, num;
}D;
D queue[10000];
int front = 0;
int rear = 0;
void push(D n);
D pop(void);
int compare(const void* n1, const void* n2) {
	int x = *(int*)n1;
	int y = *(int*)n2;
	if (x > y)
		return -1;
	else if (x < y)
		return 1;
	else
		return 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		front = 0;
		rear = 0;
		int N, M;
		scanf("%d %d", &N, &M);
		int *arr;
		arr = (int*)malloc(sizeof(int) * N);
		D temp, target;
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp.num);
			temp.index = j;
			push(temp);
			arr[j] = temp.num;
			if (j == M)
				target = temp;
		}
		int big_num = 0;
		int order = 0;
		for (int j = 0; j < N; j++) {
			if (target.num < queue[j].num)
				big_num++;
		}
		qsort(arr, N, sizeof(int), compare);
		int i = 0;
		while (big_num > 0) {
			temp = pop();
			if (temp.num != arr[i]) {
				push(temp);
			}
			else {
				big_num--;
				order++;
				i++;
			}
		}
		while (1) {
			temp = pop();
			if(temp.num == target.num)
				order++;
			if (temp.index == target.index)
				break;
		}
		printf("%d\n", order);
	}
	return 0;
}

void push(D n)
{
	queue[rear++] = n;
}

D pop(void)
{
	if (front == rear)
		return;
	return queue[front++];
}


