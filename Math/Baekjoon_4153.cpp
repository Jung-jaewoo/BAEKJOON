#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x, y, z, tmp;
	while (1)
	{
		cin >> x >> y >> z;
		if ((x == 0) && (y == 0) && (z == 0))
			break;
		if (x > y)
		{
			tmp = x;
			x = y;
			y = tmp;
		}
		if (y > z)
		{
			tmp = y;
			y = z;
			z = tmp;
		}
		if (x > y)
		{
			tmp = x;
			x = y;
			y = tmp;
		}
		if (pow(z,2) == pow(x,2) + pow(y,2))
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";
	}

	return 0;
}



