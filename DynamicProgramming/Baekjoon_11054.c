#include <stdio.h>
#include <stdlib.h>
int dpas[1001];
int dpde[1001];
int list[1001];

int main()
{
	int n;
	scanf("%d", &n);
	int max, dpmax, tmp;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &list[i]);
		max = 0;
		for (int j = 1; j < i; j++)
		{
			if (list[i] > list[j] && dpas[j] > max)
				max = dpas[j];
		}
		dpas[i] = max + 1;
	}
	for (int i = n; i >= 1; i--)
	{
		max = 0;
		for (int j = n; j > i; j--)
		{
			if (list[i] > list[j] && dpde[j] > max)
				max = dpde[j];
		}
		dpde[i] = max + 1;
	}
	dpmax = 0;
	for (int i = 1; i <= n; i++)
	{
		tmp = dpas[i] + dpde[i];
		if (tmp > dpmax)
			dpmax = tmp;
	}
	printf("%d", dpmax - 1);
	return 0;
}