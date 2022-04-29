#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))
int stack[10000];
int stacktop = 0;
void push(int n);
int pop(void);
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int numtmp;
		char tmp[6];
		scanf("%s", &tmp);
		if (strcmp(tmp, "push") == 0) {
			scanf("%d", &numtmp);
			push(numtmp);
		}
		else if (strcmp(tmp, "pop") == 0) {
			printf("%d\n", pop());
		}
		else if (strcmp(tmp, "size") == 0) {
			printf("%d\n", stacktop);
		}
		else if (strcmp(tmp, "empty") == 0) {
			if (stacktop == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(tmp, "top") == 0) {
			if (stacktop == 0)
				printf("-1\n");
			else
				printf("%d\n", stack[stacktop-1]);
		}

	}
	return 0;
}

void push(int n)
{
	stack[stacktop++] = n;
}

int pop(void)
{
	if (stacktop == 0)
		return -1;
	return stack[--stacktop];
}



