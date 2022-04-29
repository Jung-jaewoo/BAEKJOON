#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sudoku[9][9];

struct decart {
	int col, row;
};

int main()
{
	struct decart undet[81];
	int top = 0;
	int i, j, size;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			scanf("%d", &sudoku[i][j]);
			if (sudoku[i][j] == 0)
			{
				undet[top].row = i;
				undet[top++].col = j;
			}
		}
	}
	size = top;
	if (decide_number(undet, size, 0))
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
	}
}

int decide_number(struct decart* undet, int n, int k)
{
	if (n == k)
		return 1;
	else
	{
		int check[10];
		int i, j, m;
		for (i = 1; i < 10; i++)
		{
			check[i] = 0;
		}
		for (i = 0; i < 9; i++)
		{
			check[sudoku[undet[k].row][i]] = 1;
		}
		for (i = 0; i < 9; i++)
		{
			check[sudoku[i][undet[k].col]] = 1;
		}
		for (i=1;i<10;i++)
		{
			if (check[i] == 0)
			{
				for (j = (undet[k].row / 3) * 3; j < (undet[k].row / 3) * 3 + 3; j++)
				{
					for (m = (undet[k].col / 3) * 3; m < (undet[k].col / 3) * 3 + 3; m++)
					{
						check[sudoku[j][m]] = 1;
					}
				}
			}
			if (check[i] == 0)
			{
				sudoku[undet[k].row][undet[k].col] = i;
				if (decide_number(undet, n, k + 1) == 1)
					return 1;
				sudoku[undet[k].row][undet[k].col] = 0;
			}
		}
		return 0;
	}
}


