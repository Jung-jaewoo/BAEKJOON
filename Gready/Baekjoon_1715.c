#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long

int size = 0;
void push(int* arr, int n);
int pop(int* arr);
int main()
{
	int N;
	int sum = 0;
	scanf("%d", &N);
	int tmp;
	int* arr;
	arr = (int*)malloc(sizeof(int) * (N+1));
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		push(arr, tmp);
	}
	for (int i = 0; i < N - 1; i++) {
		tmp = 0;
		tmp += pop(arr) + pop(arr);
		sum += tmp;
		push(arr, tmp);
	}
	printf("%d", sum);
	return 0;
}

void push(int *arr, int n) {
	int index = 1 + size;
	size++;
	while (1) {
		if (n >= arr[index / 2]) {
			arr[index] = n;
			break;
		}
		arr[index] = arr[index / 2];
		if (index / 2 <= 1) {
			arr[index / 2] = n;
			break;
		}
		index /= 2;
	}
}

int pop(int* arr) {
	int tmp = arr[1];
	int n = arr[size];
	size--;
	int index = 1;
	int minindex;
	while (1) {
		if (index * 2 > size)
			break;
		else if (index * 2 == size) {
			if (arr[index * 2] < n) {
				arr[index] = arr[index * 2];
				index = index * 2;
			}
			else
				break;
		}
		else {
			minindex = arr[index * 2] < arr[index * 2 + 1] ? index * 2 : index * 2 + 1;
			if (minindex == index * 2) {
				if (arr[index * 2] < n) {
					arr[index] = arr[index * 2];
					index = index * 2;
				}
				else
					break;
			}
			else {
				if (arr[index * 2 + 1] < n) {
					arr[index] = arr[index * 2 + 1];
					index = index * 2 + 1;
				}
				else
					break;
			}
		}
	}
	arr[index] = n;
	return tmp;
}
