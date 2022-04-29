#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
	fastio;
	int N, M;
	cin >> N >> M;
	int** arr;
	arr = new int* [N+1];
	for (int i = 1; i < N+1; i++)
		arr[i] = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		int sum = 0, tmp;
		arr[i][0] = 0;
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			sum += tmp;
			arr[i][j] = sum;
		}
	}
	while (M--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int sum = 0;
		for (int i = x1; i <= x2; i++)
			sum += arr[i][y2] - arr[i][y1 - 1];
		cout << sum<<"\n"; 
	}
	return 0;
}