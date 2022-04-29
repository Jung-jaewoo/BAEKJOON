#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))
int sol[500];
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
	int N;
	scanf("%d", &N);
	int* arr;
	arr = (int*)malloc(sizeof(int) * N);
	int* diff;
	diff = (int*)malloc(sizeof(int) * (N - 1));
	scanf("%d", &arr[0]);
	for (int i = 1; i < N; i++) {
		scanf("%d", arr + i);
		diff[i - 1] = abs(arr[i] - arr[i - 1]);
	}
	qsort(arr, N, sizeof(int), compare);
	int tmp = arr[1] - arr[0];
	for (int i = 2; i < N; i++)
		tmp = gcd(tmp, arr[i] - arr[i - 1]);
	int count = 0;
	for (int i = 1; i * i <= tmp; i++) {
		if (tmp % i == 0) {
			sol[count++] = i;
			if (i != tmp / i)
				sol[count++] = tmp / i;
		}
	}
	qsort(sol, count, sizeof(int), compare);
	for (int i = 0; i < count; i++) {
		if (sol[i] != 1)
			printf("%d ", sol[i]);
	}
	return 0;
}

int gcd(int x, int y)
{
	int tmp;
	if (x < y) {
		tmp = x;
		x = y;
		y = tmp;
	}
	while (y != 0) {
		tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}


