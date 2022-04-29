#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define min(a,b) ((a<b)?(a):(b))
int sol;
int max, min, mid;
void binaryserch(int* arr, int N, int M);
int compare(const void* n1, const void* n2)
{
    int x = *(int*)n1;
    int y = *(int*)n2;
    if (x > y)
        return 1;
    else if (x < y)
        return -1;
    else
        return 0;
}
int main()
{
    int N, C;
    scanf("%d %d", &N, &C);
    int* arr;
    arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", arr + i);
    }
    qsort(arr, N, sizeof(int), compare);
    max = arr[N - 1];
    binaryserch(arr, N, C);
    printf("%d", sol);
    return 0;
}

void binaryserch(int* arr, int N, int C) {
    while (min <= max) {
        int sum = 0;
        mid = (max + min) / 2;
        int pre = arr[0];
        sum++;
        for (int i = 1; i < N; i++) {
            if (arr[i] >= pre + mid) {
                pre = arr[i];
                sum++;
            }
        }
        if (sum < C)
            max = mid - 1;
        else {
            if (sol < mid) 
                sol = mid;
            min = mid + 1;
        }
    }
}