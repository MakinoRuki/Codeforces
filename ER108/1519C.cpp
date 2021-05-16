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
#define M 10005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int u[N];
int s[N];
vector<ll> sv[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			sv[i].clear();
		}
		ll tot=0LL;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &u[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &s[i]);
			tot += (ll)s[i];
		}
		for (int i = 1; i <= n; ++i) {
			sv[u[i]].push_back(s[i]);
		}
		for (int i = 1; i <= n; ++i) {
			if (sv[i].size() > 0) {
				sort(sv[i].begin(), sv[i].end());
				for (int j = 1; j < sv[i].size(); ++j) {
					sv[i][j] += sv[i][j-1];
				}
			}
		}
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			if (!sv[i].empty()) {
				rk.push_back(make_pair((int)sv[i].size(), i));
			}
		}
		sort(rk.begin(), rk.end());
		reverse(rk.begin(), rk.end());
		// cout<<"???"<<endl;
		// for (int i = 0; i < rk.size(); ++i) {
		// 	cout<<i<<" "<<rk[i].first<<endl;
		// }
		for (int i = 1; i <= n; ++i) {
		//	cout<<"i="<<i<<endl;
			while(!rk.empty() && rk.back().first < i) {
				int id = rk.back().second;
				tot -= sv[id].back();
				rk.pop_back();
			}
			ll tot2 = tot;
			for (int j = 0; j < rk.size(); ++j) {
				int id = rk[j].second;
				int sz = (int)sv[id].size();
				if (sz % i > 0) {
					tot2 -= sv[id][(sz%i)-1];
				}
			}
			printf("%lld", tot2);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
