#include <iostream>
#include <cmath>
using namespace std;

int isprime[10001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int j = 2; j < n; j++)
		{
			for (int k = 2; j * k < n; k++)
			{
				isprime[j * k] = 1;
			}
		}
		int big, small;
		if (n % 2 == 0)
			big = small = n / 2;
		else
		{
			big = n / 2 + 1;
			small = n / 2;
		}
		while (1)
		{
			if (isprime[big] == 0 && isprime[small] == 0)
				break;
			big += 1;
			small -= 1;
		}
		cout << small << " " << big << "\n";
	}

	return 0;
}
