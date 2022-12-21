#include <iostream>
#include <algorithm>
// #include <cmath>
// #include <vector>
// #include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// #define INF 2e9
// #define ll long long
using namespace std;

void input(int *N, int *v, int **arr);
void solution(int N, int v, int *arr);

int main()
{
    fastio;
    int N, v;
    int *arr;
    input(&N, &v, &arr);
    solution(N, v, arr);
    return 0;
}

void input(int *N, int *v, int **arr)
{
    cin >> *N;
    *arr = new int[*N];
    for (int i = 0; i < *N; i++)
        cin >> (*arr)[i];
    cin >> *v;
}

void solution(int N, int v, int *arr)
{
    int sol = 0;
    sort(arr, arr + N);
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > v)
            break;
        if (arr[i] == v)
            sol++;
    }
    cout << sol;
}