#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int N;
	scanf("%d",&N);
	int* list;
	list = (int*)malloc(sizeof(int)*N);
	int i, j, num, position;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		position = i;
		for (j = 0; j < i; j++)
		{
			if (list[j] > num)
			{
				position = j;
				break;
			}
		}
		for (j = i; j > position; j--)
		{
			list[j] = list[j - 1];
		}
		list[position] = num;
	}
	for (i = 0; i < N; i++)
	{
		printf("%d\n",list[i]);
	}
	return 0;
}
