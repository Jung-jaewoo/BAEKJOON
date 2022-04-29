#include <iostream>
using namespace std;
int isprime[1000001] = { 0 };

void Eratosthenes(int M, int N);

int main()
{
	int M, N;
	cin >> M >> N;
	Eratosthenes(M, N);
	for (int i = M; i <= N; i++)
	{
		if (isprime[i] == 0)
			printf("%d\n", i);
	}

	return 0;
}

void Eratosthenes(int M, int N)
{
	isprime[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = i * 2; j <= N; j += i)
		{
			isprime[j] = 1;
		}
	}
}

