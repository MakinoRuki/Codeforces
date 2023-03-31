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
int a[N];
ll fac[N];
ll fac2[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
int main() {
  cin>>n;
  fac[0] = 1LL;
  for (int i =1 ; i <= n; ++i) {
    fac[i] = fac[i-1] * (ll)i % mod2;
    fac2[i] = getpw(fac[i], mod2-2);
  }
  ll ans = 1LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (i % 3 == 0) {
      vector<int> v = {a[i-2], a[i-1], a[i]};
      sort(v.begin(), v.end());
      if (v[0] == v[1] && v[0] == v[2]) {
        ans = ans * 3LL % mod2;
      } else if (v[0] == v[1] && v[1] != v[2]) {
        ans = ans * 2LL % mod2;
      }
    }
  }
  ll tmp = fac[n/3] * fac2[n/6] % mod2 * fac2[n/3-n/6] % mod2;
  ans = ans * tmp % mod2;
  cout<<ans<<endl;
  return 0;
}
