#include <iostream>
using namespace std;
int graph[52][52];
int visited[52][52];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void graph_initiate(int M, int N);
void dfs(int x, int y);
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int M, N, K, sol = 0;
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			graph[x+1][y+1] = 1;
		}
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] == 1 && visited[i][j] == 0) {
					dfs(i, j);
					sol++;
				}
			}
		}
		cout << sol << "\n";
		graph_initiate(M, N);
	}
	return 0;
}

void graph_initiate(int M, int N)
{
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void dfs(int x, int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		if (graph[x + dx[i]][y + dy[i]] == 1 && visited[x + dx[i]][y + dy[i]] == 0)
			dfs(x + dx[i], y + dy[i]);
	}
}
