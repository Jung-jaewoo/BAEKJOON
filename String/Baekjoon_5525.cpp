#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int N, M;
    string str;
    cin >> N;
    cin >> M;
    cin >> str;
    int sol = 0, pat = 0;
    for (int i = 1; i < M - 1; i++){
        if (str[i - 1] == 'I' && str[i] == 'O' && str[i + 1] == 'I') {
            pat++;
            if (pat == N) {
                pat--;
                sol++;
            }
            i++;
        }
        else
            pat = 0;
    }
    cout << sol;
    return 0;
}