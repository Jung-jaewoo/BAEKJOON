#include <stdio.h>
#include <stdlib.h>
#define min(a,b) a>b ? b : a

int main()
{
	int N;
	scanf("%d", &N);
	int** RGBsum;
	RGBsum = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
		RGBsum[i] = (int*)malloc(sizeof(int) * 3);
	scanf("%d %d %d", &RGBsum[0][0], &RGBsum[0][1], &RGBsum[0][2]);
	int R, G, B;
	for (int i = 1; i < N; i++)
	{
		scanf("%d %d %d", &R,&G,&B);
		RGBsum[i][0] = min(RGBsum[i - 1][1] + R, RGBsum[i - 1][2] + R);
		RGBsum[i][1] = min(RGBsum[i - 1][0] + G, RGBsum[i - 1][2] + G);
		RGBsum[i][2] = min(RGBsum[i - 1][0] + B, RGBsum[i - 1][1] + B);
	}
	int tmp = min(RGBsum[N - 1][0], RGBsum[N - 1][1]);
	tmp = min(tmp, RGBsum[N - 1][2]);
	printf("%d", tmp);
	return 0;
}