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
#define eps 1e-7
#define M 20005
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int a[N];
vector<int> edges[N];
unordered_map<int, int> cnt[2];
int tot;
int tot0, tot1;
int dfs(int u, int p) {
	if (edges[u].size()==0) {
		tot1++;
		cnt[1][a[u]]++;
		tot ^= a[u];
		return 1;
	}
	int nxt=0;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		nxt=dfs(v, u);
	}
	nxt ^= 1;
	cnt[nxt][a[u]]++;
	if (nxt) {
		tot ^= a[u];
		tot1++;
	} else tot0++;
	return nxt;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	cnt[0].clear();
	cnt[1].clear();
	for (int i = 2; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		edges[p].push_back(i);
	}
	tot=0;
	tot0=0, tot1=0;
	dfs(1, 0);
	ll ans=0LL;
	if (tot==0) {
		if (tot0>1) {
			ans += (ll)tot0*(ll)(tot0-1)/2LL;
		}
		if (tot1>1) {
			ans += (ll)tot1*(ll)(tot1-1)/2LL;
		}
		for (auto itr : cnt[0]) {
			if (cnt[1].find(itr.first) != cnt[1].end()) {
				ans += (ll)itr.second * (ll)cnt[1][itr.first];
			}
		}
	} else {
		for (auto itr : cnt[1]) {
			ll res=tot^(itr.first);
			if (cnt[0].find(res)!=cnt[0].end()) {
				ll num=(ll)cnt[0][res] * (ll)itr.second;
				ans += num;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
