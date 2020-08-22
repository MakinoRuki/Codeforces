#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t, n, m;
vector<int> edges[N];
int p[N];
ll dfs(int u, int p, vector<ll>& es) {
	ll tot=1;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v==p) continue;
		ll num = dfs(v, u, es);
		es.push_back(num*((ll)n-num));
		tot += num;
	}
	return tot;
}
int main() {
	cin>>t;
	for (int cas=1; cas<= t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int u,v;
			scanf("%d%d", &u,&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		scanf("%d", &m);
		for (int i =1 ; i <= m; ++i) {
			scanf("%d", &p[i]);
		}
		vector<ll> es;
		es.clear();
		dfs(1, 0, es);
		sort(es.begin(), es.end());
		reverse(es.begin(), es.end());
		ll ans = 0LL;
		sort(p+1, p+m+1);
		int det = max(0, m-(n-1));
		ll res=1LL;
		for (int i = 1; i <= det; ++i) {
			res = res*(ll)p[m-i+1]%mod;
		}
		// if (det>0) {
		// 	ans=(ans+res)%mod;
		// }
	//	cout<<"det="<<det<<endl;
		int j = m-det;
		for (int i = 0; i < es.size(); ++i) {
		//	cout<<i<<" "<<es[i]<<endl;
			ll cur;
			if (j >= 1) {
				cur = es[i]%mod * (ll)p[j]%mod;
			//	cout<<"j="<<j<<" "<<res<<endl;
			//	ans = (ans+res)%mod;
			} else {
				cur = es[i]%mod;
			//	cout<<"j="<<j<<" "<<res<<endl;
				//ans = (ans+res)%mod;
			}
			if (i==0 && det>0) {
				cur = cur*res%mod;
			}
			ans=(ans+cur)%mod;
			j--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
