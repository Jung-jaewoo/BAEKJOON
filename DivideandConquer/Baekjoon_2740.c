#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

int main()
{
	int N, M, K;
	scanf("%d %d", &N, &M);
	int** matrixA;
	matrixA = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
		matrixA[i] = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &matrixA[i][j]);
	}
	scanf("%d %d", &M, &K);
	int** matrixB;
	matrixB = (int**)malloc(sizeof(int*) * M);
	for (int i = 0; i < M; i++)
		matrixB[i] = (int*)malloc(sizeof(int) * K);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++)
			scanf("%d", &matrixB[i][j]);
	}
	int** matrixANS;
	matrixANS = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
		matrixANS[i] = (int*)malloc(sizeof(int) * K);
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			tmp = 0;
			for (int k = 0; k < M; k++) {
				tmp += matrixA[i][k] * matrixB[k][j];
			}
			matrixANS[i][j] = tmp;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			printf("%d ", matrixANS[i][j]);
		}
		printf("\n");
	}
	return 0;
}
