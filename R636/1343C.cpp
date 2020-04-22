#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
int t, n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		ll ans=0LL;
		ll cur=0LL;
		for (int i = 1; i <= n; ++i) {
			if (i==1) {
				cur = a[i];
			} else {
				if (a[i]>0&&a[i-1]>0) {
					cur = max(cur, (ll)a[i]);
				} else if (a[i] < 0 && a[i-1]<0) {
					cur = max(cur, (ll)a[i]);
				} else {
					ans += cur;
					cur = a[i];
				}
			}
		}
		ans += cur;
		printf("%lld\n", ans);
	}
	return 0;
}
