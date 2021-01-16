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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000009LL;
ll mod2 = 998244353LL;
int t, n, x;
int a[N];
int cnt[N];
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i =1; i <= n; ++i) {
			cnt[i] = 0;
			int y=a[i];
			while(y%x==0) {
				cnt[i]++;
				y/=x;
			}
		}
		int id=1;
		for (int i = 1; i <= n; ++i) {
			if (cnt[i] < cnt[id]) {
				id = i;
			}
		}
		for (int i = id-1; i >= 1; --i) {
			cnt[i] = min(cnt[i], cnt[id]+1);
		}
		for (int i = id+1; i <= n; ++i) {
			cnt[i] = min(cnt[i], cnt[id]);
		}
		ll tot=0LL;
		for (int i = 1; i <= n; ++i) {
			tot += (ll)(cnt[i]+1) * (ll)a[i];
		}
		printf("%lld\n", tot);
	}
	return 0;
}
