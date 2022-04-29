#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b) ?(a) :(b))
struct scoresum {
	int step1, step2;
};

int main()
{
	int n;
	scanf("%d", &n);
	int* stair;
	stair = (int*)malloc(sizeof(int) * n);
	struct scoresum *sum;
	sum = (struct scoresum*)malloc(sizeof(struct scoresum) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &stair[i]);
	if (n == 1)
		printf("%d", stair[0]);
	else
	{
		sum[0].step1 = stair[0];
		sum[1].step1 = sum[0].step1 + stair[1];
		sum[1].step2 = stair[1];
		printf("%d", maxscore(stair, sum, n, 2));
	}
	return 0;
}

int maxscore(int stair[], struct scoresum* sum, int n, int k)
{
	if (n == k)
	{
		return max(sum[k - 1].step1, sum[k - 1].step2);
	}
	else
	{ 
		sum[k].step1 = stair[k] + sum[k - 1].step2;
		sum[k].step2 = stair[k] + max(sum[k - 2].step1, sum[k - 2].step2);
		maxscore(stair, sum, n, k + 1);
	}
}
