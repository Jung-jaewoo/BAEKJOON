#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
int** matrixmul(int** matrixA, int** matrixB, int N);
int** matrixpow(int** matrix, ll B, int N);
int main()
{
	int N;
	ll B;
	scanf("%d %lld", &N, &B);
	int** matrixAns;
	int** matrixtmp;
	matrixtmp = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
		matrixtmp[i] = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &matrixtmp[i][j]);
			if (matrixtmp[i][j] == 1000)
				matrixtmp[i][j] %= 1000;
		}
	}
	matrixAns = matrixpow(matrixtmp,B,N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", matrixAns[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int** matrixmul(int** matrixA, int** matrixB, int N) {
	int** matrixtmp;
	matrixtmp = (int**)malloc(sizeof(int*) * N);
	for(int i=0; i<N; i++)
		matrixtmp[i] = (int*)malloc(sizeof(int) * N);
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp = 0;
			for (int k = 0; k < N; k++) {
				 tmp += matrixA[i][k] * matrixB[k][j];
			}
			matrixtmp[i][j] = tmp % 1000;
		}
	}
	return matrixtmp;
}

int** matrixpow(int** matrix, ll B, int N) {
	int** x, **ans;
	x = matrix;
	ans = matrix;
	B--;
	while (B > 0) {
		if (B % 2 != 0) {
			ans = matrixmul(ans, x, N);
		}
		x = matrixmul(x, x, N);
		B /= 2;
	}
	return ans;
}
