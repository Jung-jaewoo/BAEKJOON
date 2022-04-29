#include <stdio.h>
#include <stdlib.h>

struct decart {
	int x, y;
};

int compare(const void* one, const void* two) {
	struct decart* d_one;
	struct decart* d_two;
	d_one = (struct decart*)one;
	d_two = (struct decart*)two;
	if (d_one->x > d_two->x)
		return 1;
	else if (d_one->x < d_two->x)
		return -1;
	else
	{
		if (d_one->y > d_two->y)
			return 1;
		else if (d_one->y < d_two->y)
			return -1;
		else
			return 0;
	};
}

int main()
{
	int N;
	scanf("%d",&N);
	int i, j;
	struct decart* arr;
	arr = (struct decart*)malloc(sizeof(struct decart) * N);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	qsort(arr, N, sizeof(struct decart), compare);
	for (i = 0; i < N; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
	return 0;
}
