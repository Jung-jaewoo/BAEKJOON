#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))
int dp[1001][1001];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", combination(N, K));
	return 0;
}

int combination(int n, int r)
{
	if (dp[n][r] != 0)
		return dp[n][r];
	else if (n == r || r==0)
		return dp[n][r] = 1;
	else if (r == 1)
		return dp[n][r] = n;
	else
	{
		return dp[n][r] = (combination(n - 1, r) + combination(n - 1, r - 1)) % 10007;
	}
}