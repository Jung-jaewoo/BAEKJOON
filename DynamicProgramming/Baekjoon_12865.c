#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int* weight;
	weight = (int*)malloc(sizeof(int) * (n+1));
	int* value;
	value = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++)
		scanf("%d %d", weight + i, value + i);
	int** dp;
	dp = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 1; i <= n; i++){
		dp[i] = (int*)malloc(sizeof(int) * (k + 1));
		dp[i][0] = 0;
	}
	for (int j = 1; j <= k; j++) {
		if (weight[1] <= j)
			dp[1][j] = value[1];
		else
			dp[1][j] = 0;
	}
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= k; j++){
			if (weight[i] <= j)
				dp[i][j] = max(dp[i - 1][j - weight[i]]+ value[i], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%d", dp[n][k]);
	return 0;
}