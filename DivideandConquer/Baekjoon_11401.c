#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
ll mul(ll x, ll y, ll p);
int main()
{
	ll n, r, p;
	scanf("%lld %lld", &n, &r);
	p = 1000000007;
	ll ans = 1;
	ll t1 = 1;
	ll t2 = 1;
	for (ll i = 1; i <= n; i++) {
		t1 *= i;
		t1 %= p;
	}
	for (ll i = 1; i <= r; i++) {
		t2 *= i;
		t2 %= p;
	}
	for (ll i = 1; i <= n-r; i++) {
		t2 *= i;
		t2 %= p;
	}
	ll t3 = mul(t2, p - 2, p);
	t3 %= p;
	ans = (t1 * t3) % p;
	printf("%lld", ans);
	return 0;
}

ll mul(ll x, ll y, ll p)
{
	ll ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}