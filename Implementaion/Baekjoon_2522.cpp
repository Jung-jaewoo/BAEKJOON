#include <iostream>
using namespace std;

int main()
{	
	int N;
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < N - i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}