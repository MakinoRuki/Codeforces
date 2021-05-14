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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll getds(ll x) {
	ll tot=0LL;
	while(x) {
		tot += x%10;
		x/=10;
	}
	return tot;
}
ll getgcd(ll x, ll y) {
	return y == 0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll n;
		scanf("%lld", &n);
		for (ll m = n; m < n+3; ++m) {
			if (getgcd(m, getds(m)) > 1) {
				printf("%lld\n", m);
				break;
			}
		}
	}
  return 0;
}
