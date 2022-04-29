#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int n;
	scanf("%d", &n);
	int* list;
	list = (int*)malloc(sizeof(int) * n);
	int* cur;
	cur = (int*)malloc(sizeof(int) * n);
	int ret = -1000;
	scanf("%d", &list[0]);
	cur[0] = list[0];
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &list[i]);
		cur[i] = max(cur[i - 1] + list[i], list[i]);
		ret = max(ret, cur[i]);
	}
	ret = max(ret, cur[0]);
	printf("%d", ret);
	return 0;
}