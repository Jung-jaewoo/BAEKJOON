#include <iostream>
#include <queue>
#define ll long long
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef struct {
	int x, y;
}decart;

queue <decart> que;
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
void bfs(decart s, decart d, int I, int** check);

int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--) {
		int I;
		cin >> I;
		int** check;
		check = new int* [I];
		for (int i = 0; i < I; i++) {
			check[i] = new int[I];
			for (int j = 0; j < I; j++)
				check[i][j] = 0;
		}
		decart start, destination;
		cin >> start.x >> start.y;
		cin >> destination.x >> destination.y;
		bfs(start, destination, I, check);
		cout << check[destination.x][destination.y] << "\n";
		for (int i = 0; i < I; i++) delete[] check[i];
		delete[] check;
	}
	return 0;
}

void bfs(decart s, decart d, int I, int** check)
{
	que.push(s);
	while (que.size() != 0) {
		decart tmp = que.front();
		que.pop();
		if (tmp.x == d.x && tmp.y == d.y)
			break;
		for (int i = 0; i < 8; i++) {
			if (0 <= tmp.x + dx[i] && tmp.x + dx[i] < I && 0 <= tmp.y + dy[i] && tmp.y + dy[i] < I && check[tmp.x + dx[i]][tmp.y + dy[i]] == 0) {
				decart tmp2;
				tmp2.x = tmp.x + dx[i];
				tmp2.y = tmp.y + dy[i];
				check[tmp2.x][tmp2.y] = check[tmp.x][tmp.y] + 1;
				que.push(tmp2);
			}
		}
	}
	while (que.size() != 0)
		que.pop();
}