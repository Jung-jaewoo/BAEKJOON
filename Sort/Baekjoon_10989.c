#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int N;
	scanf("%d",&N);
	int num_count[10001] = { 0 };
	int num_index[10001] = { 0 };
	int i, j, num;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		num_count[num]++;
	}
	num_index[0] = num_count[0]-1;
	for (i = 1; i < 10001; i++)
	{
		num_index[i] = num_index[i-1] + num_count[i];
	}
	for (i = 0; i<10001; i++)
	{
		for (j = 0; j < num_count[i]; j++)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
