#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))
int num_m1, num_1, num_0;
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
	divideandconquer(arr, N, 0, 0);
	printf("%d\n%d\n%d", num_m1, num_0, num_1);
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
				return -10;
			}
		}
	}
	return color;
}

void divideandconquer(int **arr, int N, int x, int y) 
{
	int colorcheck = check(arr, N, x, y);
	if (colorcheck != -10) {
		if (colorcheck == 1)
			num_1++;
		else if (colorcheck == 0)
			num_0++;
		else
			num_m1++;
	}	
	else {
		divideandconquer(arr, N / 3, x, y);
		divideandconquer(arr, N / 3, x, y + (N / 3));
		divideandconquer(arr, N / 3, x, y + (N / 3) * 2);
		divideandconquer(arr, N / 3, x + (N / 3), y);
		divideandconquer(arr, N / 3, x + (N / 3), y + (N / 3));
		divideandconquer(arr, N / 3, x + (N / 3), y + (N / 3) * 2);
		divideandconquer(arr, N / 3, x + (N / 3)*2, y);
		divideandconquer(arr, N / 3, x + (N / 3) * 2, y + (N / 3));
		divideandconquer(arr, N / 3, x + (N / 3) * 2, y + (N / 3) * 2);
	}
}
