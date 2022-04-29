#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	int diffx, diffy;

	if (x1 == x2)
		diffx = x3;
	else if (x1 == x3)
		diffx = x2;
	else
		diffx = x1;

	if (y1 == y2)
		diffy = y3;
	else if (y1 == y3)
		diffy = y2;
	else
		diffy = y1;

	cout << diffx << " " << diffy;

	return 0;
}



