#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))
int white, blue;
void divideandconquer(int** arr, int N, int x, int y);
int main()
{
	int N, i, j;
	scanf("%d", &N);
	int** arr;
	arr = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++)
		arr[i] = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	}
	divideandconquer(arr, N,0,0);
	printf("%d\n%d", white, blue);
	return 0;
}

int check(int **arr, int N, int x, int y)
{
	int color;
	int i, j;
	color = arr[x][y];
	for (i = x; i < x + N; i++) {
		for (j = y; j < y + N; j++) {
			if (arr[i][j] != color) {
				return -1;
			}
		}
	}
	return color;
}

void divideandconquer(int **arr, int N, int x, int y) 
{
	int colorcheck = check(arr, N, x, y);
	if (colorcheck != -1) {
		if (colorcheck == 1)
			blue++;
		else 
			white++;
	}
	else {
		divideandconquer(arr, N / 2, x, y);
		divideandconquer(arr, N / 2, x, y + (N / 2));
		divideandconquer(arr, N / 2, x + (N / 2), y);
		divideandconquer(arr, N / 2, x + (N / 2), y + (N / 2));
	}
}
