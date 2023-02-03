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
#define N 1000005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int d;
string a,b;
ll ax[N], bx[N], cx[N], dx[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
ll calc(int x) {
  ll ans = (cx[x] + dx[x] * ax[x-1] % mod2) %mod2;
  ans = ans * getpw((1-dx[x]*bx[x-1]%mod2+mod2)%mod2, mod2-2) % mod2;
  return ans;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>a>>b;
    ax[1] = 1LL;
    bx[1] = (ll)(n-1) * getpw(n, mod2-2) % mod2;
    cx[n] = 1LL;
    dx[n] = 1LL;
    for (int i = 2; i <= n; ++i) {
      ax[i] = (n + ((ll)i * ax[i-1]) % mod2) % mod2;
      ll tmp = (n - (ll)i * bx[i-1] % mod2 + mod2) % mod2;
      tmp = getpw(tmp, mod2-2);
      ax[i] = ax[i] * tmp % mod2;
      bx[i] = (n-i) % mod2 * tmp % mod2;
    }
    for (int i = n-1; i >= 1; --i) {
      cx[i] = (n + ((ll)(n-i) * cx[i+1] % mod2)) % mod2;
      ll tmp = (n - (ll)(n-i) * dx[i+1] % mod2 + mod2) % mod2;
      tmp = getpw(tmp, mod2-2);
      cx[i] = cx[i] * tmp % mod2;
      dx[i] = (ll)i * tmp % mod2;
    }
    int cnt=0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        cnt++;
      }
    }
    ll ans = 0LL;
    if (cnt == 1) {
      ans = calc(2);
      ans = (ll)(n-1) * ans % mod2 * getpw(n, mod2-2) % mod2;
      ans = (ans + 1) % mod2;
    } else {
      ans = calc(cnt);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
