#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long

int main()
{
	int N, tmpn;
	int alphabet[26] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char tmp[9];
		scanf("%s", tmp);
		int tmplen = strlen(tmp);
		for (int j = 0; j < tmplen; j++) {
			tmpn = 1;
			for (int k = 0; k < tmplen - 1 - j; k++) {
				tmpn *= 10;
			}
			alphabet[tmp[j] - 'A'] += tmpn;
		}
	}
	int sum = 0;
	int num = 9;
	int max;
	int maxindex;
	while (1) {
		max = 0;
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] > max) {
				max = alphabet[i];
				maxindex = i;
			}
		}
		if (max > 0) {
			sum += alphabet[maxindex] * num--;
			alphabet[maxindex] = 0;
		}
		else
			break;
	}
	printf("%d", sum);
	return 0;
}
