#include <iostream>
#include <vector>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void input(int m, vector<vector<int>>& graph);
void output(int sol, int cnt);
void solution(int n, bool& flag, int& sol, vector<vector<int>>& graph, bool (&visited)[501]);
void dfs(int pre, int u, vector<vector<int>>& graph, bool (&visited)[501], bool& flag);

int main()
{
    int n, m, u, v, sol, cnt = 0;
    bool flag;

    vector<vector<int>> graph;
    bool visited[501] = {0, };

    while(1){
        cnt++;
        sol = 0;

        cin >> n >> m;
        if(n==0 && m==0)
            break;
    
        graph.resize(n+1);

        input(m,graph);

        solution(n,flag,sol,graph,visited);
        
        output(sol, cnt);

        for(int i=0; i<=n; i++)
            graph[i].clear();
        graph.clear();
        memset(visited, 0, sizeof(visited));
    }
}

void dfs(int pre, int u, vector<vector<int>>& graph, bool (&visited)[501], bool& flag)
{
    visited[u] = 1;

    int edgeSize = graph[u].size();
    for(int i=0; i<edgeSize; i++){
        int v = graph[u][i];
        if(visited[v]==1 && pre!=v){ 
            flag = false;
            return;
        }
        else if(visited[v]==0)
            dfs(u, graph[u][i], graph, visited, flag);
    }
}

void input(int m, vector<vector<int>>& graph)
{
    int u,v;
    for(int i=0; i<m; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
    }
}

void output(int sol, int cnt)
{
    if(sol==1){
            cout << "Case " << cnt << ": There is one tree.\n"; 
        }
        else if(sol>1){
            cout << "Case " << cnt << ": A forest of " << sol << " trees.\n"; 
        }
        else{
            cout << "Case " << cnt << ": No trees.\n";
    }
}

void solution(int n, bool& flag, int& sol, vector<vector<int>>& graph, bool (&visited)[501])
{
    for(int i=1; i<=n; i++){
        flag = true;
        if(visited[i]==0){
            dfs(0,i,graph,visited,flag);
            if(flag)
                sol++;
        }
    }
}