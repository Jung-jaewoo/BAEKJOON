#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int n, k; // 동전 개수, 가치합
	scanf("%d %d", &n, &k);
	int* coin;
	coin = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++){
		scanf("%d", coin + i);
	}
	int sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += k / coin[i];
		k -= (k / coin[i]) * coin[i];
		if (k == 0)
			break;
	}
	printf("%d", sum);
	return 0;
}