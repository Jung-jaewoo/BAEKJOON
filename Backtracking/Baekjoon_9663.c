#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct decart {
	int x, y;
};
int sum = 0;

int queennum(struct decart* queenpoint, int n, int k);
int queenpointcheck(struct decart* queenpoint, struct decart point, int k);

int main()
{
	int N;
	scanf("%d",&N);
	struct decart* queenpoint;
	queenpoint = (struct decart*)malloc(sizeof(struct decart) * N);
	for (int i = 0; i < N; i++)
		queenpoint[i].x = -1;
	queennum(queenpoint ,N, 0);
	printf("%d", sum);
	return 0;
}

int queennum(struct decart* queenpoint, int n, int k)
{
	if (n == k)
		sum++;
	else
	{
		int i;
		struct decart tmp;
		for (i = 0; i < n; i++)
		{
			tmp.x = k;
			tmp.y = i;
			if (queenpointcheck(queenpoint, tmp,k) == 1)
				queennum(queenpoint, n, k + 1);
		}
	}
}

int queenpointcheck(struct decart* queenpoint, struct decart point, int k)
{
	int i = 0;
	while (i<k)
	{
		if (queenpoint[i].y == point.y)
			return 0;
		else if (queenpoint[i].x - queenpoint[i].y == point.x - point.y)
			return 0;
		else if (queenpoint[i].x + queenpoint[i].y == point.x + point.y)
			return 0;
		i++;
	}
	queenpoint[k] = point;
	return 1;
}

