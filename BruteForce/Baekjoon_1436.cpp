#include <iostream>
using namespace std;

int main()
{	
	int N;
	cin >> N;
	int sixsixsix_num = 0;
	int i = 666;
	int num;
	while (sixsixsix_num < N)
	{
		num = i;
		while (num != 0)
		{
			if (num % 1000 == 666)
			{
				sixsixsix_num += 1;
				break;
			}
			num /= 10;
		}
		i++;
	}
	cout << i - 1;
	return 0;
}
