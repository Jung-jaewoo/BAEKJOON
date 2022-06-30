#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
using namespace std;

typedef struct{
    int v, cost;
}decart;

vector <vector<decart>> graph;
vector <int> x;
int T, n, m, t, s, g, h, a, b, d;

void input();
void dijkstra(int s, int* check);
void sol();

int main()
{   
    fastio;
    cin >> T;
    while(T--){
        input();
        sol();
        for(int i=0; i<n+1; i++)
            graph.erase(graph.begin());
    }
    return 0;
}

void input()
{
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    graph.resize(n+1);
    x.resize(t);
    decart tmp;
    for(int i=0; i<m; i++){
        cin >> a >> b >> d;
        tmp.v = b;
        tmp.cost = d;
        graph[a].push_back(tmp);
        tmp.v = a;
        graph[b].push_back(tmp);
    }
    for(int i=0; i<t; i++){
        cin >> x[i];
    }
}

void dijkstra(int s, int* check)
{
    priority_queue <pair<int,int>> que; // cost, 위치
    int curcost, curindex, nodesize;
    check[s] = 0;
    que.push(make_pair(0,s));
    while(que.size()!=0){
        curcost = -que.top().first;
        curindex = que.top().second;
        que.pop();
        nodesize = graph[curindex].size();
        for(int i=0; i<nodesize; i++){
            if(curcost + graph[curindex][i].cost < check[graph[curindex][i].v]){
                check[graph[curindex][i].v] = curcost + graph[curindex][i].cost;
                que.push(make_pair(-check[graph[curindex][i].v], graph[curindex][i].v));
            }
        }
    }
}

void sol()
{
    vector <int> solution;
    int *check;
    check = new int[n+1];
    for(int i=1; i<=n; i++) check[i]=INF;
    dijkstra(s, check);
    int s1_1 = check[g];
    int s1_2 = check[h];
    int s2;
    int graphgsize = graph[g].size();
    for(int i=0; i<graphgsize; i++){
        if(graph[g][i].v == h){
            s2 = graph[g][i].cost;
            break;
        }
    }
    for(int i=0; i<t; i++){
        for(int i=1; i<=n; i++) check[i]=INF;
        dijkstra(x[i], check);
        int stoe = check[s];
        int s3_1 = check[h];
        int s3_2 = check[g];
        int minvalue = min(s1_1+s2+s3_1, s1_2+s2+s3_2);
        if(minvalue == stoe)
            solution.push_back(x[i]);
    }
    sort(solution.begin(), solution.end());
    int solutionsize = solution.size();
    for(int i=0; i<solutionsize; i++)
        printf("%d ",solution[i]);
    printf("\n");
}