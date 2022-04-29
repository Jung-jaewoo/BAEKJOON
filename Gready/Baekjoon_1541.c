#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (((a)>(b)?(a):(b)))

int main()
{
	char string[51];
	scanf("%s", &string);
	int num = 0;
	int sum = 0;
	int sum2 = 0;
	int flag = 0;
	for (int i = 0; i < strlen(string); i++) {
		if ('0' <= string[i] && string[i] <= '9') {
			num = num * 10 + (string[i]-'0');
		}
		else{
			if (flag == 0 ) {
				sum += num;
				num = 0;
			}
			else{
				sum2 += num;
				num = 0;
			}
			if (string[i] == '-')
				flag = 1;
		}
	}
	if (flag)
		sum2 += num;
	else
		sum += num;
	printf("%d", sum - sum2);
	return 0;
}