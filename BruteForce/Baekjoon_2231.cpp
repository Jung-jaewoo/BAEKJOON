#include <iostream>
using namespace std;

int main()
{	
	int N;
	cin >> N;
	
	int i, num;
	int desum;
	for (i = 1; i < N; i++)
	{
		num = i;
		desum = num;
		while (num != 0)
		{
			desum += num % 10;
			num /= 10;
		}
		if (desum == N)
			break;
	}
	if (i == N)
		printf("0");
	else
		printf("%d\n", i);

	return 0;
}
