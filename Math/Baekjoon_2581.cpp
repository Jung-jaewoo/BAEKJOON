#include <iostream>
using namespace std;

int primenumber(int n);

int main()
{
	int M, N;
	cin >> M >> N;
	int sum = 0;
	int min = N;
	for (int i = M; i <= N; i++)
	{
		int n;
		n = primenumber(i);
		if (n != 0)
		{
			if (min > n)
				min = n;
			sum += n;
		}
	}
	if (sum == 0)
		cout << -1 << endl;
	else
		cout << sum<< "\n" << min << endl;
	return 0;
}

int primenumber(int n)
{
	if (n == 1)
		return 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return n;
}