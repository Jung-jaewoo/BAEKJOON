#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define MOD 1000000007
void matrixmul(ll matrixA[2][2], ll matrixB[2][2]);
void matrixpow(ll matrix[2][2], ll n);
ll fibonacci(ll n);
int main()
{
	ll n;
	scanf("%lld", &n);
	printf("%lld",fibonacci(n));
	return 0;
}

void matrixmul(ll matrixA[2][2], ll matrixB[2][2]) {
	ll matrixtmp[2][2] = { 0 };
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++) 
			for (int k = 0; k < 2; k++) 
				matrixtmp[i][j] += matrixA[i][k] * matrixB[k][j];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			matrixA[i][j] = matrixtmp[i][j] % MOD;
}

void matrixpow(ll matrix[2][2], ll n) {
	if (n == 0 || n == 1) return;
	ll matrixtmp[2][2] = { 0,1,1,1 };
	matrixpow(matrix, n >> 1);
	matrixmul(matrix, matrix);
	if (n & 1) matrixmul(matrix, matrixtmp);
}

ll fibonacci(ll n) {
	ll rest;
	ll tmp = n;
	ll matrixtmp[2][2] = { 0,1,1,1 };
	if (n == 0) return 0;
	else if (n == 1 || n == 2) return 1;
	else matrixpow(matrixtmp, n);
	return matrixtmp[0][1];
}