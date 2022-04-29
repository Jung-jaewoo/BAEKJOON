#include <iostream>
using namespace std;

int primenumber(int n);

int main()
{
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		sum += primenumber(n);
	}
	cout << sum << endl;
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