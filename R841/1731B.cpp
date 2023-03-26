#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 100
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
ll a[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
ll getres(ll x) {
  ll res= (ll)x * (ll)(x+1) % mod * (ll)(2LL*x+1) % mod;
  res=res*getpw(6LL, mod-2) % mod;
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n;
    scanf("%lld", &n);
  //  cout<<getres(n)<<" "<<getres(n-1)<<endl;
    ll ans = 0LL;
    ans = (getres(n) + getres(n-1)) % mod;
    ll dt = (ll)n * (ll)(n-1) %mod * getpw(2LL, mod-2) % mod;
    ans = (ans + dt) % mod;
    ans = ans * 2022LL % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
