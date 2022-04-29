#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int fivenum[3] = { 0,0,0 };
	int twonum[3] = { 0,0,0 };
	fivenum[0] = countfive(n);
	fivenum[1] = countfive(n-m);
	fivenum[2] = countfive(m);
	twonum[0] = counttwo(n);
	twonum[1] = counttwo(n-m);
	twonum[2] = counttwo(m);
	int five, two;
	five = fivenum[0] - fivenum[1] - fivenum[2];
	two = twonum[0] - twonum[1] - twonum[2];
	printf("%d", two < five ? two : five);
	return 0;
}

int counttwo(int n)
{
	int cnt = 0;
	int tmp = n;
	while (tmp >= 2) {
		cnt += tmp / 2;
		tmp /= 2;
	}
	return cnt;
}

int countfive(int n)
{
	int cnt = 0;
	int tmp = n;
	while (tmp >= 5) {
		cnt += tmp / 5;
		tmp /= 5;
	}
	return cnt;
}