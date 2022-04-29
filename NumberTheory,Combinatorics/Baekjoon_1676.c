#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int N;
	scanf("%d", &N);
	int zero = 0;
	while (N>=5) {
		zero += N / 5;
		N /= 5;
	}
	printf("%d", zero);
	return 0;
}