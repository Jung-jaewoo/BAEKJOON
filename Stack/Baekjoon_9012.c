#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))
char stack[51];
int top = 0;
void push(char c);
char pop(void);
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		top = 0;
		char str[51];
		scanf("%s", &str);
		for (int j = 0; j < strlen(str); j++){
			if (str[j] == '(')
				push(str[j]);
			else{
				if (pop() == -1) {
					top = -1;
					break;
				}
			}
		}
		if (top == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

void push(char c)
{
	stack[top++] = c;
}

char pop(void)
{
	if (top == 0)
		return -1;
	return stack[--top];
}


