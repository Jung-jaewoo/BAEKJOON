#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define max(a,b) (((a)>(b)?(a):(b)))
struct category {
	int num;
	char name[21];
};
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);
		struct category* arr;
		arr = (struct category*)malloc(sizeof(struct category) * n);
		for (int j = 0; j < n; j++)
			arr[j].num = 0;
		for (int j = 0; j < n; j++) {
			char tmp[21];
			char cate[21];
			scanf("%s %s", &tmp, &cate);
			for (int k = 0; k < n; k++) {
				if (arr[k].num != 0) {
					if (strcmp(arr[k].name, cate) == 0) {
						arr[k].num++;
						break;
					}
				}
				else {
					strcpy(arr[k].name, cate);
					arr[k].num = 1;
					break;
				}
			}
		}
		int sum = 1;
		for (int j = 0; j < n; j++)
		{
			if (arr[j].num == 0)
				break;
			sum *= arr[j].num + 1;
		}
		sum -= 1;
		printf("%d\n", sum);
	}
	return 0;
}