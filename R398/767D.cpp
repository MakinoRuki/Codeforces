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
#include <cmath>
#include <queue>
#include <time.h>
#define eps 1e-7
#define M 22
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
ll f[N], s[N];
bool check(vector<ll>& rk) {
	sort(rk.begin(), rk.end());
	int cur = 0;
	int i = 0;
	while(i < rk.size()) {
		if (rk[i] < cur) return false;
		i += k;
		cur++;
	}
	return true;
}
int main() {
	cin>>n>>m>>k;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &f[i]);
	}
	vector<pair<ll,int>> sv;
	sv.clear();
	for (int i = 1; i <= m; ++i) {
		scanf("%lld", &s[i]);
		sv.push_back(make_pair(s[i], i));
	}
	sort(f+1, f+n+1);
	sort(sv.begin(), sv.end());
	int l = 1, r = m+1;
	while(l < r) {
		int mid = (l+r)/2;
		// vector<ll> rk;
		// rk.clear();
		// for (int i = 1; i <= n; ++i) {
		// 	rk.push_back(f[i]);
		// }
		// for (int i = m; i >= mid; --i) {
		// 	rk.push_back(sv[i-1].first);
		// }
		int i = 1;
		int j = mid;
		int cur = 0;
		bool ok = true;
		for (int x = 1; x <= n + m-mid+1; x += k) {
			for (int y = 1; y <= k; ++y) {
				if (i > n && j > m) break;
				if (j > m || (i <= n && f[i] <= sv[j-1].first)) {
					if (f[i] < cur) {
						ok=false;
						break;
					}
					i++;
				} else {
					if (sv[j-1].first < cur) {
						ok=false;
						break;
					}
					j++;
				}
			}
			cur++;
		}
		if (ok) {
			r = mid;
		} else {
			l = mid+1;
		}
	}
	if (r == m+1) {
		vector<ll> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			rk.push_back(f[i]);
		}
		if (check(rk)) {
			puts("0");
		} else {
			puts("-1");
		}
	} else {
		printf("%d\n", m-r+1);
		for (int i = r; i <= m; ++i) {
			printf("%d", sv[i-1].second);
			if (i < m) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
