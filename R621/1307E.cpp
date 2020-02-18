#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define N 5002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int s[N];
int l[N], r[N];
vector<int> hs[N];
unordered_set<int> hss[N];
ll cnt[N];
int cows[N];
void calc(int f) {
	ll a = upper_bound(hs[f].begin(), hs[f].end(), l[f]) - hs[f].begin();
	ll b = upper_bound(hs[f].begin(), hs[f].end(), r[f]) - hs[f].begin();
	if (a>b) swap(a,b);
	if (a*(b-1) > 0) {
		cows[f] = 2;
		cnt[f] = a*(b-1);
	} else if (a+b > 0) {
		cows[f] = 1;
		cnt[f] = a+b;
	} else {
		cows[f] = 0;
		cnt[f]=1;
	}
}
void calc2(int f, ll cnt0, int cow0, ll& maxn, int& maxc) {
	ll b = upper_bound(hs[f].begin(), hs[f].end(), r[f]) - hs[f].begin();
	if (l[f] <= r[f]) {
		b--;
	}
	if (b) {
		if (cow0 + 2 > maxc) {
			maxc = cow0+2;
			maxn = cnt0 * b % mod;
		} else if (cow0 + 2 == maxc) {
			maxn = (maxn + cnt0*b%mod) % mod;
		}
	} else {
		if (cow0+1 > maxc) {
			maxc = cow0+1;
			maxn = cnt0 * 1LL % mod;
		} else if (cow0 + 1== maxc) {
			maxn = (maxn + cnt0*1LL%mod) % mod;
		}
	}
}
ll getrev(ll c) {
	ll res=1LL;
	ll b = mod-2;
	while(b) {
		if (b&1) res=res*c%mod;
		c = c*c % mod;
		b /= 2;
	}
	return res;
}
int main() {
	cin>>n>>m;
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &s[i]);
		r[s[i]]++;
	}
	for (int i = 1; i <= m; ++i) {
		int f, h;
		scanf("%d%d", &f, &h);
		hs[f].push_back(h);
		hss[f].insert(h);
	}
	for (int i = 1; i <=n ; ++i) {
		sort(hs[i].begin(), hs[i].end());
	}
	ll cnt0 = 1LL;
	int cow0 = 0;
	ll maxn = 0;
	int maxc = 0;
	for (int i = 1; i <= n; ++i) {
		calc(i);
		cnt0 = cnt0 * cnt[i] % mod;
		cow0 += cows[i];
	}
	maxn = cnt0;
	maxc = cow0;
	//cout<<maxn<<" "<<maxc<<endl;
	for (int i = 1; i <= n; ++i) {
		cnt0 = cnt0 * getrev(cnt[s[i]]) % mod;
		cow0 -= cows[s[i]];
		r[s[i]]--;
		l[s[i]]++;
		if (hss[s[i]].find(l[s[i]]) != hss[s[i]].end()) {
			calc2(s[i], cnt0, cow0, maxn, maxc);
		}
		calc(s[i]);
		cnt0 = cnt0 * cnt[s[i]] % mod;
		cow0 += cows[s[i]];
	//	cout<<"i="<<i<<" "<<cnt[s[i]]<<" "<<cows[s[i]]<<endl;
		// if (cow0 > maxc) {
		// 	maxn = cnt0;
		// 	maxc = cow0;
		// } else if (cow0 == maxc) {
		// 	maxn = (maxn + cnt0) % mod;
		// }
	//	cout<<i<<" "<<maxc<<" "<<maxn<<endl;
	}
	cout<<maxc<<" "<<maxn<<endl;
	return 0;
}
