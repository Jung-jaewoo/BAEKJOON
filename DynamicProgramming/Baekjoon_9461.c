#include <stdio.h>

long long int dp[101];

long long int padoban(int N);

int main()
{
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        printf("%lld\n",padoban(N));
    }
    return 0;
}

long long int padoban(int N)
{
    if (dp[N] != 0)
        return dp[N];
    else
    {
        dp[N] = padoban(N - 1) + padoban(N - 5);
        return dp[N];
    }
}