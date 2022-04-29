#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ((a)>(b)?(b):(a))
void makeonenum(int* dp, int n);

int main()
{
	int n;
	scanf("%d", &n);
	int* dp;
	dp = (int*)malloc(sizeof(int) * n+1);
	dp[1] = 0;
	makeonenum(dp, n);
	printf("%d", dp[n]);
	return 0;
}

void makeonenum(int* dp, int n)
{
	for (int i = 2; i < n+1; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}	
}