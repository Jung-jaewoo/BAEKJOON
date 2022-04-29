#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int w(int a, int b, int c);
int dp[21][21][21];

int main()
{
    int a, b, c;
    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}


int w(int a, int b, int c)
{
    int w1, w2, w3, w4;
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    else if (a < b && b < c)
    {
        if (dp[a][b][c - 1] != 0)
            w1 = dp[a][b][c - 1];
        else
            w1 = w(a, b, c - 1);
        if (dp[a][b - 1][c - 1] != 0)
            w2 = dp[a][b - 1][c - 1];
        else
            w2 = w(a, b - 1, c - 1);
        if (dp[a][b - 1][c] != 0)
            w3 = dp[a][b - 1][c];
        else 
            w3 = w(a, b - 1, c);
        dp[a][b][c] = w1 + w2 - w3;
        return  dp[a][b][c];
    }
    else
    {
        if (dp[a-1][b][c] != 0)
            w1 = dp[a - 1][b][c];
        else
            w1 = w(a - 1, b, c);
        if (dp[a-1][b - 1][c] != 0)
            w2 = dp[a - 1][b - 1][c];
        else
            w2 = w(a - 1, b - 1, c);
        if (dp[a - 1][b][c - 1] != 0)
            w3 = dp[a - 1][b][c - 1];
        else
            w3 = w(a - 1, b, c - 1);
        if (dp[a - 1][b - 1][c - 1] != 0)
            w4 = dp[a - 1][b - 1][c - 1];
        else
            w4 = w(a - 1, b - 1, c - 1);
        dp[a][b][c] = w1 + w2 + w3 - w4;
        return  dp[a][b][c];
    }
}