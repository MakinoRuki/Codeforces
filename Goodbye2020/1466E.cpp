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
int n, t;
ll x[N];
ll cnt[62];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &x[i]);
    }
    ll ans=0LL;
    memset(cnt, 0LL, sizeof(cnt));
    for (int i = 0; i <= 60; ++i) {
      for (int j = 1; j <= n; ++j) {
        if ((1LL<<i) & x[j]) {
          cnt[i]++;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      ll s1=0LL, s2=0LL;
      for (int j = 0; j <= 60; ++j) {
        if ((1LL<<j) & x[i]) {
          s1 = ((1LL<<j)%mod*(ll)cnt[j]%mod+s1)%mod;
          s2 = (s2 + (1LL<<j)%mod*(ll)n%mod)%mod;
        } else {
          s2 = (s2 + (1LL<<j)%mod*(ll)cnt[j]%mod) % mod;
        }
      }
      ans = (ans + s1*s2%mod)%mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
