#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))
int queue[100000];
char arr[400002];
char commend[100001];
int front, rear;

void push(int n);
int pop(void);
int main()
{
	int T, tmp, n, flag, arrlength, commendlength;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		flag = 1;
		front = 0;
		rear = 0;
		scanf("%s", commend);
		scanf("%d", &n);
		scanf("%s", arr);
		tmp = 0;
		arrlength = strlen(arr);
		commendlength = strlen(commend);
		for (int j = 0; j < arrlength; j++) {
			if ('0' <= arr[j] && arr[j] <= '9')
				tmp = tmp * 10 + arr[j] - '0';
			else {
				if (tmp != 0)
					push(tmp);
				tmp = 0;
			}
		}
		for (int i = 0; i < commendlength; i++) {
			if (commend[i] == 'D') {
				if (front == rear) {
					flag = 0;
					break;
				}
				else {
					if (front < rear)
						front++;
					else if (front > rear)
						front--;
				}
			}
			else if (commend[i] == 'R') {
				tmp = front;
				front = rear;
				rear = tmp;
			}
		}
		if (flag) {
			if (front == rear) {
				printf("[]\n");
			}
			else {
				printf("[%d", pop());
				while (front != rear) {
					printf(",%d", pop());
				}
				printf("]\n");
			}
		}
		else {
			printf("error\n");
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
	if (front < rear)
		return queue[front++];
	else if (front > rear)
		return queue[--front];
	else
		return -1;
}