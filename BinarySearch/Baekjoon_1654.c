#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll arr[10001];
ll mid;
ll maxL = 0;
ll minL = 1;
ll ans = 1;
void binarysearch(int k, int n);

int main()
{
	int K, N;
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%d", arr + i);
		if (maxL < arr[i])	
			maxL = arr[i];
	}
	binarysearch(K,N);
	printf("%lld", ans);
	return 0;
}

void binarysearch(int k, int n) {
	while (minL <= maxL) {
		ll cnt = 0;
		mid = (maxL + minL) / 2;
		for (int i = 0; i < k; i++)
			cnt += (arr[i] / mid);
		if (cnt < n)
			maxL = mid - 1;
		else {
			if (mid > ans)
				ans = mid;
			minL = mid + 1;
		}
	}
}