#include <iostream>
#include <cmath>
using namespace std;

int isprime[246912] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, sum;
	while (1)
	{
		sum = 0;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 2; i <= 2*n; i++)
		{
			for (int j = 2; i * j <= 2 * n; j++)
			{
				isprime[i * j] = 1;
			}
		}
		for (int i = n + 1; i <= 2*n; i++)
		{
			if (isprime[i] == 0)
				sum ++;
		}
		cout << sum << "\n";
	}
	return 0;
}
