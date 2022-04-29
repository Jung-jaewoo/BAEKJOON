#include <stdio.h>
#include <stdlib.h>
int dp[1001];
int list[1001];

int main()
{
	int n;
	scanf("%d", &n);
	int max, dpmax;
	dpmax = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &list[i]);
		max = 0;
		for (int j = 1; j < i; j++)
		{
			if (list[i] > list[j] && dp[j]>max)
				max = dp[j];
		}
		dp[i] = max + 1;
		if (dp[i] > dpmax)
			dpmax = dp[i];
	}
	printf("%d", dpmax);
	return 0;
}