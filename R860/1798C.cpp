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
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N], b[N];
ll getg(ll x, ll y) {
  return y == 0 ? x : getg(y, x%y);
}
ll getl(ll x, ll y) {
  ll g = getg(x, y);
  return x/g*y;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &a[i], &b[i]);
    }
    int ans=0;
    ll g=0,l=0;
    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        g = (ll)a[i]*(ll)b[i];
        l = b[i];
        ans++;
      } else {
        ll g2 = getg(g, (ll)a[i]*(ll)b[i]);
        ll l2 = getl(l, b[i]);
        if (g2 % l2 != 0) {
          ans++;
          g = (ll)a[i]*(ll)b[i];
          l  = b[i];
        } else {
          g = g2;
          l = l2;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
