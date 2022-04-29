#include <iostream>
using namespace std;

int main()
{	
	int N, M;
	cin >> N >> M;
	
	int list[100] = { 0 };
	int i, j, k;
	for (i = 0; i < N; i++)
		cin >> list[i];
	int sum, max;
	max = 0;
	for (i = 0; i < N-2; i++)
	{
		for (j = i+1; j < N-1; j++)
		{
			for (k = j+1; k < N; k++)
			{
				sum = list[i]+list[j]+list[k];
				if (sum > max && sum<=M)
					max = sum;
			}
		}
	}
	printf("%d\n", max);

	return 0;
}
