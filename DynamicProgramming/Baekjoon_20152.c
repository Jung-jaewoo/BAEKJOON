#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long int** dp;
	long long int h, n;
	scanf("%d %d", &h, &n);
	int length = abs(h - n);
	dp = (long long int**)malloc(sizeof(long long int*) * (length + 1));
	for (int i = 0; i < length + 1; i++)
	{
		dp[i] = (long long int*)malloc(sizeof(long long int) * (i + 1));
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)
				dp[i][j] = 1;
			else if (j == i)
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	printf("%lld", dp[length][length]);
	return 0;
}