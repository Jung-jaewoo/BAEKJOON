#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int v;
    int cost;
}edge;

void input(vector <vector<edge>>& tree, int& N){
    int u;
    for(int i=0; i<N-1; i++){
        edge e;
        edge e2;
        cin >> u >> e.v >> e.cost;
        tree[u].push_back(e);

        e2.v = u;
        e2.cost = e.cost;
        tree[e.v].push_back(e2);
    }
}

void dfs(int u, vector<vector<edge>>& tree, vector<int>& visited, int cost, int& max, int& node){
    visited[u] = 1; 

    if(max<cost){
        max = cost;
        node = u;
    }

    int size = tree[u].size();
    for(int i=0; i<size; i++){
        if(visited[tree[u][i].v]==0)
            dfs(tree[u][i].v, tree, visited, cost + tree[u][i].cost, max, node);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<vector<edge>> tree;
    vector<int> visited;
    tree.resize(N+1);
    visited.resize(N+1);

    input(tree, N);

    int max = 0, node;
    dfs(1,tree,visited,0,max,node);
    fill(visited.begin(),visited.end(),0);
    max = 0;
    dfs(node,tree,visited,0,max,node);

    cout << max;

    return 0;
}

