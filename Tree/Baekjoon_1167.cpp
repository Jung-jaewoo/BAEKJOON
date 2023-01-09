#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int u;
    int cost;
}edge;

void input(vector <vector<edge>>& tree, int& N){
    int v;
    for(int i=0; i<N; i++){
        cin >> v;
        while(1){
            edge e;
            cin >> e.u;
            if(e.u==-1)
                break;
            cin >> e.cost;
            tree[v].push_back(e);
        }
    }
}

void dfs(int v, vector<vector<edge>>& tree, vector<int>& visited, int cost, int& max, int& node){
    visited[v] = 1; 
    if(max<cost){
        max = cost;
        node = v;
    }
    int size = tree[v].size();
    for(int i=0; i<size; i++){
        if(visited[tree[v][i].u]==0)
            dfs(tree[v][i].u, tree, visited, cost + tree[v][i].cost, max, node);
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

