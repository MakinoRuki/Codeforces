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
#define M 21
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, q;
bool vis[N][N];
ll dp1[N][N][2];
ll dp2[N][N][2];
ll getres(int x, int y) {
  ll tot = 0LL;
  if (x-1>=1 && !vis[x-1][y]) {
    ll res=dp1[x-1][y][1]+1;
    ll res2=1LL;
    if (y+1<=m && !vis[x][y+1]) res2 += dp2[x][y+1][0]+1;
    tot += res * res2;
  }
  if (y-1>=1 && !vis[x][y-1]) {
    ll res=dp1[x][y-1][0]+1;
    ll res2=1LL;
    if (x+1<=n && !vis[x+1][y]) res2 += dp2[x+1][y][1]+1;
    tot += res*res2;
  }
  tot++;
  if (y+1<=m && !vis[x][y+1]) tot += dp2[x][y+1][0]+1;
  if (x+1<=n && !vis[x+1][y]) tot += dp2[x+1][y][1]+1;
  return tot;
}
void update(int x, int y, int dt) {
  for (int i = 0; i < 2; ++i) {
    ll v = 1LL;
    if (i == 0) {
      if (y+1<=m && !vis[x][y+1]) v += dp2[x][y+1][0]+1;
    } else {
      if (x+1<=n && !vis[x+1][y]) v += dp2[x+1][y][1]+1;
    }
    int x2=x, y2=y;
    int st=i;
    while(true) {
      if (!st) {
        x2--;
        if (x2>=1 && !vis[x2][y2]) {
          dp2[x2][y2][st] += dt*v;
        } else {
          break;
        }
      } else {
        y2--;
        if (y2 >= 1 && !vis[x2][y2]) {
          dp2[x2][y2][st] += dt*v;
        } else {
          break;
        }
      }
      st = !st;
    }
  }
  for (int i = 0; i < 2; ++i) {
    ll v = 1LL;
    if (i == 0) {
      if (y-1>=1 && !vis[x][y-1]) v += dp1[x][y-1][0]+1;
    } else {
      if (x-1>=1 && !vis[x-1][y]) v += dp1[x-1][y][1]+1;
    }
    int x2=x, y2=y;
    int st=i;
    while(true) {
      if (!st) {
        x2++;
        if (x2 <= n && !vis[x2][y2]) {
          dp1[x2][y2][st] += dt*v;
        } else {
          break;
        }
      } else {
        y2++;
        if (y2 <= m && !vis[x2][y2]) dp1[x2][y2][st] += dt*v;
        else break;
      }
      st = !st;
    }
  }
  if (dt > 0) {
    if (x-1>=1 && !vis[x-1][y]) dp1[x][y][0] += dp1[x-1][y][1]+1;
    if (y-1>=1 && !vis[x][y-1]) dp1[x][y][1] += dp1[x][y-1][0]+1;
    if (x+1<=n && !vis[x+1][y]) dp2[x][y][0] += dp2[x+1][y][1]+1;
    if (y+1<=m && !vis[x][y+1]) dp2[x][y][1] += dp2[x][y+1][0]+1;
  } else {
    dp1[x][y][0] = 0;
    dp1[x][y][1]=0;
    dp2[x][y][0] = 0;
    dp2[x][y][1] = 0;
  }
}
int main() {
  cin>>n>>m>>q;
  memset(vis, false, sizeof(vis));
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));
  ll ans=0LL;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i-1>=1) dp1[i][j][0] += dp1[i-1][j][1]+1;
      if (j-1>=1) dp1[i][j][1] += dp1[i][j-1][0]+1;
      ans += dp1[i][j][0]+dp1[i][j][1]+1;
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = m; j >= 1; --j) {
      if (i+1 <=n) dp2[i][j][0] += dp2[i+1][j][1]+1;
      if (j+1<=m) dp2[i][j][1] += dp2[i][j+1][0]+1;
    }
  }
  while(q-->0) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (vis[x][y]) {
      ans += getres(x, y);
      update(x, y, 1);
    } else {
      ans -= getres(x, y);
      update(x, y, -1);
    }
    vis[x][y] = !vis[x][y];
    printf("%lld\n", ans);
  }
  return 0;
}
