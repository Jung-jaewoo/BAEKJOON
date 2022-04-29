#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main()
{	
	int N;
	scanf("%d",&N);
	int* list;
	list = (int*)malloc(sizeof(int)*N);
	int i, j;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &list[i]);
	}
	sort(list, list + N);
	for (i = 0; i < N; i++)
	{
		printf("%d\n", list[i]);
	}
	return 0;
}
