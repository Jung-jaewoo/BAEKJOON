#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))
int stack[100000];
int stack2[100000];
int top = 0;
int top2 = 0;
char plma[200001];
void push(int n);
int pop(void);
void push2(int n);
int pop2(void);
int main()
{
	int n;
	scanf("%d", &n);
	int ptop = 0;
	int tmp;
	int j = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		push(tmp);
		while (j<=tmp) {
			plma[ptop++] = '+';
			j++;
		}
		plma[ptop++] = '-';
	}
	j = 1;
	top = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (plma[i] == '+')
			push2(j++);
		else {
			if (pop2() != stack[top++]) {
				ptop = 0;
				break;
			}
		}
	}
	if (ptop == 0)
		printf("NO");
	else {
		for (int i = 0; i < 2*n; i++) {
			printf("%c\n", plma[i]);
		}
	}
	return 0;
}
void push2(int n)
{
	stack2[top2++] = n;
}

int pop2(void)
{
	if (top2 == 0)
		return -1;
	return stack2[--top2];
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



