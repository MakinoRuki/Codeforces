#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#define N 500005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
ll getgcd(ll x, ll y) {
	return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<ll> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
    	scanf("%lld", &a[i]);
    	ss.insert(a[i]);
    }
    if (n==1) {
    	puts("1");
    	continue;
    }
    sort(a+1, a+n+1);
    ll g = 0;
    for (int i = 1; i < n; ++i) {
    	ll dt = a[n]-a[i];
    	g = getgcd(g, dt);
    }
    ll x = (a[n]-a[1])/g;
    ll ub = a[n];
    if (x > n-1) {
    	for (int i = 1; i < n; ++i) {
    		if (ss.find(a[n] - i*g) == ss.end()) {
    			a[n+1] = a[n]-i*g;
    			break;
    		}
    	}
    } else {
    	a[n+1] = a[n] + g;
    	ub = a[n+1];
    }
    ll ans=0LL;
    for (int i = 1; i <= n+1; ++i) {
    	ans += (ub - a[i])/g;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
