#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max, min;
max = -1000000000;
min = 1000000000;

void decide_operation(int* operand, int* operation_num, int result, int n, int k);

int main()
{
	int N, i;
	scanf("%d", &N);
	int* operand;
	operand = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		scanf("%d", operand +i);
	int operation_num[4];
	
	for (i = 0; i < 4; i++)
		scanf("%d", operation_num + i);
	decide_operation(operand, operation_num, operand[0], N-1, 0);
	printf("%d\n%d", max, min);
}

void decide_operation(int * operand, int* operation_num, int result, int n, int k)
{
	if (n == k)
	{
		if (max < result)
			max = result;
		if (min > result)
			min = result;
	}
	else
	{
		int i;
		for (i = 0; i < 4; i++)
		{
			if (operation_num[i] > 0)
			{
				switch (i)
				{
				case 0:
					operation_num[i]--;
					decide_operation(operand, operation_num, result + operand[k + 1], n, k + 1);
					operation_num[i]++;
					break;
				case 1:
					operation_num[i]--;
					decide_operation(operand, operation_num, result - operand[k + 1], n, k + 1);
					operation_num[i]++;
					break;
				case 2:
					operation_num[i]--;
					decide_operation(operand, operation_num, result * operand[k + 1], n, k + 1);
					operation_num[i]++;
					break;
				case 3:
					operation_num[i]--;
					decide_operation(operand, operation_num, result / operand[k + 1], n, k + 1);
					operation_num[i]++;
					break;
				default:
					break;
				}
			}
		}
	}
}

