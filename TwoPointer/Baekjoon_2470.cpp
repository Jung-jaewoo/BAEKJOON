#include <iostream>
#include <algorithm>
#include <cmath>
//#include <vector>
//#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2e10
#define ll long long
using namespace std;

void input(int *N, int **arr);
void solution(int N, int *arr);

int main()
{
    fastio;
    int N;
    int *arr;
    input(&N, &arr);
    sort(arr, arr + N);
    solution(N, arr);
    return 0;
}

void input(int *N, int **arr)
{
    cin >> *N;
    *arr = new int[*N];
    for (int i = 0; i < *N; i++)
        cin >> (*arr)[i];
}

void solution(int N, int *arr)
{
    int ptr1 = 0, ptr2 = N - 1;
    int solp1, solp2;
    ll closezero = INF;
    ll sum;
    while (ptr1 < ptr2)
    {
        sum = (ll)arr[ptr1] + arr[ptr2];
        if (abs(sum) < closezero)
        {
            closezero = abs(sum);
            solp1 = ptr1;
            solp2 = ptr2;
        }
        if (sum < 0)
            ptr1++;
        else if (sum > 0)
            ptr2--;
        else
        {
            cout << arr[ptr1] << " " << arr[ptr2];
            return;
        }
    }
    cout << arr[solp1] << " " << arr[solp2];
}