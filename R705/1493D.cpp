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
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, q;
int a[N];
map<int, int> cnt[N];
int cnt2[N];
map<int, int> b[N];
ll getpw(ll x, ll y) {
	ll res=1LL;
	while(y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return res;
}
int main() {
	cin>>n>>q;
	for (int i = 1; i <= 200000; ++i) {
		cnt[i].clear();
		cnt2[i]=0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		int x=a[i];
		for (int j = 2; j*j <= x; ++j) {
			if (x%j==0) {
				int num=0;
				while(x%j==0) {
					num++;
					x/=j;
				}
				cnt[j][num]++;
				cnt2[j]++;
				b[i][j] = num;
			}
		}
		if (x>1) {
			cnt[x][1]++;
			cnt2[x]++;
			b[i][x] = 1;
		}
	}
//	cout<<cnt2[2]<<endl;
	ll ans = 1LL;
	for (int i = 1; i <= 200000; ++i) {
		if (cnt2[i] == n) {
			ans = (ans * getpw(i, cnt[i].begin()->first)) % mod;
		}
	}
//	cout<<ans<<endl;
	while(q-->0) {
		int id, x;
		scanf("%d%d", &id, &x);
		vector<pair<int,int>> ps;
		ps.clear();
		for (int i = 2; i * i <= x; ++i) {
			if (x%i==0) {
				int num=0;
				while(x%i==0) {
					num++;
					x/=i;
				}
				ps.push_back(make_pair(i, num));
			}
		}
		if (x>1) {
			ps.push_back(make_pair(x, 1));
		}
		for (int i = 0; i < ps.size(); ++i) {
			int p = ps[i].first;
			if (b[id].find(p) == b[id].end()) {
				b[id][p] = ps[i].second;
				cnt[p][ps[i].second]++;
		//		cout<<p<<" "<<b[id][p]<<" "<<cnt[p][ps[i].second]<<" "<<cnt2[p]<<endl;
				if (cnt2[p] == n-1) {
					cnt2[p]++;
					ans = (ans * getpw(p, cnt[p].begin()->first)) % mod;
				} else {
					cnt2[p]++;
				}
				continue;
			}
			int ts = b[id][p];
			cnt[p][ts]--;
			bool del=false;
			bool has = false;
			if (cnt2[p] >= n) has=true;
			if (cnt[p][ts] == 0) {
				if (ts == (cnt[p].begin()->first) && cnt2[p] == n) {
					ans = (ans * getpw(p, (ll)ts*(ll)(mod-2))) % mod;
					del=true;
				}
				cnt[p].erase(ts);
			}
			cnt2[p]--;
			b[id][p] = ts+ps[i].second;
			ts = ts+ps[i].second;
			cnt[p][ts]++;
			cnt2[p]++;
			if ((!has&&cnt2[p]>=n) || del) {
				ans = (ans * getpw(p, cnt[p].begin()->first)) % mod;
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}
