#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int N;
	scanf("%d",&N);
	int num_count[8001] = { 0 };
	int num_index[8001] = { 0 };
	int i, j, num, sum;
	sum = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		num_count[num+4000]++;
		sum += num;
	}
	num_index[0] = num_count[0]-1;
	for (i = 1; i < 8001; i++)
	{
		num_index[i] = num_index[i-1] + num_count[i];
	}
	int mid;
	for (i = 0; i < 8001; i++)
	{
		if (num_count[i] == 0)
			continue;
		else
		{
			if (num_index[i] - num_count[i] + 1 <= (N - 1) / 2 && (N - 1) / 2 <= num_index[i])
			{
				mid = i - 4000;
				break;
			}
		}
	}
	int many, many_cnt, many_num;
	many = 0;
	many_cnt = 0;
	for (i = 0; i<8001; i++)
	{
		if (many < num_count[i])
		{
			many = num_count[i];
			many_num = i - 4000;
			many_cnt = 0;
		}
		else if(many == num_count[i] && many_cnt==0)
		{
			many_cnt = 1;
			many = num_count[i];
			many_num = i - 4000;
		}
	}
	int max, min;
	for (i = 0; i < 8001; i++)
	{
		if (num_count[i] != 0)
		{
			min = i - 4000;
			break;
		}
	}
	for (i = 8000; i >= 0; i--)
	{
		if (num_count[i] != 0)
		{
			max = i - 4000;
			break;
		}
	}
	if ((double)sum / N <0 && (double)sum / N >-0.5)
		printf("0\n");
	else
		printf("%.0lf\n", (double)sum / N);	//»ê¼úÆò±Õ
	printf("%d\n", mid);	//Áß¾Ó°ª
	printf("%d\n", many_num);	//ÃÖºó°ª
	printf("%d", max - min);	//¹üÀ§
	return 0;
}
