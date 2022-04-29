#include <iostream>
#include <queue>
using namespace std;
int graph[101][101];
int visited_dfs[101];
int visited_bfs[101];
int sum;
queue <int> que;
void dfs(int u, int N);
void bfs(int u, int N);
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(1, N); //¶Ç´Â bfs(1,N);
	cout << sum - 1;
	return 0;
}

void dfs(int u, int N)
{
	sum++;
	visited_dfs[u] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[u][i] == 1 && visited_dfs[i] == 0)
			dfs(i, N);
	}
}

void bfs(int u, int N)
{
	int tmp;
	sum++;
	visited_bfs[u] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[u][i] == 1 && visited_bfs[i] == 0) {
			visited_bfs[i] = 1;
			que.push(i);
		}
	}
	if (que.size() != 0) {
		tmp = que.front();
		que.pop();
		bfs(tmp, N);
	}
}