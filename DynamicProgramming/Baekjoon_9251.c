#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
	char string1[1000];
	char string2[1000];
	scanf("%s", string1);
	scanf("%s", string2);
	int tmp;
	int* dp;
	int* predp;
	int n1 = strlen(string1);
	int n2 = strlen(string2);
	dp = (int*)malloc(sizeof(int) * (n1+1));
	predp = (int*)malloc(sizeof(int) * (n1+1));
	for (int i = 0; i <= n1; i++)
	{
		predp[i] = 0;
		dp[i] = 0;
	}
	for (int i = 0; i < n2; i++)
	{
		dp[0] = 0;
		for (int j = 0; j < n1; j++)
		{
			if (string2[i]==string1[j])
			{
				predp[j+1] = dp[j+1];
				dp[j + 1] = predp[j] + 1;
			}
			else
			{
				tmp = dp[j + 1];
				dp[j + 1] = max(dp[j + 1], dp[j]);
				predp[j + 1] = tmp;
			}
		}
	}
	printf("%d", dp[n1]);
	return 0;
}