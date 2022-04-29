#include <iostream>
using namespace std;

int primenumber(int n);
int nextprime(int prime);

int main()
{
	int N;
	cin >> N;
	if (N == 1)
		return 0;
	int dprime = 2;
	while (primenumber(N) != 1)
	{
		if (N % dprime == 0)
		{
			cout << dprime << endl;
			N /= dprime;
		}
		else
			dprime = nextprime(dprime);
	}
	cout << N << endl;
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
	return 1;
}

int nextprime(int prime)
{
	int i = prime + 1;
	while(1)
	{
		if (primenumber(i) == 1)
			return i;
		i++;
	}
}