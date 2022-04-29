#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))

void divideandconquer(int first, int** arr, int N, int x, int y);
int main()
{
	int N, i, j;
	scanf("%d", &N);
	int** arr;
	arr = (int**)malloc(sizeof(int*) * N);
	char** strarr;
	strarr = (char**)malloc(sizeof(char*) * N);
	for (i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * N);
		strarr[i] = (char*)malloc(sizeof(char) * (N + 1));
	}
	for (i = 0; i < N; i++) {
		scanf("%s", strarr[i]);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			arr[i][j] = strarr[i][j]-'0';
		}
	}
	divideandconquer(1,arr, N,0,0);
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

void divideandconquer(int first, int **arr, int N, int x, int y) 
{
	int colorcheck = check(arr, N, x, y);
	if (colorcheck != -1) {
		if (colorcheck == 1) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	else {
		printf("(");
		divideandconquer(0, arr, N / 2, x, y);
		divideandconquer(0, arr, N / 2, x, y + (N / 2));
		divideandconquer(0, arr, N / 2, x + (N / 2), y);
		divideandconquer(0, arr, N / 2, x + (N / 2), y + (N / 2));
		printf(")");
	}
}
