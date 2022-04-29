#include <iostream>
#include <queue>
using namespace std;
int graph[1001][1001];
int visited_dfs[1001];
int visited_bfs[1001];
queue <int> que;
void dfs(int u, int N);
void bfs(int u, int N);
int main()
{
	int N, M, V;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(V, N);
	cout << "\n";
	bfs(V, N);
	return 0;
}

void dfs(int u, int N)
{
	cout << u << " ";
	visited_dfs[u] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[u][i] == 1 && visited_dfs[i] == 0)
			dfs(i, N);
	}
}

void bfs(int u, int N)
{
	int tmp;
	cout << u << " ";
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