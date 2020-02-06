#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 300005
using namespace std;
typedef long long ll;
int n, k;
string s;
int par[N];
bool sf[N];
int cnt[N][2];
vector<int> cs[N];
int num[N];
bool check(int u, int pu, int v, int pv, int t) {
	if (t) {
		if (sf[u] == sf[v]) return false;
		return true;
	} else {
		if (sf[u] != sf[v]) return false;
		return true;
	}
}
int find(int u) {
	if (u == par[u]) return u;
	int p = find(par[u]);
	sf[u] = !(sf[u] ^ sf[par[u]]);
	par[u] = p;
	return p;
}
int main() {
	cin>>n>>k;
	cin>>s;
	for (int i = 1; i <= k; ++i) {
		par[i] = i;
		sf[i] = 1;
		cnt[i][0] = 0;
		cnt[i][1] = 1;
		num[i] = 1;
	}
	for (int i = 1; i <= k; ++i) {
		int c;
		cin>>c;
		for (int j = 0; j < c; ++j) {
			int x;
			cin>>x;
			cs[x].push_back(i);
		}
	}
	int ans=0;
	for (int i = 1; i <= n; ++i) {
		if (cs[i].empty()) {
			cout<<ans<<endl;
		} else {
			int t = (s[i-1] == '0');
			if (cs[i].size() == 1) {
				int u = cs[i][0];
				int pu = find(u);
				ans -= min(cnt[pu][0], cnt[pu][1]);
				cnt[pu][sf[u]^t] = 1000000000;
				ans += min(cnt[pu][0], cnt[pu][1]);
			} else {
				int u = cs[i][0];
				int v = cs[i][1];
				int pu = find(u);
				int pv = find(v);
				if (pu != pv) {
					if (num[pu] > num[pv]) {
						swap(u, v);
						swap(pu, pv);
					}
				//	if (i == 4) cout<<"i = 4 !"<<endl;
					ans -= min(cnt[pu][0], cnt[pu][1]) + min(cnt[pv][0], cnt[pv][1]);
					if (check(u, pu, v, pv, t)) {
						cnt[pv][0] = min(1000000000, cnt[pv][0] + cnt[pu][0]);
						cnt[pv][1] = min(1000000000, cnt[pv][1] + cnt[pu][1]);
						//if (i == 4) cout<<cnt[pv][0]<<" "<<cnt[pv][1]<<endl;
					} else {
						sf[pu] = 0;
						cnt[pv][0] = min(1000000000, cnt[pv][0] + cnt[pu][1]);
						cnt[pv][1] = min(1000000000, cnt[pv][1] + cnt[pu][0]);
					}
					par[pu] = pv;
					num[pv] += num[pu];
					ans += min(cnt[pv][0], cnt[pv][1]);
				}
			}
			cout<<ans<<endl;
		}
		//cout<<i<<" "<<sf[1]<<" "<<sf[2]<<endl;
	}
	return 0;
}
