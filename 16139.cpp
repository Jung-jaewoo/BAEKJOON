#include <iostream>
#include <string>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[26][200002];

int main()
{
    fastio;
    int q, l, r;
    string S;
    cin >> S;
    int Ssize = S.size();
    for(int i = 1; i<=Ssize; i++)
        arr[S[i-1]-'a'][i] = 1;
    for(int i = 0; i<26; i++)
        for(int j=1; j<=Ssize; j++)
            arr[i][j] +=arr[i][j-1];
    cin >> q;
    char alpha;
    while(q--){
        cin >> alpha >> l >> r;
        cout << arr[alpha-'a'][r+1]-arr[alpha-'a'][l] << "\n";
    }
    return 0;
}