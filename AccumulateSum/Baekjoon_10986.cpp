#include <iostream>
#include <string>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    ll tmp, * arr; // 동적할당
    arr = new ll[n + 1];
    ll* sumarr;
    sumarr = new ll[m] ;
    for (int i = 0; i < m; i++) sumarr[i] = 0; // sumarr 초기화
    arr[0] = 0; // 누적합 초기값
    for (int i = 1; i <= n; i++) { //누적 합 %m 구하기
        cin >> tmp;
        arr[i] = (arr[i - 1] + tmp) % m;
        sumarr[arr[i]]++;
    }
    ll sum = sumarr[0];
    for (int i = 0; i < m; i++) {
        sum += (sumarr[i]*(sumarr[i]-1))/ 2;
    }
    cout << sum;
    return 0;
}