#include <iostream>
using namespace std;

int main()
{	
	int M, N;
	cin >> M >> N;
	char** chess;
	chess = new char*[M];
	for (int i = 0; i < M; i++)
	{
		chess[i] = new char[N];
		cin >> chess[i];
	}
	int min = 8 * 8;
	char wb[2] = { 'W','B' };
	int n, num;
	for (int i = 0; i < M - 7; i++)
	{
		for (int j = 0; j < N - 7; j++)
		{
			num = 0;
			if (chess[i][j] == 'W')
				n = 0;
			else
				n = 1;
			for (int l = 0; l < 8; l++)
			{
				for (int m = 0; m < 8; m++)
				{
					if (chess[i + l][j + m] != wb[n])
						num++;
					n = (n + 1) % 2;
				}
				n = (n + 1) % 2;
			}
			if (num > 32)
				num = 64 - num;
			if (num < min)
				min = num;
		}
	}
	cout << min;
	return 0;
}
