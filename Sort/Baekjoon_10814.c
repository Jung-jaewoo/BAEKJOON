#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ageandname {
	int age;
	char name[101];
	int input;
};

int compare(const void* one, const void* two) {
	struct ageandname* x;
	struct ageandname* y;
	x = (struct ageandname*)one;
	y = (struct ageandname*)two;
	if (x->age > y->age)
		return 1;
	else if (x->age < y->age)
		return -1;
	else
	{
		if (x->input > y->input)
			return 1;
		else if (x->input < y->input)
			return -1;
		else
			return 0;
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	int i;
	struct ageandname* arr;
	arr = (struct ageandname*)malloc(sizeof(struct ageandname) * N);
	for (i = 0; i < N; i++)
	{
		scanf("%d %s", &arr[i].age, &arr[i].name);
		arr[i].input = i;
	}
	qsort(arr, N, sizeof(struct ageandname), compare);
	for (i = 0; i < N; i++)
	{
		printf("%d %s\n", arr[i].age, arr[i].name);
	}
	return 0;
}
