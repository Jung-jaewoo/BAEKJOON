#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//#define INF 2e9
//#define ll long long
using namespace std;

void input(int *N, int *S, int **arr);
void solution(int N, int S, int *arr);

int main()
{
    fastio;
    int N, S;
    int *arr;
    input(&N, &S, &arr);
    solution(N, S, arr);
    return 0;
}

void input(int *N, int *S, int **arr)
{
    cin >> *N >> *S;
    *arr = new int[*N];
    for (int i = 0; i < *N; i++)
        cin >> (*arr)[i];
}

void solution(int N, int S, int *arr)
{
    int ptr1 = 0, ptr2 = 1;
    int sum = arr[ptr1];
    int minlength = N + 1;
    while (1)
    {
        if (sum >= S)
        {
            if (minlength > ptr2 - ptr1)
                minlength = ptr2 - ptr1;
            sum -= arr[ptr1];
            ptr1++;
        }
        else
        {
            if (ptr2 == N)
                break;
            sum += arr[ptr2];
            ptr2++;
        }
    }
    if (minlength != N + 1)
        cout << minlength;
    else
        cout << 0;
}