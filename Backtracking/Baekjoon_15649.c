#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_order_array(int* order, int m);
void permutation(int *order, int k, int n, int m);

int main()
{
	int N, M;
	scanf("%d %d",&N, &M);
	int* order;
	order = (int*)malloc(sizeof(int) * (M+1));
	permutation(order, 0, N, M);
	return 0;
}

void print_order_array(int* order, int m)
{
	for (int i = 1; i < m+1; i++)
	{
		printf("%d ", order[i]);
	}
	printf("\n");
}

void permutation(int *order, int k, int n, int m)
{
	if (k == m)
		print_order_array(order, m);
	else
	{
		int* check;
		check = (int*)malloc(sizeof(int) * (n+1));
		for (int i = 1; i < n+1; i++)
			check[i] = 0;
		for (int i = 1; i < k+1; i++)
			check[order[i]] = 1;
		for (int i = 1; i < n+1; i++)
		{
			if (check[i] == 0)
			{
				order[k+1] = i;
				permutation(order, k + 1, n, m);
			}
		}
	}
}

