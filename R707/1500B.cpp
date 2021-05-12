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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
ll k;
int a[N], b[N];
int id1[2*N], id2[2*N];
ll ab[2*N];
ll ab2[2*N];
void dfs(ll m1, ll& x, ll m2, ll& y) {
	if (m2 == 0) {
		x=1;
		y=0;
		return ;
	}
	dfs(m2, x, m1%m2, y);
	ll x1 = y;
	ll y1 = x-(m1/m2)*y;
	x = x1;
	y = y1;
}
ll getgcd(ll x, ll y) {
	return (y == 0 ? x : getgcd(y, x%y));
}
void getres(int id, ll m1, ll r1, ll m2, ll r2) {
	ll g = getgcd(m1, m2);
	if (abs(r2-r1)%g != 0) {
		return ;
	}
	ab2[id] = m1/g*m2;
	ll x, y;
	dfs(m1/g, x, m2/g, y);
	ll x2 = (r2-r1)/g*x;
	x2 = m1*x2+r1;
	if (x2 < 0) {
		ll det = (-x2+ab2[id]-1)/ab2[id];
		x2 += det*ab2[id];
	} else if (x2 >= ab2[id]) {
		x2 %= ab2[id];
	}
	ab[id] = x2;
}
int main() {
	cin>>n>>m>>k;
	memset(id1, -1, sizeof(id1));
	memset(id2, -1, sizeof(id2));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		id1[a[i]] = i;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
		id2[b[i]] = i;
	}
	memset(ab, -1, sizeof(ab));
	memset(ab2, -1, sizeof(ab2));
	for (int i = 1; i <= 2*max(n,m); ++i) {
		if (id1[i]>=0 && id2[i]>=0) {
			getres(i, n, id1[i], m, id2[i]);
		}
	}
	ll l = 1, r = (1LL<<62)-1;
	while(l<r) {
		ll mid=(l+r)/2;
		ll tot=0LL;
		for (int i = 1; i <= 2*max(n,m); ++i) {
			if (ab[i] >= 0) {
				if (mid < ab[i]+1) {
					continue;
				}
			//	if (mid == 46) cout<<i<<" "<<ab[i]+1<<" "<<(mid-(ab[i]+1))/ab2[i]+1<<endl;
				tot += (mid-(ab[i]+1))/ab2[i]+1;
			}
		}
		tot = mid - tot;
		//cout<<mid<<" "<<tot<<endl;
		if (tot >= k) {
			r = mid;
		} else {
			l = mid+1;
		}
	}
	printf("%lld\n", r);
  return 0;
}
