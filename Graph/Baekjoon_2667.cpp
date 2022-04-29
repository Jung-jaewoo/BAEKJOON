#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int graph[27][27];
int visited[27][27];
int sum[314];
void dfs(int x, int y, int N, int n);

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++)
			graph[i + 1][j + 1] = tmp[j] - '0';
	}
	int n = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 1 && visited[i][j] == 0) {
				n++;
				dfs(i, j, N, n);
			}
		}
	}
	sort(sum, sum + n);
	cout << n << "\n";
	for (int i = 0; i < n; i++)
		cout << sum[i] << "\n";
	return 0;
}

void dfs(int x, int y, int N, int n)
{
	visited[x][y] = n;
	sum[n - 1]++;
	if (graph[x - 1][y] == 1 && visited[x - 1][y] == 0)
		dfs(x - 1, y, N, n);
	if (graph[x + 1][y] == 1 && visited[x + 1][y] == 0)
		dfs(x + 1, y, N, n);
	if (graph[x][y - 1] == 1 && visited[x][y - 1] == 0)
		dfs(x, y - 1, N, n);
	if (graph[x][y + 1] == 1 && visited[x][y + 1] == 0)
		dfs(x, y + 1, N, n);
}