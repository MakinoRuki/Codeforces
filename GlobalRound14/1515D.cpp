#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m, x;
int l, r;
int c[N];
int cnt[N][2];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d", &n, &l, &r);
		for (int i = 1; i <= n; ++i) {
			cnt[i][0] = 0;
			cnt[i][1] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &c[i]);
			if (i <= l) cnt[c[i]][0]++;
			else cnt[c[i]][1]++;
		}
		int ans=0;
		int d0 = 0, c0=0;
		int d1 = 0, c1=0;
		for (int i = 1; i <= n; ++i) {
			if (cnt[i][0] > cnt[i][1]) {
				d0 += cnt[i][0]-cnt[i][1];
				if ((cnt[i][0]-cnt[i][1])%2) {
					c0++;
				}
			} else {
				d1 += cnt[i][1]-cnt[i][0];
				if ((cnt[i][1]-cnt[i][0])%2) {
					c1++;
				}
			}
		}
		if (c0 && c1) {
			if (c0 > c1) {
				if (c0 <= d1) {
					ans = (d0+d1)/2;
				} else {
					int det = c0-d1;
					ans = det + (d0+d1-det)/2;
				}
			} else {
				if (c1 <= d0) {
					ans = (d0+d1)/2;
				} else {
					int det = c1-d0;
					ans = det + (d0+d1-det)/2;
				}
			}
		} else if (c0) {
			if (c0 <= d1) {
				ans = (d0+d1)/2;
			} else {
				int det = c0-d1;
				ans = det + (d0+d1-det)/2;
			}
		} else {
			if (c1 <= d0) {
				ans = (d0+d1)/2;
			} else {
				int det = c1-d0;
				ans = det+(d0+d1-det)/2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
