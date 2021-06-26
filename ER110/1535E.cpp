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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int q;
ll a[N], c[N];
int f[N][M];
int par[N];
ll sum[N];
ll used[N];
int dep[N];
int getpar(int u, int l) {
	if (l == 0) return u;
	int cur = u;
	for (int i = 20;  i>= 0; --i) {
		if ((1<<i) <= l) {
			cur = f[cur][i];
			l -= (1<<i);
		}
	}
	return cur;
}
int main() {
	memset(par, -1, sizeof(par));
	memset(f, -1, sizeof(f));
	memset(sum, 0LL, sizeof(sum));
	memset(used, 0LL, sizeof(used));
	memset(dep, 0, sizeof(dep));
	scanf("%d%lld%lld", &q, &a[0], &c[0]);
	sum[0] = a[0];
	for (int i = 1; i <= q; ++i) {
		int ty;
		scanf("%d", &ty);
		if (ty == 1) {
			scanf("%d%lld%lld", &par[i], &a[i], &c[i]);
			f[i][0] = par[i];
			for (int j = 1; j <= 20; ++j) {
				if (f[i][j-1] >= 0 && f[f[i][j-1]][j-1] >= 0) {
					f[i][j] = f[f[i][j-1]][j-1];
				}
			}
			dep[i] = dep[par[i]]+1;
			sum[i] = a[i];
			if (par[i] >= 0) {
				sum[i] += sum[par[i]];
			}
		} else {
			int v;
			ll w;
			scanf("%d%lld", &v, &w);
			int lev = 0;
			if (used[0] < a[0]) {
				lev = dep[v];
			} else {
				int l = 0, r = dep[v];
				while(l < r) {
					int mid = (l+r+1)/2;
					int pr = getpar(v, mid);
					if (used[pr] < a[pr]) {
						l = mid;
					} else {
						r = mid-1;
					}
				}
				lev = r;
			}
			ll x = 0, y = 0;
			for (int j = lev; j >= 0; --j) {
				if (w == 0) break;
				int pr = getpar(v, j);
				ll det = min(w, a[pr]-used[pr]);
				x += det;
				y += det * c[pr];
				used[pr] += det;
				w -= det;
			}
			printf("%lld %lld\n", x, y);
			fflush(stdout);
		}
	//	cout<<"i="<<i<<" "<<sum[1]<<endl;
	}
  return 0;
}
