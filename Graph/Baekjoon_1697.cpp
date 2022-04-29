#include <iostream>
#include <queue>
#define ll long long
using namespace std;

queue <int> que;
int check[200001];

void bfs(int n, int k);

int main()
{
	int N, K;
	cin >> N >> K;
	bfs(N, K);
	cout << check[K];
	return 0;
}

void bfs(int n, int k)
{
	que.push(n);
	while (1) {
		int x = que.front();
		que.pop();
		if (x == k)
			break;
		if (check[x - 1] == 0 && x - 1 <= 100000) {
			que.push(x - 1);
			check[x - 1] = check[x] + 1;
		}
		if (check[x + 1] == 0 && x + 1 <= 100000) {
			que.push(x + 1);
			check[x + 1] = check[x] + 1;
		}
		if (x*2 <= 100000 && check[x * 2] == 0 ) {
			que.push(2 * x);
			check[2 * x] = check[x] + 1;
		}
	}
}