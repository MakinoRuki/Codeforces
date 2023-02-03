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
int a[N];
vector<int> es[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      es[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      if (x > y) swap(x, y);
      es[x].push_back(y);
    }
    ll ans = 0LL;
    int mn = inf;
    int xy = n+1;
    for (int i = n; i >= 1; --i) {
      for (int j = 0; j < es[i].size(); ++j) {
        xy = min(xy, es[i][j]);
      }
      ans += (ll)(xy-i);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
