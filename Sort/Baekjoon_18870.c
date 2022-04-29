#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rank {
	int num;
	int index;
};

int compare(const void* one, const void* two) {
	struct rank* x;
	struct rank* y;
	x = (struct rank*)one;
	y = (struct rank*)two;
	if (x->num > y->num)
		return 1;
	else if (x->num < y->num)
		return -1;
	else
		return 0;
}

int main()
{
	int N;
	scanf("%d",&N);
	int i, j;
	struct rank* arr;
	arr = (struct rank*)malloc(sizeof(struct rank) * N);
	int* rank;
	rank = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i].num);
		arr[i].index = i;
	}
	qsort(arr, N, sizeof(struct rank), compare);
	int count = 1;
	rank[arr[0].index] = 0;
	for (i = 1; i < N; i++)
	{
		if (arr[i].num == arr[i - 1].num)
			rank[arr[i].index] = rank[arr[i-1].index];
		else
		{
			rank[arr[i].index] = count;
			count++;
		}
	}
	for (i = 0; i < N; i++)
	{
		printf("%d ", rank[i]);
	}
	return 0;
}
