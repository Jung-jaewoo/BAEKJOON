#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    int arr[100][100];
    for (int i = 0; i < 100; i++)
        fill(arr[i], arr[i] + 100, 0);

    int N, x, y;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        for (int i = x; i < x + 10; i++)
            for (int j = y; j < y + 10; j++)
                arr[i][j] = 1;
    }

    int sum = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            sum += arr[i][j];
    cout << sum << endl;
    return 0;
}