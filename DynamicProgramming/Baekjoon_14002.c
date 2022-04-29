#include <stdio.h>
#include <stdlib.h>
int dp[1001];
int list[1001];

int main()
{
	int n;
	scanf("%d", &n);
	int max, dpmax, dpindex;
	dpmax = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &list[i]);
		max = 0;
		for (int j = 1; j < i; j++)
		{
			if (list[i] > list[j] && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max + 1;
		if (dp[i] > dpmax)
		{
			dpmax = dp[i];
			dpindex = i;
		}
	}
	printf("%d\n", dpmax);
	int num = dpmax;
	int* arr;
	arr = (int*)malloc(sizeof(int) * dpmax);
	for(int i = dpindex; i >= 0; i--)
	{
		if (dp[i] == num)
		{
			arr[num-1] = list[i];
			num--;
		}
	}
	for (int i = 0; i < dpmax; i++)
		printf("%d ", arr[i]);
	return 0;
}