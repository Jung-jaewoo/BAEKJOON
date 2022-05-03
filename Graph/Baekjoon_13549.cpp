#include <iostream>
#include <queue>
#define INF 1000000000
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int check[100001];
priority_queue <pair<int, int>> que;

void dijkstra(int N, int K);

int main()
{
    fastio;
    int N, K;
    cin >> N >> K;
    dijkstra(N, K);
    cout << check[K];
    return 0;
}

void dijkstra(int N, int K)
{
    fill(check, check + 100001, INF);
    que.push(make_pair(0, N));
    check[N] = 0;
    while (que.size() != 0) {
        int indextime = -que.top().first;
        int index = que.top().second;
        que.pop();
        if (index == K) break;
        if (index * 2 <= 100000 && check[index * 2] > indextime) {
            check[index * 2] = indextime;
            que.push(make_pair(-indextime, index * 2));
        }
        if (index < K && check[index + 1]>indextime + 1) {
            check[index + 1] = indextime + 1;
            que.push(make_pair(-(indextime + 1), index + 1));
        }
        if (index - 1 >= 0 && check[index - 1] > indextime + 1){
            check[index - 1] = indextime + 1;
            que.push(make_pair(-(indextime + 1), index - 1));
        }
    }
}