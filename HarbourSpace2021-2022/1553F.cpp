#pragma GCC optimize(2)
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
#define M 300000
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
ll bit[2][N];
int a[N];
int lowbit(int x) {
	return x&(-x);
}
void update(int id, int pos, ll val) {
	while(pos < N) {
		bit[id][pos] += val;
		pos += lowbit(pos);
	}
}
ll query(int id, int pos) {
	ll res=0LL;
	while(pos) {
		res += bit[id][pos];
		pos -= lowbit(pos);
	}
	return res;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	ll sum = 0LL;
	ll tot = 0LL;
	for (int i = 1; i <= n; ++i) {
		ll res = (ll)(i-1)*(ll)a[i] - query(1, a[i]);
		res += sum;
		for (int j = 1; j <= M/a[i]; j++) {
			ll det = query(0, min(M, (j+1)*a[i]-1)) - query(0, j*a[i]-1);
			res -= (ll)a[i] * (ll)det * (ll)j;
		}
		tot += res;
		printf("%lld", tot);
		if (i < n) cout<<" ";
		else cout<<endl;
		sum += a[i];
		update(0, a[i], 1);
		for (int j = 1; j <= M/a[i]; ++j) {
			update(1, a[i]*j, (ll)j*(ll)a[i]);
			update(1, min(M+1, a[i]*(j+1)), -(ll)j*(ll)a[i]);
		}
	}
  return 0;
}
