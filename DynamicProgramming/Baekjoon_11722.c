#include <stdio.h>
#include <stdlib.h>
int dpde[1001];
int list[1001];

int main()
{
	int n;
	scanf("%d", &n);
	int max, dpmax, tmp;
	dpmax = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &list[i]);
		max = 0;
		for (int j = 1; j < i; j++)
		{
			if (list[i] < list[j] && dpde[j] > max)
				max = dpde[j];
		}
		dpde[i] = max + 1;
		if (dpde[i] > dpmax)
			dpmax = dpde[i];
	}
	printf("%d",dpmax);
	return 0;
}