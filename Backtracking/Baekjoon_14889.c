#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int min = 1000000000;
int check[21] = { 0 };
void maketeam(int* team, int** ability, int n, int k);

int main()
{
	int N, i, j;
	scanf("%d", &N);
	int* team;
	team = (int*)malloc(sizeof(int) * (N/2));
	team[0] = 1;
	int** ability;
	ability = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++)
		ability[i] = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &ability[i][j]);
		}
	}
	check[1] = 1;
	maketeam(team, ability, N, 1);
	printf("%d", min);
	free(team);
	free(ability);
	return 0;
}

void maketeam(int* team, int**ability, int n, int k)
{
	if (n/2 == k)
	{
		int i, j;
		int sum1 = 0;
		int sum2 = 0;
		for (i = 1; i < n + 1; i++)
		{
			for (j = 1; j < n + 1; j++)
			{
				if (check[i] == 1 && check[j] == 1)
					sum1 += ability[i-1][j-1];
				if (check[i] == 0 && check[j] == 0)
					sum2 += ability[i-1][j-1];
			}
		}
		int result = sum1 > sum2 ? sum1 - sum2 : sum2 - sum1;
		if (min > result)
			min = result;
	}
	else
	{
		int i;
		for (i = team[k-1]; i < n+1; i++)
		{
			if (check[i] == 0 )
			{
				team[k] = i;
				check[i] = 1;
				maketeam(team, ability, n, k + 1);
				check[i] = 0;
			}
		}
	}
}

