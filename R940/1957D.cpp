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
#include <list>
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int lc[N][32][2];
int rc[N][32][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= 30; ++i) {
      lc[0][i][0] = 0;
      lc[0][i][1] = 0;
      rc[n+1][i][0] = 0;
      rc[n+1][i][1] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= 30; ++j) {
        if ((1<<j)&a[i]) {
          lc[i][j][0] = lc[i-1][j][1];
          lc[i][j][1] = lc[i-1][j][0] + 1;
        } else {
          lc[i][j][0] = lc[i-1][j][0] + 1;
          lc[i][j][1] = lc[i-1][j][1];
        }
      }
    }
    for (int i = n; i >= 1; --i) {
      for (int j = 0; j <= 30; ++j) {
        if ((1<<j)&a[i]) {
          rc[i][j][0] = rc[i+1][j][1];
          rc[i][j][1] = rc[i+1][j][0] + 1;
        } else {
          rc[i][j][0] = rc[i+1][j][0] + 1;
          rc[i][j][1] = rc[i+1][j][1];
        }
      }
    }
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      int bt=0;
      while((1<<bt) <= a[i]) {
        bt++;
      }
      bt--;
      ans += (ll)(lc[i-1][bt][0]+1)*(ll)rc[i+1][bt][1];
      ans += (ll)lc[i-1][bt][1]*(ll)(rc[i+1][bt][0]+1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
