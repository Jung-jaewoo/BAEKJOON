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
	while(1){
		top = 0;
		char str[101];
		gets(str);
		if (strcmp(str, ".") == 0)
			break;
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == '('||str[j]=='[')
				push(str[j]);
			else if(str[j] == ')') {
				if (pop() != '(') {
					top = -1;
					break;
				}
			}
			else if (str[j] == ']') {
				if (pop() != '[') {
					top = -1;
					break;
				}
			}
		}
		if (top == 0)
			printf("yes\n");
		else
			printf("no\n");
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



