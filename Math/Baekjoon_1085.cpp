#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int min1 = h;
	int min2 = h;
	min1 = (x > y) ? y : x;
	min2 = (w - x > h - y) ? h - y : w - x;
	min1 = (min1 > min2) ? min2 : min1;

	cout << min1;

	return 0;
}



