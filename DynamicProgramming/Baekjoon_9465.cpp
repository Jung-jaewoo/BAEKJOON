#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void solution(int n, vector<int>& arr);

int main()
{
    fastio;

    int T;
    cin >> T;

    vector<int> arr;
    while(T--){
        int n;
        cin >> n;

        arr.resize(2*n);
        for(int i=0; i<2*n; i++)
            cin >> arr[i];

        solution(n,arr);
    }
    
    return 0;
}

void solution(int n, vector<int>& arr)
{
    vector<int> dp;
    dp.resize(2*n);
    
    dp[0] = arr[0];
    dp[n] = arr[n];
    if(n>1){
        dp[1] = dp[n] + arr[1];
        dp[n+1] = dp[0] + arr[n+1];
    }
    if(n>2){
        for(int i=2; i<n; i++){
            dp[i] = max(dp[n+i-2],dp[n+i-1]) + arr[i];
            dp[n+i] = max(dp[i-2],dp[i-1]) + arr[n+i];
        }
    }

    int max = 0;
    for(int i=0; i<2; i++){
        if(max<dp[n-1-i])
            max = dp[n-1-i];
        if(max<dp[2*n-1-i])
            max = dp[2*n-1-i];
    }

    cout << max << "\n";
    dp.clear();
}