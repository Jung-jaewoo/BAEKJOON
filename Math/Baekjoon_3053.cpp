#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int R;
	cin >> R;
	double pi = 3.14159265358979;
	double euclid_circle, non_euclid_circle;
	euclid_circle = R * R * pi;
	non_euclid_circle = 2 * R * R;

	cout << fixed;
	cout.precision(6);
	cout << euclid_circle << "\n" << non_euclid_circle;
	
	return 0;
}
