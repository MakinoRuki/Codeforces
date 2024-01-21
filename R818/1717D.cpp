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
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll fac[N];
ll fac2[N];
ll getpw(ll x, ll y) {
    ll res=1LL;
    while(y) {
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return res;
}
ll comb(ll x, ll y) {
    ll res=fac[x]*fac2[y]%mod*fac2[x-y]%mod;
    return res;
}
int main() {
  ll n,k;
  cin>>n>>k;
  fac[0]=1LL;
  fac2[0]=1LL;
  for (int i = 1; i <= n; ++i) {
    fac[i] = fac[i-1] * (ll)i % mod;
    fac2[i] = getpw(fac[i], mod-2);
  }
  ll tot = 0LL;
  if (k >= n) {
    tot = 1LL;
    for (int i = 1; i <= n; ++i) {
        tot= tot*2LL % mod;
    }
  } else {
    for (int i = 0; i <= k; ++i) {
        tot = (tot +comb(n, i)) % mod;
    }
  }
  cout<<tot<<endl;
  return 0;
}
