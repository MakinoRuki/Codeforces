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
#define M 25
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n;
ll ww;
ll w[N];
ll cnt[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%lld", &n, &ww);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &w[i]);
			cnt[w[i]]++;
		}
		ll ans=0;
		ll tot=0;
		while(tot < n) {
			ans++;
			ll w2 = ww;
			for (int i = 20; i >= 0; --i) {
				if ((1<<i) > 1000000) continue;
				if (w2 <= 0) break;
				ll num = min(cnt[(1<<i)], w2/(1<<i));
				w2 -= num*(1<<i);
				cnt[(1<<i)] -= num;
				tot += num;
			}
		//	cout<<"w="<<w2<<endl;
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= n; ++i) {
			cnt[w[i]] = 0;
		}
	}
  return 0;
}
