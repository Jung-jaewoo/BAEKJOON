#include <iostream>
using namespace std;

int main()
{
	int N, K, cnt, sol;
	cnt = 1;
	sol = 0;
	cin >> N >> K;
	if (N <= K) {
		cout << 0;
		return 0;
	}
	int result;
	for (result = 0; ; result++) {
		int cnt = 0, tempN = N;
		while (tempN) {
			if (tempN % 2 == 1)
				cnt++;
			tempN /= 2;
		}
		if (cnt <= K)
			break;
		N++;
	}
	cout << result;
	return 0;
}

