#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define min(a,b) ((a<b)?(a):(b))
int sol;
int max, min, mid;
void binaryserch(int* arr, int N, int M);
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int* arr;
	arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
		if (max < arr[i])
			max = arr[i];
	}
	binaryserch(arr, N, M);
	printf("%d", sol);
	return 0;

	//test
}

void binaryserch(int* arr, int N, int M) {
	while (min <= max) {
		ll sum = 0;
		mid = (max + min) / 2;
		for (int i = 0; i < N; i++) {
			if(arr[i]-mid>0)
				sum += (ll)arr[i] - mid;
		}
		if (sum < M)
			max = mid - 1;
		else {
			if (sol < mid)
				sol = mid;
			min = mid + 1;
		}
	}
}