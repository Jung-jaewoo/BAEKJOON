#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int checktime(int** arr, int height, int N, int M, int B);
int main()
{
	int N, M, B, i, j, mintime_height, mintime;
	cin >> N >> M >> B;
	int** height;
	height = new int*[N];
	for (i = 0; i < N; i++)
		height[i] = new int[M];
	double sum = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> height[i][j];
		}
	}
	mintime_height = 0;
	mintime = checktime(height, 0, N, M, B);
	for (i = 0; i <= 256; i++) {
		int tmp = checktime(height, i, N, M, B);
		if (tmp!=-1 && mintime >= tmp) {
			mintime = tmp;
			mintime_height = i;
		}
	}
	cout << mintime << " " << mintime_height;
	return 0;
}

int checktime(int** arr, int height, int N, int M, int B)
{
	int remove = 0;
	int add = 0;
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (arr[i][j] > height)
				remove += arr[i][j] - height;
			else if (arr[i][j] < height)
				add += height - arr[i][j];
		}
	}
	if (add > remove + B) return -1;
	return remove * 2 + add * 1;
}

