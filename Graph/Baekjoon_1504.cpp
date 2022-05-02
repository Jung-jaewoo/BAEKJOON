#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000000
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

typedef struct {
	int v, cost;
}decart;
vector < vector<decart> > graph;
priority_queue < pair<int, int> > que;

int dijkstra(int start, int V, int N);

int main()
{
	fastio;
	int V, E, v1, v2;
	cin >> V >> E;
	graph.resize(V + 1);
	for (int i = 0; i < E; i++) {
		decart tmp;
		int u, swaptmp;
		cin >> u >> tmp.v >> tmp.cost;
		graph[u].push_back(tmp);
        swaptmp = tmp.v;
        tmp.v = u;
        u = swaptmp;
        graph[u].push_back(tmp);
	}
    cin >> v1 >> v2;
    int cnt = graph[v1].size();
    int fv1tv2 = dijkstra(v1, v2, V);
    int f1tv2 = dijkstra(1, v2, V);
    int f1tv1 = dijkstra(1, v1, V);
    int fv2tV = dijkstra(v2, V, V);
    int fv1tV = dijkstra(v1, V, V);
    int sol1, sol2;
    if(f1tv1 + fv2tV < f1tv2 + fv1tV){
        sol1 = f1tv1;
        sol2 = fv2tV;
    }
    else{
        sol1 = f1tv2;
        sol2 = fv1tV;
    }
    if(sol1 == INF || fv1tv2 == INF || sol2 == INF)
        cout << -1;
    else
	    cout << sol1 + fv1tv2 + sol2;
	return 0;
}

int dijkstra(int start, int V, int N)
{
	int* check;
	check = new int[N+1];
	for (int i = 1; i <= N; i++) check[i] = INF;
	que.push(make_pair(0, start));
	check[start] = 0;
	while (que.size() != 0) {
		int indexcost = -que.top().first;
		int index = que.top().second;
		que.pop();
		int edgesize = graph[index].size();
		for (int i = 0; i < edgesize; i++) {
			if (indexcost + graph[index][i].cost < check[graph[index][i].v]) {
				check[graph[index][i].v] = indexcost + graph[index][i].cost;
				que.push(make_pair(-check[graph[index][i].v], graph[index][i].v));
			}
		}
	}
    return check[V];
}