#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
#define ll long long
using namespace std;

typedef struct{
    int u, v, cost;
}Edge;

void input(int& N, int& M, int& W, vector<Edge>& edges);
int bellman_ford(int& N, int& M, int& W, vector<Edge>& edges);

int main()
{
    fastio;
    int T;
    cin >> T;

    while(T--){
        int N, M, W;
        vector<Edge> edges;
        input(N,M,W,edges);

        if(bellman_ford(N,M,W,edges))
            cout << "YES\n";
        else
            cout << "NO\n";
        
        edges.clear();
    }

    return 0;
}   

void input(int& N, int& M, int& W, vector<Edge>& edges)
{
    Edge tmp;

    cin >> N >> M >> W;
    for(int i=0; i<M; i++){
        cin >> tmp.u >> tmp.v >> tmp.cost;
        edges.push_back(tmp);
    }
    for(int i=0; i<W; i++){
        cin >> tmp.u >> tmp.v >> tmp.cost;
        edges.push_back(tmp);
    }
}

int bellman_ford(int& N, int& M, int& W, vector<Edge>& edges)
{
    vector<int> distances;
    distances.resize(N+1, INF);
    distances[1] = 0;

    int cur, next, cost;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cur = edges[j].u;
            next = edges[j].v;
            cost = edges[j].cost;
            if(distances[next] > distances[cur] + cost){
                distances[next] = distances[cur] + cost;
                if(i==N-1)
                    return 1;
            }
            swap(cur,next);
            if(distances[next] > distances[cur] + cost){
                distances[next] = distances[cur] + cost;
                if(i==N-1)
                    return 1;
            }
        }
        for(int j=M; j<M+W; j++){
            cur = edges[j].u;
            next = edges[j].v;
            cost = -edges[j].cost;
            if(distances[next] > distances[cur] + cost){
                distances[next] = distances[cur] + cost;
                if(i==N-1)
                    return 1;
            }
        }
    }
    
    distances.clear();
    return 0;
}