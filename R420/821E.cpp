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
#define M 21
#define N 102
#define SZ 200000002
#define eps 1e-7
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
ll k;
vector<pair<pair<ll,ll>, int>> abc;
ll a[20];
ll b[20][20];
void calc(ll len, int ub) {
	memset(b, 0LL, sizeof(b));
	for (int i = 0; i <= ub; ++i) {
		if (i-1>=0) b[i][i-1]=1;
		b[i][i] = 1;
		if (i+1<=ub) b[i][i+1] = 1;
	}
	if (len == 0) {
		for (int i = ub+1; i<=15; ++i) {
			a[i] = 0LL;
		}
		return;
	}
	while(len) {
		if (len&1) {
			ll c[20];
			for (int i = 0; i <= ub; ++i) {
				c[i] = 0LL;
			}
			for (int i = 0; i <= ub; ++i) {
				for (int j = 0; j <= ub; ++j) {
					c[i] = (c[i] + b[i][j] * a[j] % mod) % mod;
				}
			}
			for (int i = 0; i <= ub; ++i) {
				a[i] = c[i];
			}
		}
		ll c[20][20];
		for (int i = 0; i<= ub; ++i) {
			for (int j = 0; j <= ub; ++j) {
				c[i][j]  = 0LL;
				for (int j2 = 0; j2<= ub; ++j2) {
					c[i][j] = (c[i][j] + b[i][j2] * b[j2][j] % mod) %mod;
				}
			}
		}
		for (int i = 0; i <= ub; ++i) {
			for (int j = 0; j <= ub; ++j) {
				b[i][j] = c[i][j];
			}
		}
		len/=2;
	}
}
int main() {
	cin>>n>>k;
	abc.clear();
	for (int i = 0; i < n; ++i) {
		ll a,b;
		int c;
		scanf("%lld%lld%d", &a, &b, &c);
		abc.push_back(make_pair(make_pair(a,b), c));
	}
	memset(a, 0LL, sizeof(a));
	a[0] = 1LL;
	for (int i = 0; i < n; ++i) {
		ll len = abc[i].first.second-abc[i].first.first;
		if (i == n-1) {
			len = k-abc[i].first.first;
		}
		if (i > 0) {
			for (int j = abc[i].second+1; j <= 15; ++j) {
				a[j] = 0LL;
			}
		}
		calc(len, abc[i].second);
	}
	cout<<a[0]<<endl;
  return 0;
}
