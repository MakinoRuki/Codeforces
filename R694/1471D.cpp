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
#define M 1000005
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000009LL;
ll mod2 = 998244353LL;
int t, n, m;
int a[N];
int q;
int vis[M];
int main() {
	cin>>t;
	memset(vis, -1, sizeof(vis));
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		
		unordered_map<int,int> cnt;
		cnt.clear();

		for (int i = 1; i <= n; ++i) {
			if (vis[a[i]]>0) {
				cnt[vis[a[i]]]++;
				continue;
			}
			ll x = a[i];
			ll res=1LL;
			for (ll j = 2; j *j <= x; ++j) {
				if (x%j==0) {
					while(x % (j*j) == 0) {
						x/=(j*j);
					}
					if (x % j == 0) {
						res *= j;
						x /= j;
					}
				}
			}
			if (x > 1) {
				res *= x;
			}
		//	cout<<i<<" "<<a[i]<<" "<<res<<endl;
		//	cout<<i<<" "<<a[i]<<" "<<res<<endl;
			vis[a[i]] = res;
			cnt[res]++;
		}

		int ans=0;
		int cnt2=0;
		for (auto itr : cnt) {
		//	cout<<itr.first<<" "<<itr.second<<endl;
			ans=max(ans, itr.second);
			if (itr.first != 1 && (itr.second%2==0)) {
				cnt2 += itr.second;
			}
		}
		cin>>q;
		while(q-->0) {
			ll w = 0LL;
			scanf("%lld", &w);
			if (w == 0) {
				printf("%d\n", ans);
			} else {
				int ans2 = max(ans, cnt[1]+cnt2);
				printf("%d\n", ans2);
			}
		}
	}
	return 0;
}
