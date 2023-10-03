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
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
ll f[N][2];
ll g[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      f[i][0] = f[i][1] = (1LL<<61)-1;
      g[i] = (1LL<<61)-1;
    }
    for (int i = n; i >= 1; --i) {
      if (i == n) {
        f[i][1] = 0;
        f[i][0] = 1;
      } else {
        if (a[i] < a[i+1]) {
          f[i][1] = min(f[i][1], f[i+1][1]);
        } else {
          f[i][1] = min(f[i][1], f[i+1][1]+1);
        }
        f[i][0] = min(f[i][0], f[i+1][1]+1);
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        g[i] = 0;
      } else {
        if (a[i] < a[i-1]) {
          g[i] = min(g[i], g[i-1]);
        } else {
          g[i] = min(g[i], g[i-1]+1);
        }
      }
    }
    ll ans = (1LL<<61)-1;
    for (int i = 1; i <= n; ++i) {
      if (i > 1) {
        ans = min(ans, g[i-1]+1 + min(f[i][1], f[i][0]));
      } else {
        ans = min(ans, min(f[i][1], f[i][0]));
      }
    }
    ans = min(ans, g[n]+1);
    printf("%lld\n", ans);
  }
  return 0;
}
