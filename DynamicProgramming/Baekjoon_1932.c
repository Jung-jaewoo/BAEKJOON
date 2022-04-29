#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

int main()
{
	int n;
	scanf("%d", &n);
	int** triangle;
	triangle = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		triangle[i] = (int*)malloc(sizeof(int) * i+1);
	scanf("%d", &triangle[0][0]);
	int tmp;
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &tmp);
			if (j == 0)
				triangle[i][j] = triangle[i - 1][0] + tmp;
			else if (j == i)
				triangle[i][j] = triangle[i - 1][j - 1] + tmp;
			else
				triangle[i][j] = max(triangle[i - 1][j - 1], triangle[i - 1][j]) + tmp;
		}
	}
	int max = triangle[n-1][0];
	for (int i = 1; i < n; i++) {
		max = max(max, triangle[n - 1][i]);
	}
	printf("%d", max);
	return 0;
}