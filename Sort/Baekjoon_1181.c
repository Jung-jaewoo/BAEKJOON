#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct wordandsize {
	char word[51];
	int size;
};

int compare(const void* one, const void* two) {
	struct wordandsize* x;
	struct wordandsize* y;
	x = (struct wordandsize*)one;
	y = (struct wordandsize*)two;
	if (x->size > y->size)
		return 1;
	else if (x->size < y->size)
		return -1;
	else
		return strcmp(x->word, y->word);
}

int main()
{
	int N;
	scanf("%d",&N);
	int i, j;
	struct wordandsize* arr;
	arr = (struct wordandsize*)malloc(sizeof(struct wordandsize) * N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", &arr[i].word);
		arr[i].size = strlen(arr[i].word);
	}
	qsort(arr, N, sizeof(struct wordandsize), compare);

	printf("%s\n", &arr[0].word);
	for (i = 1; i < N; i++)
	{
		if (strcmp(arr[i].word ,arr[i - 1].word)==0)
			continue;
		printf("%s\n", &arr[i].word);
	}
	return 0;
}
