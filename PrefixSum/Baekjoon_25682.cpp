#include <iostream>
#include <algorithm>
// #include <cmath>
// #include <vector>
// #include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// #define INF 2e9
//  #define ll long long
using namespace std;

void solution(void);
void input(int **arr, int N, int M);
void makePrefixSum(int **arr, int **prefix_sum, int N, int M, int K, int color);
int findMinSum(int **prefix_sum, int N, int M, int K);

int main()
{
    fastio;
    solution();
    return 0;
}

void solution()
{
    int N, M, K;
    cin >> N >> M >> K;

    int **arr;
    arr = new int *[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[M];
    }

    input(arr, N, M);

    int **prefix_sum;
    prefix_sum = new int *[N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        prefix_sum[i] = new int[M + 1];
    }

    int min1, min2;
    makePrefixSum(arr, prefix_sum, N, M, K, 1);
    min1 = findMinSum(prefix_sum, N, M, K);
    makePrefixSum(arr, prefix_sum, N, M, K, 0);
    min2 = findMinSum(prefix_sum, N, M, K);

    cout << min(min1, min2);
}

void input(int **arr, int N, int M)
{
    char tmp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            arr[i][j] = (tmp == 'B') ? 1 : 0;
        }
    }
}

void makePrefixSum(int **arr, int **prefix_sum, int N, int M, int K, int color)
{
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < M + 1; j++)
        {
            prefix_sum[i][j] = 0;
        }
    }

    int value;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (arr[i][j] == color)
                    value = 1;
                else
                    value = 0;
            }
            else
            {
                if (arr[i][j] != color)
                    value = 1;
                else
                    value = 0;
            }
            prefix_sum[i + 1][j + 1] = prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j] + value;
        }
    }
}

int findMinSum(int **prefix_sum, int N, int M, int K)
{
    int count = K * K;
    for (int i = 1; i < N - K + 2; i++)
    {
        for (int j = 1; j < M - K + 2; j++)
        {
            count = min(count, prefix_sum[i + K - 1][j + K - 1] - prefix_sum[i + K - 1][j - 1] - prefix_sum[i - 1][j + K - 1] + prefix_sum[i - 1][j - 1]);
        }
    }
    return count;
}