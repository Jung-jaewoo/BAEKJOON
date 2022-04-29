#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
	int n;
	scanf("%d", &n);
	int* list;
	list = (int*)malloc(sizeof(int) * n);
	int* maxsum;
	maxsum = (int*)malloc(sizeof(int) * n);
	int* cur;
	cur = (int*)malloc(sizeof(int) * n);
	
	scanf("%d", &list[0]);
	if (list[0] < 0)
		cur[0] = 0;
	else
		cur[0] = list[0];
	maxsum[0] = list[0];
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &list[i]);
		if (cur[i - 1] + list[i] < 0)
		{
			cur[i] = 0;
			maxsum[i] = max(maxsum[i - 1], list[i]);
		}
		else
		{
			cur[i] = cur[i-1] + list[i];
			maxsum[i] = max(cur[i], maxsum[i - 1]);
		}
	}
	printf("%d", maxsum[n - 1]);
	return 0;
}