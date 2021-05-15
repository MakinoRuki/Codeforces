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
int t, n, p;
int a[N];
bool vis[N];
int getgcd(int x, int y) {
	return y == 0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &p);
		for (int i =1; i <= n; ++i) {
			vis[i] = false;
		}
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			rk.push_back(make_pair(a[i], i));
		}
		ll tot=0LL;
		sort(rk.begin(), rk.end());
		for (int i = 0; i < rk.size(); ++i) {
			int id = rk[i].second;
			if (a[id] >= p) {
				break;
			}
			for (int j = id-1; j >= 1; --j) {
				if (getgcd(a[j], a[id]) == a[id] && !vis[j]) {
					tot += (ll)a[id];
					vis[j] = true;
				} else {
					break;
				}
			}
			for (int j = id+1; j <= n; ++j) {
				if (getgcd(a[id], a[j]) == a[id] && !vis[j-1]) {
					tot += (ll)a[id];
					vis[j-1] = true;
				} else {
					break;
				}
			}
		}
		for (int i = 1; i < n; ++i) {
			if (!vis[i]) tot += (ll)p;
		}
		printf("%lld\n", tot);
	}
  return 0;
}
