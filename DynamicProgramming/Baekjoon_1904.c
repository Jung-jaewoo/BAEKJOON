#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[1000001];

int sequencenum(int N);

int main()
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    int N;
    scanf("%d", &N);
    printf("%d",sequencenum(N));
    return 0;
}

int sequencenum(int N)
{
    if (N == 0)
        return 1;
    else if (N == 1)
        return 1;
    else if (N == 2)
        return 2;
    else
    {
        if (dp[N] != 0)
            return dp[N];
        if (N % 2 == 0)
            return dp[N] = ((sequencenum(N / 2) * sequencenum(N / 2))%15746+ (sequencenum(N / 2 - 1) * sequencenum(N / 2 - 1))%15746) % 15746;
        else
            return dp[N] = ((sequencenum(N / 2 + 1) * sequencenum(N / 2)) % 15746 + (sequencenum(N / 2) * sequencenum(N / 2 - 1)) % 15746) % 15746;
    }
}