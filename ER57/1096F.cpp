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
#define M 31
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int p[N];
ll fac[N];
ll fac2[N];
int BIT[N];
ll comb(ll a) {
  return (a * (a-1) / 2LL) % mod2;
}
ll getpw(ll a, ll b) {
  ll res=1LL;
  while(b) {
    if (b&1) res=res*a%mod2;
    a=a*a%mod2;
    b/=2;
  }
  return res;
}
int lowbit(int x) {
  return x&(-x);
}
void update(int pos) {
  while(pos <= n) {
    BIT[pos]++;
    pos += lowbit(pos);
  }
}
int query(int pos) {
  int res=0;
  while(pos > 0) {
    res += BIT[pos];
    pos -= lowbit(pos);
  }
  return res;
}
int main() {
  cin>>n;
  int c1 = 0, c2 = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    if (p[i] > 0) c1++;
    else c2++;
  }
  fac[0] = 1LL;
  for (int i =1 ; i <= n; ++i) {
    fac[i] = fac[i-1] * (ll)i % mod2;
  }
  fac2[0] = 1LL;
  for (int i =1 ; i <= n; ++i) {
    fac2[i] = getpw(fac[i], mod2-2);
  }
  ll ans=0LL;
  if (c1 > 0) {
    memset(BIT, 0, sizeof(BIT));
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      if (p[i] > 0) {
        ss.insert(p[i]);
        ans = (ans + (ll)(query(n) - query(p[i]))) % mod2;
        update(p[i]);
      }
    }
    if (c2 > 0) {
      memset(BIT, 0, sizeof(BIT));
      for (int i = 1; i <= n; ++i) {
        if (ss.find(i) == ss.end()) {
          update(i);
        }
      }
      ll sum = 0LL;
      for (int i = 1; i <= n; ++i) {
        if (p[i] > 0) {
          sum = (sum + (ll)query(p[i]-1)) % mod2;
        }
      }
      for (int i = n; i >= 1; --i) {
        if (p[i] < 0) {
          ans = (ans + sum * fac[c2-1] % mod2 * fac2[c2] % mod2) % mod2;
        } else {
          sum = (sum - (ll)query(p[i]-1) + mod2) % mod2;
          sum = (sum + (ll)(query(n) - query(p[i]))) % mod2;
        }
      }
    }
  }
  if (c2 > 1) {
    ll tmp = comb(c2) * comb(c2) % mod2 * fac[c2-2] % mod2;
    ans = (ans + tmp * fac2[c2] % mod2) % mod2;
  }
  cout<<ans<<endl;
  return 0;
}
