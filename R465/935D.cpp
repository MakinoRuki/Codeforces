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
#define M 30
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m;
int a[N], b[N];
int cnt[N];
ll getpw(ll x, ll y) {
  ll res= 1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  cnt[n+1] = 0;
  for (int i = n; i>=1; --i) {
    cnt[i] = cnt[i+1];
    if (a[i] == 0) cnt[i]++;
    if (b[i] == 0) cnt[i]++;
  }
  ll ans = 0LL;
  ll tmp = 1LL;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0 && b[i] == 0) {
      ll det = ((ll)m*(ll)(m-1)/2)%mod;
      det = tmp*det%mod*getpw(m, cnt[i+1])%mod;
      ans = (ans+det)%mod;
      tmp = tmp * (ll)m % mod;
    } else if (a[i]>0 && b[i]==0) {
      if (a[i]-1>0) {
        ll det = tmp*(ll)(a[i]-1)%mod*getpw(m, cnt[i+1])%mod;
        ans = (ans + det)%mod;
      }
    } else if (a[i] == 0 && b[i] >0) {
      if (m-b[i]>0) {
        ll det = tmp*(ll)(m-b[i])%mod*getpw(m, cnt[i+1])%mod;
        ans=(ans+det) % mod;
      }
    } else {
      if (a[i] == b[i]) continue;
      if (a[i] > b[i]) {
        ans = (ans + tmp * getpw(m, cnt[i+1]) % mod) % mod;
        break;
      }
      break;
    }
  }
  tmp = getpw(m, cnt[1]);
  tmp = getpw(tmp, mod-2);
  ans = ans * tmp % mod;
  cout<<ans<<endl;
  return 0;
}
