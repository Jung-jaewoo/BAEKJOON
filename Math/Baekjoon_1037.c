#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int n;
	scanf("%d", &n);
	int tmp;
	int max,min;
	scanf("%d", &tmp);
	max = tmp;
	min = tmp;
	for (int i = 1; i < n; i++) {
		scanf("%d", &tmp);
		if (max < tmp)
			max = tmp;
		if (min > tmp)
			min = tmp;
	}
	printf("%d", max * min);
	return 0;
}




