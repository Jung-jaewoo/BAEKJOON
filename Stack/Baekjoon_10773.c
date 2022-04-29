#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))
int stack[100000];
int stacktop = 0;
void push(int n);
int pop(void); 
int main()
{
	int k;
	scanf("%d", &k);
	int sum = 0;
	for (int i = 0; i < k; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0) {
			sum -=pop();
		}
		else {
			sum += tmp;
			push(tmp);
		}
	}
	printf("%d", sum);
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



