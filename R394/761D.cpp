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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
int l, r;
int a[N], p[N];
ll b[N];
int main() {
	// cin>>t;
	// for (int cas=1; cas<=t; ++cas) {
	// }
	cin>>n>>l>>r;
	vector<pair<int,int>> rk;
	rk.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; ++i) {
		rk.push_back(make_pair(p[i], i));
	}
	sort(rk.begin(), rk.end());
	reverse(rk.begin(), rk.end());
	ll ub = r;
	bool ok = true;
	for (int i = 0; i < rk.size(); ++i) {
		int id = rk[i].second;
		if (i == 0) {
			b[id] = ub;
			ub = b[id] - a[id] - 1;
		} else {
			ll cur = min((ll)r, a[id] + ub);
			if (cur < l) {
				ok=false;
				break;
			}
			b[id] = cur;
			ub = b[id] - a[id] - 1;
		}
	}
	if (!ok) puts("-1");
	else {
		for (int i = 1; i <= n; ++i) {
			printf("%lld", b[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
