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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll n;
int a[N];
int pos[N];
int ans[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld", &n);
		vector<pair<ll, ll>> ds;
		ds.clear();
		for (ll i = 2; i * i <= n; ++i) {
			if (n%i==0) {
				int cnt=0;
				while(n%i==0) {
					cnt++;
					n/=i;
				}
				ds.push_back(make_pair(-cnt, i));
			}
		}
	//	cout<<ds.size()<<" "<<n<<endl;
		if (n>1) {
			ds.push_back(make_pair(-1, n));
		}
		sort(ds.begin(), ds.end());
		// for (int i = 0; i < ds.size(); ++i) {
		// 	cout<<"i="<<i<<" "<<ds[i].second<<" "<<-ds[i].first<<endl;
		// }
		vector<ll> res;
		res.clear();
		for (int i = 1; i <= -ds[0].first; ++i) {
			res.push_back(ds[0].second);
		}
		int sz=res.size();
		for (int i = 1; i < ds.size(); ++i) {
			ll d = ds[i].second;
			ll cnt = -ds[i].first;
			for (int j = 1; j <= cnt; ++j) {
				res[sz-j] *= d;
			}
		}
		printf("%d\n", sz);
		for (int i = 0; i < sz; ++i) {
			printf("%lld", res[i]);
			if (i < res.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
