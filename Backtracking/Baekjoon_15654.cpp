#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef struct {
	int num, index;
}Num;
int arr[8];
int N, M;
void printorder(Num* order);
void permutation(Num* order, int k);

int main()
{
	fastio;
	cin >> N >> M;
	Num* order;
	order = new Num[M];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	permutation(order, 0);
	return 0;
}

void printorder(Num* order)
{
	for (int i = 0; i < M; i++)
		cout << order[i].num << " ";
	cout << "\n";
}

void permutation(Num* order, int k)
{
	if (k == M)
		printorder(order);
	else {
		int* check;
		check = new int[N];
		for (int i = 0; i < N; i++)
			check[i] = 0;
		for (int i = 0; i < k; i++)
			check[order[i].index] = 1;
		for (int i = 0; i < N; i++) {
			if (check[i] == 0) {
				order[k].num = arr[i];
				order[k].index = i;
				permutation(order, k + 1);
			}
		}
	}
}