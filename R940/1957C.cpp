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
#include <list>
#define N 1000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    fac[0]=1LL;
    fac2[0] = 1LL;
    for (int i = 1; i <= n; ++i) {
      fac[i] = fac[i-1] * (ll)i % mod;
      fac2[i] = getpw(fac[i], mod-2);
    }
    set<int> rs;
    set<int> cs;
    rs.clear();
    cs.clear();
    for (int i = 1; i <= k; ++i) {
      int r,c;
      scanf("%d%d", &r, &c);
      rs.insert(r);
      cs.insert(c);
    }
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (rs.find(i) == rs.end() && cs.find(i) == cs.end()) {
        cnt++;
      }
    }
   // cout<<"cnt="<<cnt<<endl;
    ll ans=0LL;
    for (int i = 0; i <= cnt; ++i) {
      if ((cnt-i)%2) continue;
      int j = cnt-i;
      ll tmp = fac[cnt] * fac2[i] % mod * fac2[j/2] % mod;
      ans = (ans + tmp) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
