#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
#define ll long long
using namespace std;

typedef struct{
    int u;
    int v;
    int cost;
}edge;
vector <edge> edges;
vector <ll> dist;
int N,M;

void input();
int bellman_ford(int start);

int main()
{
    input();
    if(bellman_ford(1)) cout << -1;
    else{
        for(int i=2; i<=N; i++){
            if(dist[i]!=INF)
                cout << dist[i] << "\n";
            else
                cout << -1 << "\n";
        }
    }   
}

void input()
{
    edge tmp;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> tmp.u >> tmp.v >> tmp.cost;
        edges.push_back(tmp);
    }
    dist.resize(N+1);
    fill(dist.begin(),dist.end(),INF);
}

int bellman_ford(int start) 
{
    dist[start] = 0;
    int cur_node, next_node, edge_cost;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cur_node = edges[j].u;
            next_node = edges[j].v;
            edge_cost = edges[j].cost;
            if(dist[cur_node]!=INF && dist[next_node] > dist[cur_node] + edge_cost){
                dist[next_node] = dist[cur_node] + (ll)edge_cost;
                if(i==N-1) return 1;
            }
        }
    }
    return 0;
}