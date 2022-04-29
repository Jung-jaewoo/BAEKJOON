#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int T;
	scanf("%d", &T);
	while (T!=0) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n",lcm(x, y));
		T--;
	}
	return 0;
}

int gcd(int x, int y)
{
	int tmp;
	if (x < y) {
		tmp = x;
		x = y;
		y = tmp;
	}
	while (y != 0) {
		tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}

int lcm(int x, int y)
{
	int tmp;
	tmp = (x * y) / gcd(x, y);
	return tmp;
}


