#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))
int stack[1000000];
int top = 0;
void push(int n);
int pop(void);
int main()
{
	int n, tmp;
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	int* sol;
	sol = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i <n; i++) 
		scanf("%d", &arr[i]);
	sol[n - 1] = -1;
	push(arr[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] < stack[top - 1]) {
			sol[i] = stack[top - 1];
		}
		else {
			if (pop() == -1) {
				sol[i] = -1;
				push(arr[i]);
			}
			else {
				i++;
				continue;
			}
		}
		push(arr[i]);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", sol[i]);
	return 0;
}

void push(int n)
{
	stack[top++] = n;
}

int pop(void)
{
	if (top == 0)
		return -1;
	return stack[--top];
}



