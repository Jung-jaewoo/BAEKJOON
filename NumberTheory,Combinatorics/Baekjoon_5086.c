#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		int i;
		if (a < b) {
			i = 2;
			while (1) {
				if (a * i > b) {
					printf("neither\n");
					break;
				}
				else if (a * i == b) {
					printf("factor\n");
					break;
				}
				i++;
			}
		}
		else {
			i = 2;
			while (1) {
				if (b * i > a) {
					printf("neither\n");
					break;
				}
				else if (b * i == a) {
					printf("multiple\n");
					break;
				}
				i++;
			}
		}

	}
	return 0;
}




