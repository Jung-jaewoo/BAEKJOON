#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
int dp[10001];

int main()
{
	int n;
	scanf("%d", &n);
	int* podoju;
	podoju = (int*)malloc(sizeof(int) * (n+1));
	podoju[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &podoju[i]);
	dp[0] = 0;
	dp[1] = podoju[1];
	if (n >= 2)
		dp[2] = podoju[1] + podoju[2];
	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + podoju[i]);
		dp[i] = max(dp[i], dp[i - 3] + podoju[i - 1] + podoju[i]);
	}
	printf("%d", dp[n]);
	return 0;
}