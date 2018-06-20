#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 200010
using namespace std;
typedef long long ll;
int last[N];
int n, k;
int a[N];
int main() {
	cin>>n>>k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		last[i] = (a[i] == 1 ? last[i - 1] : i);
	}
	ll ans = 0LL;
	for (int i = 1; i <= n; ++i) {
		//cout<<"i="<<i<<endl;
		int j = i;
		ll s = 0, p = 1LL;
		while(j > 0) {
		//	cout<<"j="<<j<<" ";
			if (p > 2e18 / a[j]) break;
			s += a[j];
			p *= a[j];
			if (a[j] > 1) {
				if (p % s == 0 && p / s == k) {
					ans++;
				}
				j--;
			} else {
				ll delta = j - last[j] - 1;
				if (p % k == 0 && p / k >= s && p / k <= s + delta) {
					ans++;
				}
				j = last[j];
				s += delta;
			}
		}
	//	cout<<endl;
	}
	printf("%I64d\n", ans);
	return 0;
}
