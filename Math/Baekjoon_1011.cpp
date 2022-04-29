#include <iostream>
using namespace std;

int calculation(int x, int y);

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << calculation(x, y) << endl;
	}
	return 0;
}

int calculation(int x, int y)
{
	int distance = y - x;
	int cnt = 1;
	while (1)
	{
		if (distance - 2 * cnt < 0)
			break;
		distance -= 2 * cnt;
		cnt += 1;
	}
	cnt -= 1;
	if (distance == 0)
		return cnt * 2;
	if (distance <= cnt + 1)
		return cnt * 2 + 1;
	if (distance > cnt + 1)
		return cnt * 2 + 2;
}