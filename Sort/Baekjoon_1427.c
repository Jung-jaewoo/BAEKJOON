#include <stdio.h>
#include <stdlib.h>

int compare(const void* one, const void* two) {
	if (*(int*)one > * (int*)two)
		return -1;
	else if (*(int*)one < *(int*)two)
		return 1;
	else return 0;
}

int main()
{	
	int N;
	scanf("%d",&N);
	int num_arry[10] = { 0 };
	int size = 0;
	int i = 0;
	while (N != 0)
	{
		num_arry[i] = N % 10;
		N /= 10;
		size++;
		i++;
	}
	qsort(num_arry, 10, sizeof(int),compare);
	for (i = 0; i < size; i++)
	{
		printf("%d", num_arry[i]);
	}
	return 0;
}
