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
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
int s;
int t;
int n, m, k;
int a[N];
int ans[N];
int b[32][N];
ll pw[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int l, r;
		scanf("%d%d", &n, &m);
		pw[0] = 1LL;
		for (int i =1; i <= n; ++i) {
			pw[i] = pw[i-1] * (ll)2LL % mod;
		}
		for (int i = 0; i <= 30; ++i) {
			for (int j = 1; j <= n; ++j) {
				b[i][j] = -1;
			}
		}
		vector<pair<pair<int,int>,int>> sg;
		sg.clear();
		for (int i = 1; i <= m; ++i) {
			int x;
			scanf("%d%d%d", &l,&r,&x);
			sg.push_back(make_pair(make_pair(l, r), x));
		}
		ll ans = 0LL;
		for (int i = 0; i <= 30; ++i) {
			int cnt[N];
			for (int j = 1; j <= n; ++j) {
				cnt[j] = 0;
			}
			for (int j = 0; j < sg.size(); ++j) {
				if (sg[j].second & (1<<i)) {
					continue;
				}
				cnt[sg[j].first.first]++;
				cnt[sg[j].first.second+1]--;
			}
			int tot=0;
			for (int j = 1; j <= n; ++j) {
				tot += cnt[j];
				if (tot > 0) b[i][j] = 0;
				else b[i][j] = 1;
			}
			int n1 = 0, n0 = 0;
			for (int j = 1; j <= n; ++j) {
				if (b[i][j]) n1++;
				else n0++;
			}
		//	cout<<"i="<<i<<" "<<n1<<endl;
			if (n1 > 0) {
				ll det = (1LL<<i) % mod;
			//	cout<<pw[n0+n1-1]<<" "<<det<<endl;
				ans = (ans + pw[n0+n1-1] * det % mod) % mod;
		//		cout<<ans<<endl;
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}

