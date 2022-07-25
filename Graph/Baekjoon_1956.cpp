#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e10
#define ll long long
using namespace std;

vector <vector<ll>> table;
ll minvalue = INF;
int n, m;

void input();
void FloydWarshall();

int main()
{
    fastio;
    input();
    FloydWarshall();
    if(minvalue == INF)
        cout << -1;
    else
        cout << minvalue;
    return 0;
}

void input()
{
    cin >> n >> m;
    table.resize(n+1);
    for(int i=1; i<n+1; i++){
        table[i].resize(n+1);
        fill(table[i].begin(),table[i].end(),INF);
    }
    for(int i=1, j=1; i<=n; i++,j++) table[i][j]=0;
    int a,b,c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        if(table[a][b]==0 || table[a][b]>c)   table[a][b] = c;
    }
}

void FloydWarshall()
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                table[i][j] = min(table[i][j], table[i][k]+table[k][j]);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                if(table[i][j]==0 || table[i][j]==0) continue;
                else{
                    minvalue = min(minvalue, table[i][j]);
                }
            } 
            else{
                minvalue = min(minvalue, table[i][j]+table[j][i]);
            }
        }
    }
}