#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (((a)>(b)?(a):(b)))
typedef struct {
	int start, end;
}staend;

int compare(const void* n1, const void* n2)
{
	staend x, y;
	x = *(staend*)n1;
	y = *(staend*)n2;
	if (x.end > y.end)
		return 1;
	else if (x.end < y.end)
		return -1;
	else
	{
		if (x.start > y.start)
			return 1;
		else if (x.start < y.start)
			return -1;
		else
			return 0;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	staend* arr;
	arr = (staend*)malloc(sizeof(staend) * n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].start, &arr[i].end);
	qsort(arr, n, sizeof(staend), compare);
	int sum = 0;
	int cnt = 0;
	int time = 0;
	while (cnt < n)
	{
		if (time <= arr[cnt].start) {
			sum++;
			time = arr[cnt].end;
		}
		cnt++;
	}
	printf("%d", sum);
	return 0;
}