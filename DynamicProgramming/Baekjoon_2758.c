#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))
ll dp[11][2001];
int main()
{
	int T, n, m;
	ll sum;
	scanf("%d", &T); 
	for (int i = 0; i < T; i++) {
		sum = 0;
		scanf("%d %d", &n, &m);
		for (int q = 1; q <= m; q++)
			dp[1][q] = 1;
		for (int q = 1; q <= m; q++) 
			dp[2][q] = q/2;
		for (int p = 3; p <= n; p++) {
			for (int q = 1; q <= m; q++) {
				if (q % 2 == 0)
					dp[p][q] = dp[p - 1][q / 2] + dp[p][q - 1];
				else
					dp[p][q] = dp[p][q - 1];
			}
		}
		for (int q = 1; q <= m; q++) {
			sum += dp[n][q];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
