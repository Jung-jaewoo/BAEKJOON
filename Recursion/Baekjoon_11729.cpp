#include <iostream>
using namespace std;

void hanoi(int a, int b, int c, int n);

int main()
{	
	int N;
	cin >> N;
	printf("%d\n", (1<<N)-1);
	hanoi(1, 3, 2, N);

	return 0;
}

void hanoi(int a, int b, int c, int n)
{
	if (n == 1)
	{
		printf("%d %d\n", a, b);
	}
	else
	{
		hanoi(a, c, b, n - 1);
		printf("%d %d\n", a, b);
		hanoi(c, b, a, n - 1);
	}
}