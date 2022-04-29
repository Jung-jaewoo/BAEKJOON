#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int n;
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	int* dpmax;
	dpmax = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	dpmax[0] = arr[0];
	int max, dpmaxmax;
	dpmaxmax = 0;
	for (int i = 1; i < n; i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				if (dpmax[j] > max)
					max = dpmax[j];
			}
			dpmax[i] = max + arr[i];
		}
		if (dpmaxmax < dpmax[i])
			dpmaxmax = dpmax[i];
	}
	printf("%d", dpmaxmax);
	return 0;
}