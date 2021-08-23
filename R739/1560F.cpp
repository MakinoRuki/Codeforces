#pragma GCC optimize(2)
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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
ll suf[M][M];
ll pw[M];
ll getres(vector<int> ds, int i, int d1, int d2, int k) {
	ds[i] = d1;
	for (int j = i+1; j < ds.size(); ++j) {
		ds[j] = d2;
	}
	set<int> ss;
	ss.clear();
	ll tmp = 0LL;
	for (int j = 0; j < ds.size(); ++j) {
		ss.insert(ds[j]);
		tmp = tmp * 10LL + ds[j];
	}
	if ((int)ss.size() <= k) {
		return tmp;
	}
	return -1;
}
int main() {
	for (int i = 0; i <= 9; ++i) {
		suf[i][1] = i;
		for (int j = 2; j <= 20; ++j) {
			suf[i][j] = suf[i][j-1]*10LL+i;
		}
	}
	pw[0] = 1LL;
	for (int i = 1; i <= 10; ++i) {
		pw[i] = pw[i-1] * 10LL;
	}
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		ll ans = 1111111111;
		vector<int> ds;
		ds.clear();
		ll x = n;
		while(x) {
			ds.push_back(x%10);
			x/=10;
		}
		reverse(ds.begin(), ds.end());
		ll tmp = 0LL;
		bool has[10];
		memset(has, false, sizeof(has));
		int cnt=0;
		for (int i = 0; i < ds.size(); ++i) {
			int p = ds.size()-1-i;
			for (int d1 = ds[i]+1; d1 <= 9; ++d1) {
				for (int d2 = 0; d2 <= 9; ++d2) {
					int cnt2=cnt;
					if (!has[d1]) cnt2++;
					if (d2 != d1 && !has[d2]) cnt2++;
					if (cnt2 > k) continue;
					ll tmp2 = (tmp*10LL+d1)*pw[p] + suf[d2][p];
					ans = min(ans, tmp2);
				}
			}
			tmp = tmp*10LL+ds[i];
			if (!has[ds[i]]) cnt++;
			has[ds[i]] = true;
		}
		if (cnt<=k) {
			ans=min(ans, tmp);
		}
		printf("%lld\n", ans);
	}
  return 0;
}
