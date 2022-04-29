#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[41];

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
	    int N;
	    scanf("%d", &N);
        if (N == 0)
            printf("%d %d\n", 1, 0);
        else if (N == 1)
            printf("%d %d\n", 0, 1);
        else
        {
            fibonacci(N);
            printf("%d %d\n", dp[N-1], dp[N]);
        }
    }
	return 0;
}


int fibonacci(int n) {
    if (n == 0) {
        dp[0]=0;
        return 0;
    }
    else if (n == 1) {
        dp[1]=1;
        return 1;
    }
    else {
        if (dp[n] != 0)
            return dp[n];
        else
        {
            dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
            return dp[n];
        }
    }
}
