#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector <vector<int>> graph;
vector <int> visited;
int N, M;
queue <int> que;

void input();
void bfs(int n);
void sol();

int main()
{   
    fastio;
    input();
    sol();
    return 0;
}

void input()
{
    cin >> N >> M;
    graph.resize(100);
    visited.resize(101);
    int x, y;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i=0; i<M; i++){
        cin >> x >> y;
        graph[x].push_back(y);
    }
}

void bfs(int n)
{
    int u;
    visited[n] = 1; //처음 1의 최소1번이라 가정하고 결과값에서 -1 해주어야함.
    que.push(n);
    while(que.size()!=0){
        u = que.front();
        if(u == 100)  break;
        que.pop();
        if(graph[u].size()){
            if(visited[graph[u][0]]==0 || visited[graph[u][0]]>visited[u]){
                visited[graph[u][0]] = visited[u];  //x번 칸에 도착하면, y번 칸으로 이동. 이동횟수 증가x.
                que.push(graph[u][0]);
            }         
        }
        else{
            for(int i=1; i<=6; i++){
                if(u+i<=100 && (visited[u+i]==0 || visited[u+i]>visited[u])){
                    visited[u+i] = visited[u] + 1;
                    que.push(u+i);
                }
            }
        }
    }
}

void sol()
{
    bfs(1);
    printf("%d\n", visited[100] - 1);   //처음 시작값을 1로 가정했으니 결과값에 -1.
}