#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int n;
	scanf("%d", &n);
	int* distance;
	distance = (int*)malloc(sizeof(int) * (n - 1));
	int* expense;
	expense = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n - 1; i++)
		scanf("%d", distance + i);
	for (int i = 0; i < n; i++)
		scanf("%d", expense + i);
	int end = n - 1;
	ll sum = 0;
	int min = expense[0];
	sum += (long long)min * distance[0];
	for (int i = 1; i < n - 1; i++){
		if (expense[i] < min)
			min = expense[i];
		sum += (long long)min * distance[i];
	}
	printf("%lld", sum);
	return 0;
}