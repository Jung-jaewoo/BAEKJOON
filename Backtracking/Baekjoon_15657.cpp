#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int arr[8];
int N, M;
void printorder(int* order);
void permutation(int* order, int k);

int main()
{
	fastio;
	cin >> N >> M;
	int* order;
	order = new int[M];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	permutation(order, 0);
	return 0;
}

void printorder(int* order)
{
	for (int i = 0; i < M; i++)
		cout << order[i] << " ";
	cout << "\n";
}

void permutation(int* order, int k)
{
	if (k == M)
		printorder(order);
	else {
		for (int i = 0; i < N; i++) {
			if (k == 0) {
				order[k] = arr[i];
				permutation(order, k + 1);
			}
			else if (order[k-1]<=arr[i]) {
				order[k] = arr[i];
				permutation(order, k + 1);
			}
		}
	}
}