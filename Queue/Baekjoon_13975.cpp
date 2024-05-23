#include <iostream>
#include <algorithm>
#include <queue>
#define MAXK 1000001
#define ll long long
using namespace std;

priority_queue <ll, vector<ll>, greater<ll>> que;

void solution(int K);
void arrK_out(int S, int K);

int main()
{
    int T, K, tmp;
    cin >> T;
    while(T--){
        cin >> K;
        for(int i=0; i<K; i++){
            cin >> tmp;
            que.push(tmp);
        }
        solution(K);
        while(que.size()!=0)
            que.pop();
    }

    return 0;
}

void solution(int K){
    ll sum = 0;
    
    while(que.size()!=1){
        ll min1 = que.top();
        que.pop();
        ll min2 = que.top();
        que.pop();
        sum += min1 + min2;
        que.push(min1 + min2);
    }
    cout << sum << "\n";
}

