#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int N, B, C;
    long long sol = 0;
    cin >> N;
    int* A;
    A = new int[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> B >> C;
    for (int i = 0; i < N; i++) {
        if (A[i] > B) {
            sol++;
            A[i] -= B;
        }
        else {
            sol++;
            continue;
        }
        sol += (long long)A[i] / C;
        if (A[i] % C != 0) sol++;
    }
    cout << sol;
    return 0;
}