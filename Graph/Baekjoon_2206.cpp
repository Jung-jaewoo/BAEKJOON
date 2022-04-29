#include <iostream>
#include <queue>
#define ll long long
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef struct {
	int x, y;
	bool broken;
}decart;

queue <decart> que;
int graph[1001][1001];
int check[1001][1001];
int check2[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void bfs(int N, int M);

int main()
{
	fastio;
	int N, M;
	cin >> N >> M;
	string tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 1; j <= M; j++)
			graph[i][j] = tmp[j - 1]-'0';
	}
	decart start;
	start.x = 1;
	start.y = 1;
	start.broken = false;
	check[1][1] = 1;
	que.push(start);
	bfs(N,M);
	if (check[N][M] != 0)
		cout << check[N][M];
	else if (check2[N][M] != 0)
		cout << check2[N][M];
	else
		cout << -1;
	return 0;
}

void bfs(int N, int M)
{
	decart tmp, tmp2;
	while (que.size()!=0) {
		tmp = que.front();
		if (tmp.x == N && tmp.y == M)
			break;
		que.pop();
		if (!tmp.broken) {
			for (int i = 0; i < 4; i++) {
				if (check[tmp.x + dx[i]][tmp.y + dy[i]] == 0 && 1 <= tmp.x+dx[i] && tmp.x + dx[i] <=N && 1<=tmp.y+dy[i] && tmp.y+dy[i] <=M) {
					if (graph[tmp.x + dx[i]][tmp.y + dy[i]] == 1) {
						tmp2.x = tmp.x + dx[i];
						tmp2.y = tmp.y + dy[i];
						tmp2.broken = true;
						check2[tmp2.x][tmp2.y] = check[tmp.x][tmp.y] + 1;
						que.push(tmp2);
					}
					else {
						tmp2.x = tmp.x + dx[i];
						tmp2.y = tmp.y + dy[i];
						tmp2.broken = false;
						check[tmp2.x][tmp2.y] = check[tmp.x][tmp.y] + 1;
						que.push(tmp2);
					}
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (check2[tmp.x + dx[i]][tmp.y + dy[i]] == 0 && graph[tmp.x + dx[i]][tmp.y + dy[i]] == 0 && 1 <= tmp.x + dx[i] && tmp.x + dx[i] <= N && 1 <= tmp.y + dy[i] && tmp.y + dy[i] <= M) {
					tmp2.x = tmp.x + dx[i];
					tmp2.y = tmp.y + dy[i];
					tmp2.broken = true;
					check2[tmp2.x][tmp2.y] = check2[tmp.x][tmp.y] + 1;
					que.push(tmp2);
				}
			}
		}
	}
}