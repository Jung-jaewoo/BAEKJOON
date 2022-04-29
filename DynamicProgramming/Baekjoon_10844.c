#include <stdio.h>
#include <stdlib.h>
#define mod 1000000000
long long int dp[101][10];

int main()
{
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;
	int N;
	scanf("%d", &N);
	for (int i = 2; i < N+1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(j==0)
				dp[i][j] = dp[i - 1][j + 1];
			else if(j==9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%mod;
		}
	}
	long long int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[N][i])%mod;
	printf("%lld", sum);
	return 0;
}