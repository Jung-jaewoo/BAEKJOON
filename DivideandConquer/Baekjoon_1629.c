#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b))
ll sqrmod(int a, int b, int c);

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%lld", sqrmod(a, b, c));
	return 0;
}

ll sqrmod(int a, int b, int c)
{
	ll tmp;
	if (b > 1) {
		if (b % 2 == 0) {
			tmp = sqrmod(a, b / 2, c);
			return (tmp * tmp) % c;
		}
		else {
			tmp = sqrmod(a, b / 2, c);
			return (tmp* ((tmp*(a%c))%c)) % c;
		}
	}
	else {
		return a % c;
	}
}