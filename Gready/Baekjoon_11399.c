#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (((a)>(b)?(a):(b)))

int compare(const void* n1, const void* n2)
{
	int x, y;
	x = *(int*)n1;
	y = *(int*)n2;
	if (x > y)
		return 1;
	else if (x < y)
		return -1;
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), compare);
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i] * (n - i);
	printf("%d", sum);
	return 0;
}