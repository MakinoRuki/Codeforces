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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N], b[N];
int cnt[N];
ll bit[2][N];
ll fac[N], fac2[N];
int lowbit(int x) {
  return x&(-x);
}
ll getpw(ll x, ll y) {
  ll res = 1LL;
  while(y) {
    if (y&1) res=  res*x % mod2;
    x = x*x%mod2;
    y/=2;
  }
  return res;
}
void update(int id, int p, ll v) {
  while(p <= 200000) {
    bit[id][p] = (bit[id][p] + v) % mod2;
    p += lowbit(p);
  }
}
ll query(int id, int p) {
  ll res= 0LL;
  while(p > 0) {
    res = (res + bit[id][p]) % mod2;
    p -= lowbit(p);
  }
  return res;
}
int main() {
  fac[0] = 1LL;
  fac2[0] = 1LL;
  for (int i = 1; i <= 200000; ++i) {
    fac[i] = fac[i-1] * (ll)i % mod2;
    fac2[i] = getpw(fac[i], mod2-2);
  }
  cin>>n>>m;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  memset(bit, 0LL, sizeof(bit));
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
  }
  ll tot = fac[n-1];
  ll tot2 = 1LL;
  for (int i = 1; i <= 200000; ++i) {
    if (cnt[i] > 0) {
      tot2 = tot2 * fac2[cnt[i]] % mod2;
      update(0, i, 1);
      update(1, i, fac[cnt[i]]*fac2[cnt[i]-1]%mod2);
    }
  }
  ll ans = 0LL;
  int i;
  for (i = 1; i <= min(m,n); ++i) {
  //  cout<<"i="<<i<<endl;
    tot = fac[n-i];
    ll det = tot * tot2 % mod2;
    ans = (ans + query(1, b[i]-1) * det % mod2) % mod2;
    if (cnt[b[i]] == 0) {
      break;
    }
    ll add = fac[cnt[b[i]]] * fac2[cnt[b[i]]-1] % mod2;
    update(1, b[i], -add);
    tot2 = tot2 * fac[cnt[b[i]]] % mod2;
    cnt[b[i]]--;
    if (cnt[b[i]] > 0) {
      tot2 = tot2 * fac2[cnt[b[i]]] % mod2;
      update(1, b[i], fac[cnt[b[i]]] * fac2[cnt[b[i]]-1] % mod2);
    } else {
      update(0, b[i], -1);
    }
   // cout<<"i="<<i<<endl;
  }
 // cout<<"ans="<<ans<<endl;
  if (i > min(n,m) && n < m) {
    ans = (ans + 1) % mod2;
  }
  cout<<ans<<endl;
  return 0;
}
