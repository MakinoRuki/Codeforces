#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#define N 5002
using namespace std;
typedef long long ll;
int k;
int a[16][N];
vector<vector<pair<int, ll>>> dp[1<<15];
ll sum[16];
unordered_map<ll, pair<int, int>> mp;
pair<ll, int> ans[16];
int main() {
	cin>>k;
	ll tot=0;
	memset(sum, 0LL, sizeof(sum));
	mp.clear();
	for (int i = 1; i <= k; ++i) {
		int ni;
		cin>>ni;
		a[i][0] = ni;
		for (int j = 1; j <= ni; ++j) {
			cin>>a[i][j];
			tot += (ll)a[i][j];
			sum[i] += a[i][j];
			mp[a[i][j]] = make_pair(i,j);
		}
	}
	if (tot % k) {
		cout<<"No"<<endl;
		return 0;
	}
	tot /= k;
	for (int i= 0; i < (1<<k); ++i) {
		dp[i].clear();
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= a[i][0]; ++j) {
		//	cout<<i<<" "<<j<<endl;
			int s = 0;
			vector<pair<int, ll>> tmp;
			tmp.clear();
			int curi = i;
			int curj = j;
			bool ok = true;
			while(true) {
				if (tmp.size() >= k) {
					ok = false;
					break;
				}
				s |= (1<<(curi-1));
				ll need = tot - (sum[curi]-a[curi][curj]);
				if (mp.find(need) == mp.end()) {
					ok = false;
					break;
				}
				tmp.push_back(make_pair(curi, a[curi][curj]));
				int nxti = mp[need].first;
				int nxtj = mp[need].second;
				if (nxti == i) {
					if (nxtj != j) {
						ok = false;
					}
					break;
				}
				curi = nxti;
				curj = nxtj;
			}
			if (ok && dp[s].empty()) {
				//cout<<i<<" "<<j<<" "<<s<<endl;
				dp[s].push_back(tmp);
			}
		}
	}
	// 子集dp。经典题。复杂度O(3^k)。
	for (int i = 0; i < (1<<k); ++i) {
		if (dp[i].size() > 0) continue;
		for (int j = i; j > 0; j = (j-1) & i) {
			if (dp[j].size() > 0 && dp[i-j].size() > 0) {
				for (int t = 0; t < dp[j].size(); ++t) {
					dp[i].push_back(dp[j][t]);
				}
				for (int t = 0; t < dp[i-j].size(); ++t) {
					dp[i].push_back(dp[i-j][t]);
				}
				break;
			}
		}
	}
	// for (int i = 0; i < dp[(1<<k)-1].size(); ++i) {
	// 	cout<<"xxx"<<dp[(1<<k)-1][i].first<<" "<<dp[(1<<k)-1][i].second<<endl;
	// }
	if (dp[(1<<k)-1].empty()) {
		cout<<"No"<<endl;
	} else {
		cout<<"Yes"<<endl;
		for (int i = 0; i < dp[(1<<k)-1].size(); ++i) {
			auto vi = dp[(1<<k)-1][i];
			int sz = vi.size();
			for (int j = 0; j < vi.size(); ++j) {
				int id = vi[j].first;
				ll need = vi[j].second;
				int id2 = vi[(j-1+sz)%sz].first;
				ans[id] = make_pair(need, id2);
				//cout<<need<<" "<<id2<<endl;
			}
		}
		for (int i = 1; i <= k; ++i) {
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
	return 0;
}
