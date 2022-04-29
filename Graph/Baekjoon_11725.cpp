#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N;
vector <int> parent;
vector <vector<int>> graph;
void bfs(void);

int main()
{
	fastio;
	cin >> N;
	parent.resize(N + 1);
	graph.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs();
	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";
	return 0;
}

void bfs(void)
{
	queue <int> que;
	que.push(1);
	vector <bool> visit(N + 1, false);
	visit[1] = true;
	while (que.size() != 0) {
		int i = que.front();
		que.pop();
		int graphsize = graph[i].size();
		for (int j = 0; j < graphsize; j++) {
			if (!visit[graph[i][j]]) {
				que.push(graph[i][j]);
				visit[graph[i][j]] = 1;
				parent[graph[i][j]] = i;
			}
		}
	}
}