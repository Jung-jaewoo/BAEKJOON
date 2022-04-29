#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int N;
	scanf("%d", &N);
	int* arr;
	arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	int i, j;
	for (i = 1; i < N; i++) {
		int tmp = arr[0];
		j = tmp < arr[i] ? tmp : arr[i];
		while (j>1) {
			if (arr[i] % j == 0 && tmp % j == 0) {
				tmp /= j;
				arr[i] /= j;
				j = tmp < arr[i] ? tmp : arr[i];
			}
			j--;
		}
		printf("%d/%d\n", tmp, arr[i]);
	}
	return 0;
}