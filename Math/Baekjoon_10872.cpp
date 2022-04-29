#include <iostream>
using namespace std;

int Factorial(int n);

int main()
{
	int N;
	cin >> N;
	cout << Factorial(N);
	
	return 0;
}

int Factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * Factorial(n - 1);
}
