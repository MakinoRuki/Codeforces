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
#define N 100005
using namespace std;
typedef long long ll;
int t,n;
ll a[N];
ll b[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}
		int i;
		for (i = 2; i <= n; ++i) {
			if (a[i] < a[i-1]) break;
		}
		if (i > n) {
			cout<<0<<endl;
			continue;
		}
		int l = 1, r = 32;
		while(l < r) {
			int m = (l+r)/2;
			for (int i = 1; i <= n; ++i) {
				b[i] = a[i];
			}
			int i;
			for (i = 1; i <= n; ++i) {
				if (i == 1) continue;
				ll det = b[i]-b[i-1];
				if (det>=0) continue;
				det = abs(det);
				int p = m-1;
				while(p >= 0) {
					if (det >= (1LL<<p)) {
						det -= (1LL<<p);
					}
					p--;
				}
				if (det == 0) {
					b[i] = b[i-1];
					continue;
				}
				break;
			}
			if (i > n) r = m;
			else l = m+1;
		}
		cout<<r<<endl;
	}
	return 0;
}
