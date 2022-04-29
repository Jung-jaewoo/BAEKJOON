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
	int** dp;
	int n1 = strlen(string1);
	int n2 = strlen(string2);
	dp = (int**)malloc(sizeof(int*) * (n2+1));
	for(int i=0; i<=n2; i++)
		dp[i] = (int*)malloc(sizeof(int) * (n1+1));
	for (int i = 0; i <= n2; i++)
	{
		dp[i][0] = 0;
	}
	for (int j = 0; j <= n1; j++)
	{
		dp[0][j] = 0;
	}
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			if (string2[i]==string1[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i+1][j + 1] = max(dp[i][j + 1], dp[i+1][j]);
		}
	}
	printf("%d\n", dp[n2][n1]);
	int i, j, stringindex;
	i = n2;
	j = n1;
	char* string3;
	string3 = (char*)malloc(sizeof(char) * (dp[n2][n1] + 1));
	stringindex = dp[n2][n1];
	string3[stringindex--] = '\0';
	while (1)
	{
		if (i < 1 || j < 1)
			break;
		if (string2[i-1] == string1[j-1])
		{
			string3[stringindex--] = string1[j-1];
			i--;
			j--;
		}
		else
		{
			if (dp[i][j - 1] > dp[i - 1][j])
				j--;
			else
				i--;
		}
	}
	printf("%s", string3);
	return 0;
}