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
#define N 300005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  ll ans = 0LL;
  for (int i = 30; i >= 0; --i) {
    ll n0=0,n1=0;
    ll s0=0,s1=0;
    ll cnt=0;
    for (int j = 1; j <= n; ++j) {
      if ((1<<i) & a[j]) {
        ll n00 = n1, s00 = n1 + s1;
        ll n11 = n0 + 1, s11 = s0 + n0 + 1;
        n0 = n00, s0 = s00;
        n1 = n11, s1 = s11;
        cnt = (cnt + s1) % mod2;
      } else {
        ll n00 = n0 + 1, s00 = s0 + n0 + 1;
        ll n11 = n1, s11 = s1 + n1;
        n0 = n00, s0 = s00;
        n1 = n11, s1 = s11;
        cnt = (cnt + s1) % mod2;
      }
    //  if (i == 1) cout<<"j="<<j<<" "<<n0<<" "<<n1<<" "<<s0<<" "<<s1<<endl;
    }
    cnt = cnt * ((1LL<<i) % mod2) % mod2;
    ans = (ans + cnt) % mod2;
   // cout<<"i="<<i<<" "<<ans<<endl;
  }
  printf("%lld\n", ans);
  return 0;
}
