#include <stdio.h>
#include <stdlib.h>

int dp[501];
int line[501];

int main()
{
	int n, tmp, max, dpmax, indexmax;
	indexmax = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&tmp);
		if (tmp > indexmax)
			indexmax = tmp;
		scanf("%d", &line[tmp]);
	}
	dpmax = 0;
	for (int i = 1; i <= indexmax; i++)
	{
		max = 0;
		for (int j = 1; j < i; j++)
		{
			if (line[j]!=0 && line[i] > line[j] && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max + 1;
		if (dp[i] > dpmax)
			dpmax = dp[i];
	}
	printf("%d", n - dpmax);
	return 0;
}